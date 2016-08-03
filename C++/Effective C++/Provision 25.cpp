//考虑写出一个不抛异常的swap函数(Consider support for a non-throwing swap)

//缺省的swap由标准程序库提供的算法完成：

namespace std {
    template<typename T>
    void swap(T& a, T& b)
    {
        T temp(a);
        a = b;
        b = temp;
    }
}

//只要类型T支持copying(通过copy构造函数和copy assignment操作符完成)
//但在交换"以指针指向一个对象，内含真正数据"的类型，这种设计常见形式是所谓"pimpl(pointer to implementation)手法"，如下：
class WidgetImpl {
public:
    ...
private:
    int a,b,c;
    std::vector<double> v;
    ...  
};

class Widget {
public:
    Widget(const Widget& rhs);
    Widget& operator=(const Widget& rhs)
    {
        ...
        *pImpl = *(rhs.pImpl);
        ...
    }    
    ...
private:
    WidgetImpl* pImpl;
};

//置换两个Widget对象值，唯一需要做的就是置换pImpl指针，但缺省的swap算法并不知道，它不止复制了三个Widget，还复制了三个WidgetImpl对象，
//非常缺乏效率。
//此时，我们希望告诉std::swap：当Widget被置换时真正该做的是置换其内部的pImpl指针。如下（但无法通过编译）
namespace std {
    template<>
    void swap<Widget>(Widget& a,            //这是std::swap针对“T是Widget的特化版本”。
                      Widget& b)            //目前无法通过编译，
    {
        swap(a.pImpl, b.pImpl);             //置换Widget时只要置换它们的pImpl指针。
    }
}
//这个函数一开始的"template<>"表示它是std::swap的一个全特化(total template specialization)版本，函数名称之后
//的"<Widget>"表示这一特化版本针对"T是Widget"而设计。
//未能通过编译是由于pImpl是private的，我们可以将这个特化版本声明为friend。
//但此时，我们和以往不一样:我们令Widget声明一个名为swap的public成员函数做真正的置换工作，然后将std::swap特化，令它调用该成员函数：
class Widget {                                //增加了swap函数
public:
    ...
    void swap(Widget& other)
    {
        using std::swap;                         
        swap(pImpl, other.pImpl);           //若要置换Widget就置换其pImpl指针。
    }
    ...
};
namespace std {
    template<>
    void swap<Widget> (Widget& a,
                       Widget& b)
    {
        a.swap(b);                         //若要置换Widget，调用其swap成员函数
    }
}

//这种做法不只能够通过编译，还与STL容器有一致性，因为所有STL容器也都是提供有public swap成员函数和std::swap特化版本

//如果假设Widget和WidgetImpl都是class template而非class，如下：
template<typename T>
class WidgetImpl {...};

template<typename T>
class Widget {...};


//在Widget内(以及WidgetImpl内，如果需要的话)放个swap成员函数就像以往一样简单，当我们却在特化std::swap时遇上乱流，如下：
namespace std {
    template<typename T>
    void swap< Widget<T> >(Widget<T>& a,        //错误，不合法
                           Widget<T>& b)
    {
        a.swap(b);
    }
}

//我们企图偏特化(partially specialize)一个function template(std::swap)，但c++只允许对class template偏特化，
//在function template身上偏特化是行不通的，因此无法通过编译。
//如果打算偏特化一个function template时，惯常做法是简单地为它添加一个重载版本，如下：
namespace std {
    template<typename T>        //std::swap的一个重载版本
    void swap(Widget<T>& a,     //（注意"swap"之后没有"<...>"）
              Widget<T>& b)     //其实不合法
    {
        a.swap(b);
    }
}
//一般而言，重载function template没有问题，但std是个特殊命名空间，其管理规则也比较特殊，客户可以全特化std内的
//template，但不可以添加新的template(或class或function或其他任何东西)到std里头。

//为了能够让其他人调用swap时调用我们提供的较高效的template特定版本，我们还是声明一个non-member swap让它调用memeber
//swap，但不再将那个non-member swap声明为std::swap的特化版本或重载版本。假设Widget的所有相关机能都被置于命名空间
//WidgetStuff内：
namespace WidgetStuff {
    ...                                     //模板化的Widgeti等等
    template<typename T>                    //同前，内含swap成员函数
    class Widget{...};
    ...
    template<typename T>                    //non-member swap函数；
    void swap(Widget<T>& a,                 //这里并不属于std命名空间
              Widget<T>& b)
    {
        a.swap(b);
    }
}

//这个做法对class和class template都行得通，所以似乎我们应该在任何时候都使用它，不幸的的是有一个你有使你应该为
//class特化std::swap，所以如果你想让你的"class专属版"swap 在尽可能多的语境下被调用，你需同时在该class所在命名
//空间内写一个non-member版本以及一个std::swap特化版本。

//总结：
//1. 如果swap的缺省实现码对你的class或class template提供可接受的效率，你不需要额外做任何事，任何尝试置换那种对象的
//人都会取得缺省版本，而那将有良好的运作。
//2. 如果swap缺省实现版的效率不足(那几乎总是意味着你的class或template使用了某种pimpl手法)，试着做以下事情：
//-----(1):提供一个public swap成员函数，让它高效地置换你的类型的两个对象值，且不可抛出异常。
//-----(2):在你的class或template所在的命名空间内提供一个non-member swap，并令它调用上述swap成员函数
//-----(3):如果你正编写一个class(而非class template),为你的class特化std::swap。并令它调用你的swap成员函数。
//-----最后，如果你调用swap，请确定包含一个using声明式，以便让std::swap在你的函数类曝光可见，然后不加任何namespace
//------修饰符，赤裸裸第调用swap。


//劝告：
//成员版swap绝不可抛出异常，因为swap的一个最好的应用是帮助class(和class template)提供一个public
//强烈的异常安全性(exception-safety)保障。