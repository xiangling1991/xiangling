/*Explicitly disallow the use of compiler-generated functions you do not want*/
/*若不想使用编译器自动生成的函数，就应该明确拒绝*/

/*当我们遇到某个设计的类存在无意义的复制时，就需要明确的去
拒绝由编译器自动生成的函数。比如地产中介商卖房子，如果系统
使用一个class来描述代售房屋：*/
	class HomeForSale{...};

//	此时的HomeForSale应该是独一无二的，无论是拷贝还是赋值拷贝
//	都是不合理的
	HomeForSale h1;
	HomeForSale h2;
	HomeForSale h3(h1);		//此时不应该通过编译
	h1 = h2;				//同上


/*此时的你应该痛恨编译器自作主张，为你添加了一个operator=和assign的操作，
由此，为了阻止编译器的这种野蛮行为，你需要自己定义operator=和assign的操作，
并且是私有的,且无需去实现它：*/
	class HomeForSale {
	public:
		...
	private:
		HomeForSale(const HomeForSale&);
		HomeForSale& operator=(const HomeForSale&);
	};

/*但是，一般情况下，问题是可以被解决的，但是如果你添加了一个friend函数，此时
这个函数可以使用这两个函数，这会造成在连接期出现问题，为了将连接期的问题提前
到编译器，另一个更好的方式就是定义一个禁止被拷贝的基类，用HomeForSale来私有
继承该类：*/
	class NonCopyAble {
	public:
		NonCopyAble(){}
		~NonCopyAble(){}
	private:
		NonCopyAble(const NonCopyAble&);
		NonCopyAble& operator=(const NonCopyAble&);
	};

	class HomeForSale : private NonCopyAble {
	public:
		...
	};
//此时，HomeForSale类将无需再添加拷贝和复制的方法。

//此种方式在boost库中是noncopyable;继承该类，也实现了以上的作用。