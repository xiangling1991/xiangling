/*Never call virtual functions during construction or destruction.*/
/*绝不在构造和析构过程中调用virtual 函数*/

/*重点：你不该在构造函数和析构函数期间调用virtual函数，因为这样的调用不会带来
你预想的结果。假设有个class继承体系，用塑模股市交易如何买进、卖出订单等等。
这样的交易一定要经过审计，所有每当创建一个交易对象，在审计日志中也需要创建
一笔适当记录：*/
	class Transaction {			//所有交易的基类
	public:
		Transaction();
		virtual void logTransaction() const = 0;//做出一份类型不同而不同
		...										//的日志记录	
	};

	Transaction::Transaction() {
		...
		logTransaction();    //构造函数中的最后动作记录这笔交易
	}

	class BuyTransaction : public Transaction {  //derived class 
	public:
		virtual void logTransaction() const;	//志记此型交易
		...
	};

	class SellTransaction : public Transaction { //derived class 
		virtual void logTransaction() const;	 //志记此型交易
		...
	};
	//现在执行以下语句会发生什么：
	BuyTransaction b;

/*当执行此语句时，基类Transaction的构造函数必定先于BuyTransaction执行，
最后的logTransaction将会引发惊奇，此时调用的logTransaction是Transaction
中的，而不是BuyTransaction中的，在基类构造期间，virtual函数决不会下降到
derived classes阶层，换句话说，在构造期间，virtual函数并不是virtual函数。

更退一步，加入在基类构造过程中，virtual下降到了derived类中，virtual函数
是derived中的，此时的derived class的函数几乎必然取用local成员变量，而那些
成员比按钮尚未初始化。这将会引起不明确行为和彻夜调试大会串的直达车车票。

再者说，对象在derived class的构造函数执行之前不会成为一个derived class。

同理可用于析构函数。

因此一个优秀的做法是将共同的初始化代码放进一个初始化函数init内：*/

class Transaction {
	public Transaction() {init();}
	virtual void logTransaction() const = 0;
	...
private:
	void init() {
		...
		logTransaction();
	}
};


/*其它解决方案：可将class Transaction内将logTransaction函数改为
non-virtual，然后要求derived class 构造函数传递必要信息给Transaction
构造函数：*/

class Transaction {
public:
	explicit Transaction(const std::string& logInfo);
	void logTransaction(const std::string& logInfo) const;
	...
};

Transaction::Transaction(const std::string& logInfo) {
	...
	logTransaction(logInfo);
}

class BuyTransaction : public Transaction {
public:
	BuyTransaction(parameters)
	: Transaction(createLogString(parameters))
	{...}

private:
	static std::string createLogString(parameters);
	...
};


//////记住:在构造和析构期间不要调用virtual函数，因为这类调用从不下降至
/////derived class






