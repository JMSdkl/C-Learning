#include<iostream>
#include<string>
using namespace std;

//类模板对象做函数参数


template<class T1,class T2>
class Person
{
public:
	Person(T1 name, T2 age) 
	{
		this->m_Name = name;
		this->m_age = age;
	}
	void showPerson() 
	{
		cout << "姓名：" << this->m_Name<<" " << "年龄：" << this->m_age << endl;
	}
	T1 m_Name;
	T2 m_age;

};

//指定传入参数的类型				//最常用
void printPerson1(Person<string, int> &p)//用函数来调用类里面的方法，需要传一个指定的类模板的参数
{
	p.showPerson();
}
void test01() 
{
	Person<string, int>p("张三", 10);
	printPerson1(p);
}
//参数模板化
template<class T1,class T2>
void printPerson2(Person<T1, T2>& p)
{
	p.showPerson();
	cout << "T1的类型为：" << typeid(T1).name() << endl;//看系统推断的类型为什么
	cout << "T2的类型为：" << typeid(T2).name() << endl;
}
void test02() 
{
	Person<string, int>p("李四", 10);
	printPerson2(p);
	
}
//整个类模板    相当于函数模板配合类模板
template<class T>
void printPerson3(T& p) 
{
	p.showPerson();
	cout << "T的类型为：" << typeid(T).name() << endl;
}

void test03() 
{
	Person<string, int>p("赵五", 30);
	printPerson3(p);
}


int main() 
{
	test03();
	system("pause");
	return 0;

}