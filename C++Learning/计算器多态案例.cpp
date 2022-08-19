#include <iostream>
#include <string>
using namespace std;

//在真实的开发中，提倡开闭原则，对拓展进行开放，对修改进行关闭
class calculator
{
	void friend  test01();
public:
	calculator();
	~calculator();
	int getResult(string oper) {
		if (oper == "+")
		{return m_Num1+m_Num2;
		}
		else if (oper == "-")
		{
			return m_Num1 - m_Num2;
		}
		else if (oper == "*")
		{
			return m_Num1 * m_Num2;
		}
	}

private:
	int m_Num1,m_Num2;
};

calculator::calculator()
{
}

calculator::~calculator()
{
}

void test01() {
	calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;
	cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+" ) << endl;
	cout << c.m_Num1 << "-" << c.m_Num2 << "=" << c.getResult("-") << endl;
	cout << c.m_Num1 << "*" << c.m_Num2 << "=" << c.getResult("*") << endl;
}

//利用多态实现计算器
//实现计算器抽象类
class AbstractCalculator
{public:
	virtual int getResult() {
		return 0;
	}

	int m_Num1;
	int m_Num2;

};
//加法计算器类
class AddCalculator :public AbstractCalculator
{public:
	virtual int getResult() {
		
			return m_Num1 + m_Num2;	
	}
};

//减法计算器类
class SubCalculator :public AbstractCalculator
{
public:
	virtual int getResult() {

		return m_Num1 - m_Num2;
	}
};
//乘法计算器类
class MulCalculator :public AbstractCalculator
{
public:
	virtual int getResult() {

		return m_Num1 * m_Num2;
	}
};
void test02() {					//父类引用或指向子类可以发生多态
	AbstractCalculator* abc = new AddCalculator;//new一个add calculator 相当于创造一个add calculator的对象
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
	//用完后记得销毁
	delete abc;
	abc = new SubCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;
	abc = new MulCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;

}


int main() {


	test02();



	system("pause");
	return 0;

}