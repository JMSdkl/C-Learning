#include <iostream>
#include <string>
using namespace std;

//����ʵ�Ŀ����У��ᳫ����ԭ�򣬶���չ���п��ţ����޸Ľ��йر�
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

//���ö�̬ʵ�ּ�����
//ʵ�ּ�����������
class AbstractCalculator
{public:
	virtual int getResult() {
		return 0;
	}

	int m_Num1;
	int m_Num2;

};
//�ӷ���������
class AddCalculator :public AbstractCalculator
{public:
	virtual int getResult() {
		
			return m_Num1 + m_Num2;	
	}
};

//������������
class SubCalculator :public AbstractCalculator
{
public:
	virtual int getResult() {

		return m_Num1 - m_Num2;
	}
};
//�˷���������
class MulCalculator :public AbstractCalculator
{
public:
	virtual int getResult() {

		return m_Num1 * m_Num2;
	}
};
void test02() {					//�������û�ָ��������Է�����̬
	AbstractCalculator* abc = new AddCalculator;//newһ��add calculator �൱�ڴ���һ��add calculator�Ķ���
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
	//�����ǵ�����
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