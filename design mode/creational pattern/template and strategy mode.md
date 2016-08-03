# Template mode

>Template模式是采用继承的方式实现这一点：将逻辑框架放在抽象基类中，并定义好细节的接口，子类中实现细节。
Template模式实际上就是利用面向对象中多态的概念实现算法实现细节和高层接口的松耦合。可以看到Template模
式采取的是继承方式实现的，由于继承是一种强约束性的条件，因此也给Template模式带来一些不方便的地方。

代码实现如下：
```
class AbstractClass {
public:
    virtual ~AbstractClass(){}
    void TemplateMethod();
protected:
    virtual void PrimitiveOperation1() = 0;
    virtual void PrimitiveOperation2() = 0;
    AbstractClass(){}
};

class ConcreteClass1 : public AbstractClass {
public:
    ConcreteClass1(){}
    ~ConcreteClass1(){}
protected:
    void PrimitiveOperation1();
    void PrimitiveOperation2();
};

class ConcreteClass2 : public AbstractClass {
public:
    ConcreteClass2(){}
    ~ConcreteClass2(){}
protected:
    void PrimitiveOperation1();
    void PrimitiveOperation2();
};

void AbstractClass::TemplateMethod() {
    PrimitiveOperation1();
    PrimitiveOperation2();
}

void ConcreteClass1::PrimitiveOperation1() {
    cout <<"ConcreteClass1...PrimitiveOperation1"<<endl;
}

void ConcreteClass1::PrimitiveOperation2() {
    cout <<"ConcreteClass1...PrimitiveOperation2"<<endl;
}

void ConcreteClass2::PrimitiveOperation1() {
    cout <<"ConcreteClass2...PrimitiveOperation1"<<endl;
}

void ConcreteClass2::PrimitiveOperation2() {
    cout <<"ConcreteClass2...PrimitiveOperation2"<<endl;
}

int main() {
    AbstractClass* p1 = new ConcreteClass1();
    AbstractClass* p2 = new ConcreteClass2();
    p1->TemplateMethod();
    p2->TemplateMethod();
    
    return 0;
}
```

>Template模式获得一种反向控制结构效果，这也是面向对象系统分析和设计的原则之一：
DIP(依赖倒置:Dependency Inversion Principles)。其含义就是父类调用子类的操作
(高层模块调用低层模块的操作)，低层模块实现高层模块声明的接口。这样控制权在父类
(高层模块)，低层模块反而要依赖高层模块。

>所引发的问题：Template中利用的是继承来实现的，所以类之间就产生了强制性约束，
降低了代码的可重用性。


#Strategy mode

>Strategy 模式和 Template 模式要解决的问题是相同 （类似）的， 都是为了给业务逻辑 （算
法） 具体实现和抽象接口之间的解耦。 Strategy 模式将逻辑（算法） 封装到一个类（ Context）
里面， 通过组合的方式将具体算法的实现在组合对象中实现， 再通过委托的方式将抽象接口
的实现委托给组合对象实现。 State 模式也有类似的功能， 他们之间的区别将在讨论中给出。

实现如下：

```
class Strategy {
public:
    Strategy(){};
    virtual ~Strategy() {}
    virtual void AlgrithmInterface() = 0;
};

class ConcreteStrategyA : public Strategy {
public:
    ConcreteStrategyA(){}
    virtual ~ConcreteStrategyA() {}
    void AlgrithmInterface();
};

class ConcreteStrategyB : public Strategy {
public:
    ConcreteStrategyB(){}
    virtual ~ConcreteStrategyB() {}
    void AlgrithmInterface();
};

class Context {
public:
    Context(Strategy* stg)
        : _stg(stg)
        {}
    ~Context() {
        if(_stg)
            delete _stg;
    }
    
    void　DoAction() {
        _stg->AlgrithmInterface();
    }
private:
    Stategy* _stg;
};

int main() {
    Strategy* ps;
    ps = new ConcreteStrategyA();
    Context* pc = new Context(ps);
    
    pc->DoAction();
    if(pc)
        delete pc;
        
    return 0;
}

```

>Strategy mode 和Template模式实际是实现一个抽象接口的两种方式：继承与组合的区别。
