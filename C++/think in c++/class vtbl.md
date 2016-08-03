# 编译器实现多态的方式
[![Google](http://pic.nipic.com/2007-11-09/200711912453162_2.jpg)](http://www.baidu.com/)
实现
----

>当创建一个含有虚函数的父类的对象时，编译器在对象构造时将虚表指针指向父类的虚函数；同样当创建子类对象时，
编译器在构造函数里将虚表指针(子类只有一个虚表指针，它来自父类)指向子类的虚表(这个虚表里面的虚函数入口
地址是子类的)。

所以，如果调用
```
    Base *p = new Derived();
```
>生成的是子类的对象，在构造时，子类对象的虚指针指向的是子类的虚表，接着由Derived\* 到Base\*的转换并没
有改变虚表指针，所以这时p->VirtualFunction,实际上是p->vfptr->VirtualFunction,他在构造时已经指向了
子类的VirtualFunction，所以调用的是子类的虚函数，就是多态了。

总结：
-------
>1. 每个类都有虚指针和虚表
2. 如果不是虚继承，那么子类将父类的虚指针继承下来，并指向自身的虚表(发生在对象构造时).有多个虚函数，虚表
里的项就会有多少。多重继承时，可能存在多个基类虚表与虚指针。
3. 如果是虚继承，那么子类会有两份虚指针，一份指向自己的虚表，另一份指向虚基表，多重继承时虚基表与虚基表指针
有且只有一份。


##多重继承+虚拟继承

```
class X{};
class Y : public virtual X{};
class Z : public virtual X{};
class M : public Y, public Z {};
```

在以上的代码中，分别计算各个类所占字节数如下：
```
    sizeof(X) = 1; sizeof(Y) = 8; sizeof(Z) = 8; sizeof(M) = 16;
```
Y 和 Z的大小和机器以及编译器有关，其影响因素如下：
1. 语言本身所造成的额外负担(overhead)
2. 编译器对于特殊情况所提供的优化处理
3. Alignment的限制



#多重继承+虚拟继承

```
#include <iostream>

class Point2d {
public:
	Point2d(float x, float y):_x(x),_y(y){}
protected:
	float _x;
	float _y;
};

class Vertex : public virtual Point2d {
public:
	Vertex(float x, float y);
protected:
	Vertex *next;
};

class Point3d : public virtual Point2d {
public:
	Point3d(float x, float y, float z) 
		: Point2d(x, y) { _z = z;}
protected:
	float _z;
};

class Vertex3d : public Vertex, public Point3d {
public:
	Vertex3d(float, float, float);	
protected:
	float mumble;
};

Vertex::Vertex(float x, float y)
		: Point2d(x, y),
		next(NULL)
{
	
}

Vertex3d::Vertex3d(float x, float y, float z)
		: Point2d(x, y),                      //此处需谨慎，如果不存在虚继承，则此处不需要添加Point2d的初始化
		Vertex(x, y),
		Point3d(x, y, z)
{

}

int main()
{
	

	return 0;
}
```

>由上可知，在带有虚继承的构造函数中，c++的规则是：最底层的子类要负责完成该基类部分成员的构造。此时，我们可以
显示调用虚基类的构造函数完成初始化。如果不显示调用虚基类的构造函数，则编译器调用虚基类的缺省构造函数。如果
不显示调用虚基类的构造函数，而虚基类没有定义缺省构造函数，则会出现编译错误。原因是：如果不这样做，则虚基类部
分会在存在的多个继承链条上被多次初始化。

>如果Point3d有如下的操作符：
```
void Point3d::operator+=(const Point3d& rhs) {
    _x += rhs._x;
    _y += rhs._y;
    _z += rhs._z;
}
```
>在cfront策略下，这个运算符被内部转换为：
```
>//虚拟c++码
__vbcPoint2d->_x += rhs.__vbcPoint2d->_x;  //vbc 意为：virtual base class
__vbcPoint2d->_y += rhs.__vbcPoint2d->_y;  //
_z += rhs._z;
```
而一个derived class 和一个base class的实例之间的转换：
```
Point3d* pv3d;
Point2d *p2d = pv3d; 
//在cfront实现模型之下，会变成：
Point2d* p2d = pv3d ? pv2d->__vbcPoint2d : 0;
```
此种实现的缺点有：
 - 每一个对象必须对其每一个virtual base class背负一个额外的指针，
然而理想上我们却希望class object有固定的负担，不因为其virtual
base classes的数目而有所变化。
 - 由于虚拟继承串链的加长，导致间接存取层次的增加，如果我们有三层
虚拟衍化，就需要三次间接存取，而理想上，我们有固定的存取时间，而
不应该随着深度的增加而改变。
解决方案：
 - 解决第一种问题的两种方法：
   - Microsoft编译器引入所谓的virtual base class table。每一个class
   object 如果有一个或多个virtual base classes，就会由编译器安插一个
   指针，指向virtual base class table，至于真正的virtual base class
   指针，当然是被放在该表格中。
   - 在virtual function table中放置virtual base class的offset
<div class="footer">
    &copy;2016.02.02 Titan Corporation
</div>