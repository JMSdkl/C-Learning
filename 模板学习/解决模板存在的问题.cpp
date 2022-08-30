#include<iostream>
#include<string>
using namespace std;

//模板的局限性
class person 
{public:
	person(string name, int age) 
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

template<class T>
bool myCompare(T& a, T& b) 
{
	if (a == b) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

//利用具体化的person版本实现代码，具体化优先调用
template<>bool myCompare(person& p1, person& p2) //专门处理person的实现
{
	if (p1.name == p2.name && p1.age == p2.age) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test01() 
{
	int a = 10;
	int b = 20;
	bool ret = myCompare(a, b);
	if (ret == 1) 
	{
		cout << "等于" << endl;
	}
	else
	{
		cout << "不等" << endl;
	}
}

void test02() 
{
	person A("tom", 10);
	person B("tom", 20);
	bool ret = myCompare(A, B);//这样传值需要进行运算符重载
	if (ret == 1)
	{
		cout << "等于" << endl;
	}
	else
	{
		cout << "不等" << endl;
	}
}

int main() 
{
	test02();

	system("pause");
	return 0;
}