#pragma once
#include <iostream>
using namespace std;

template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age);
	void showPerson();
	T1 m_Name;
	T2 m_age;

};


template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)//告诉编译器是类模板的类外实现 
{
	this->m_Name = name;
	this->m_age = age;
}
//成员函数的类外实现
template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "名字为：" << this->m_Name << " " << "年龄为：" << this->m_age << endl;
}