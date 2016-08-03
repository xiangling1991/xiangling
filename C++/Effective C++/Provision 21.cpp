/*Don't try to return a reference when you must return an object.*/
/*必须返回对象时，别妄想返回其Reference*/

//eg：
	class Rational {
	public:
		Rational(int numerator = 0,
			int denominator = 1);
		...
	private:
		int n, d;
		friend const Rational operator*(const Rational& lhs, const Rational& rhs);
	};

//此版本的operator*以by value方式返回其技术结果，如果你完全不担心该对象的构造和析构成本，你其实是明显逃避了
//你的专业责任。若非必要，没有人会想要为这样的对象付出太多的代价，问题时需要付出任何代价吗？
//如果改为传递Reference，就不需要付出代价，但是，所谓的Reference只是个名称，代表某个既有对象，
//任何时候看到一个Reference声明式，都应该立刻问自己，它的另一个名称是什么》如果此处使用Reference，
//则一定存在一个既有的Rational对象，内含两个Rational对象的乘积。但是这并不是我们所期望的。

//eg:
	Rational a(1, 2);
	Rational b(3, 5);
	Rational c = a * b;

//如果"原本就存在一个其值为3/10的Rational对象"并不合理。
//假如我们返回一个对象的引用，以下三中方式为例，进行评析：
//a:
	const Rational& operator*(const Rational& lhs, const Rational& rhs) {
		Rational result(lhs.n * rhs.n, lhs.d * rhs.d);
		return result;
	}

	//此时返回的是一个临时变量的引用，在函数退出时，result对象就已经被析构了，导致返回的引用
	//将指向一个未知的，未定义的行为。
//b:
	const Rational& operator*(const Rational& lhs, const Rational& rhs) {
		Rational* result = new Rational(lhs.n * rhs.n, lhs.d * rhs.d);
		return *result;
	}
	//此时在堆上分配了空间，虽然以牺牲"构造函数调用"为代价分配了内存以完成初始化动作，但是分配的
	//空间又有谁来delete呢?
	//如果Rational r = a * b * c,此时需要多次delete，而在调用后并不能从返回的Reference中找到隐藏的
	//指针，因此无法进行delete动作，造成内存泄露。

//c:
	const Rational& operator*(const Rational& lhs, const Rational& rhs) {
		static Rational result;
		result = Rational(lhs.n * rhs.n, lhs.d * rhs.d);

		return result;
	}
	//此时发生的问题，一个是多线程安全问题，深层的瑕疵如下：

	bool operator==(const Rational& lhs, const Rational& rhs);

	Rational a, b, c, d;
	...
	if((a * b) == (c * d)) {
		...
	} else {

	}

	//结果表达式(a * b) == (c * d) 总是被核算为true，不论a, b, c, d为何值。

	//上面的代码重写如下：
	if(operator==(operator*(a, b), operator*(c, d)))

	//在operator==被调用前，已有两个operator*调用式起作用，每一个都返回Reference
	//指向operator*内部定义个static Rational对象，因此operator==被要求将"operator*"
	//内的static Rational对象值拿来和"operator*内的static Rational对象值"比较，如
	//果不相等，那才奇怪。


//一个"必须返回新对象"的函数的正确写法是：
inline const Rational operator*(const Rational& lhs, const Rational& rhs) 
{
	return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
}


//Must Remember:
//绝不要返回pointer或Reference指向一个local stack对象，或返回Reference指向一个heap-allocated
//对象，或返回pointer或Reference指向一个local static对象而有可能同时需要多个这样的对象。