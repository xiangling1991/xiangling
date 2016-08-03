##使用地址来获取类中的数据，因此在类的布局与安全性息息相关，如果知道了类中数据的布局，则可以通过非法的手段来获取信息，如下：

```
#include <iostream>

class A {
public:
	A();
private:
	int a;
	//	static int b;
	int m;
	char k;
	double n;
};

A::A()
{
	a = 4;
	m = 6;
	k = 'b';
	n = 3.2;
	std::cout << "this:" << this << std::endl;
	std::cout << "a:" << &a << std::endl;
	std::cout << "m:" << &m << std::endl;
	std::cout << "k:" << (int*)(&k) << std::endl;
	std::cout << "n:" << &n << std::endl;

}
//int A::b = 4;

int main()
{
	std::cout << "size:" << sizeof(A) << std::endl;
	A a;
	std::cout << "k:" << (char)*(int*)((int*)(&a) + 2) << std::endl;
	std::cout << "n:" << (double)*(double*)((int*)(&a) + 4) << std::endl;
}
```


由上同理，也可以通过创建函数指针来直接获取类成员函数的值。
```
#include <iostream>

using namespace std;

class A				//类A有两个虚函数和一个成员变量，由于内存对齐，类A的大小为16(虚表大小8，变量对齐到8)
{
	virtual int get(int);
	virtual int get();
	char a = 'A';
};

class B : A					//单一继承的情况
{
	virtual int get1();
};

class C
{
	char c = 'C';
	virtual int get();
};

class D : A, C				//多重继承的情况
{
	char d = 'D';
	virtual int get2();
};

class E : public A			//单一继承并发生override的情况
{
	int get();
};

int A::get(int)
{
	cout << "A::get(int)" << endl;
	return 0;
}

int A::get()
{
	cout << "A::get()" << endl;
	return 0;
}

int B::get1()
{
	cout << "B::get1()" << endl;
	return 0;
}

int C::get()
{
	cout << "C::get()" << endl;
	return 0;
}

int D::get2()
{
	cout << "D::get2()" << endl;
	return 0;
}

int E::get()
{
	cout << "E::get()" << endl;
	return 0;
}

int main(void)
{
	A* a = new E;
	B b;
	D d;

	//在64bit的Linux中，普通指针的大小为8B，故需要转换为一个占有8个字节的类型来保存内容，否则可能会发生截断
	cout << "调用类A的get(int)函数 ";
	((int(*)())*(long*)*(long*)&d)();
	cout << "调用类A的get()函数 ";
	((int(*)())*((long*)*(long*)&d + 1))();
	cout << "调用类D的get2()函数 ";
	((int(*)())*((long*)*(long*)&d + 2))();
	cout << "类A的变量a的值 " << (char)*((long*)&d + 1) << endl;
	cout << "类C的变量a的值 " << *(char*)((long*)&d + 3) << endl;
	cout << "类D的变量a的值 " << *((char*)((long*)&d + 3) + 1) << endl;		//类D继承于类A和C，D的虚函数添加到了类A虚表的末尾，因而类D中的变量a处于类C中的变量a的下一个位置
	cout << "调用类B的get1()函数 ";
	((int(*)())*((long*)*(long*)&b + 2))();
	cout << "调用类C的get()函数 ";
	((int(*)())*(long*)*((long*)&d + 2))();
	cout << "调用类A的get(int)函数 ";
	((int(*)())*((long*)*(long*)&*a))();
	cout << "向上转型使用A类指针调用类E的get()函数 ";
	((int(*)())*((long*)*(long*)&*a + 1))();
	return 0;
}

```