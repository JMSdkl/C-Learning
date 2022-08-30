#include<iostream>
#include<string>
#include "Person.hpp"//第一种解决方式，直接包含源文件
using namespace std;

//常用解决方式：将.h和.cpp放到一起，将后缀名写成.hpp

//类模板的分文件编写问题以及解决

//template<class T1,class T2>
//class Person
//{public:
//	Person(T1 name, T2 age);
//	void showPerson();
//	T1 m_Name;
//	T2 m_age;
//
//};
//构造函数的类外实现
//template<class T1,class T2>
//Person<T1,T2>::Person(T1 name, T2 age)//告诉编译器是类模板的类外实现 
//{
//	this->m_Name = name;
//	this->m_age = age;
//}
////成员函数的类外实现
//template<class T1,class T2>
//void Person<T1, T2>::showPerson() 
//{
//	cout << "名字为：" << this->m_Name << " " << "年龄为：" << this->m_age << endl;
//}
void test01() 
{
	Person<string, int> p("张三",30);  //两个无法解析的外部命令
	p.showPerson();           //两个无法解析的外部命令  把上面的Person.h改为 .cpp
}
int main() 
{
	test01();
	system("pause");
	return 0;
}