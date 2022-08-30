#include<iostream>
#include<string>
using namespace std;

template<class NameType,class AgeType>
class Person 
{public:
	Person(NameType name, AgeType age) 
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson() 
	{
		cout << "name：" << this->m_Name <<" " << "age：" << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};
void test01() 
{
	Person<string, int> p1("tom", 99);
	p1.showPerson();
}
class Person1 
{public:

	void showPerson1() 
	{
		cout << "showPerson1" << endl;
	}
};
class Person2
{public:

	void showPerson2()
	{
		cout << "showPerson2" << endl;
	}
};
template<class T>
class usezz 
{
public:
	T obj;
	void func1() 
	{
		obj.showPerson1();
	}
	void func2()
	{
		obj.showPerson2();
	}
};

void test2() 
{
	usezz<Person1>  q;//当未说明q是什么类型前，可编译通过，
					//当知道什么类型后只可以调用存在该类型的函数
	q.func1();
	//q.func2();
}


int main() 
{
	//test01();
	system("pause");
	return 0;
}