#include <iostream>
#include <string>
using namespace std;

//在父类中虚函数一般是没用的，可以定义为纯虚函数

class Base	//有纯虚函数是抽象类，是不能实例化对象的
			//且子类想实例化对象，需要重新纯虚函数.否则也属于抽象类
{public:
				//纯虚函数在虚函数里使其=0；
	virtual void func()=0;



};
//饮品的抽象类

class AbstractDrinking
{
public:
	AbstractDrinking();
	~AbstractDrinking();
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加入辅料
	virtual void PutSomeThing() = 0;
	//制作饮品
	void makeDring() 
	{
		Boil();
		Brew();
		PourInCup();
		PutSomeThing();
	}

private:

};

AbstractDrinking::AbstractDrinking()
{
}

AbstractDrinking::~AbstractDrinking()
{
}

class Coffee:public AbstractDrinking
{
public:
	virtual void Boil() 
	{
		cout << "煮农夫山泉" << endl;
	};
	//冲泡
	virtual void Brew() {
		cout << "冲泡咖啡" << endl;
	};
	//倒入杯中
	virtual void PourInCup() {
		cout << "倒入杯中" << endl;
	};
	//加入辅料
	virtual void PutSomeThing() {
		cout << "加入糖和牛奶" << endl;
	};


private:

};

class Tea :public AbstractDrinking
{
public:
	virtual void Boil()
	{
		cout << "煮矿泉水" << endl;
	};
	//冲泡
	virtual void Brew() {
		cout << "冲泡茶叶" << endl;
	};
	//倒入杯中
	virtual void PourInCup() {
		cout << "倒入杯中" << endl;
	};
	//加入辅料
	virtual void PutSomeThing() {
		cout << "加入柠檬" << endl;
	};


private:

};

void doWork(AbstractDrinking *abs)   //形参为父类，接收的实参为子类，发生多态    AbstractDrinking *abs=new Coffee
{	
	abs->makeDring();//但是在这里传入的是匿名对象，运行完直接释放          多态：  一个接口，有多种形态
	delete abs;//释放，防止内存泄露
	abs = NULL;

}

void test02(){
	doWork(new Coffee);

	doWork(new Tea);
}


class Son :public Base 
{public:
	virtual void func() {
	
		cout << "func函数的调用" << endl;
	
	};



};

void test01(){
	Base* so = new Son;//多态产生的条件
	so->func();

}


int main() {

	test02();








	system("pause");
	return 0;

}