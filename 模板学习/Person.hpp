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
Person<T1, T2>::Person(T1 name, T2 age)//���߱���������ģ�������ʵ�� 
{
	this->m_Name = name;
	this->m_age = age;
}
//��Ա����������ʵ��
template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "����Ϊ��" << this->m_Name << " " << "����Ϊ��" << this->m_age << endl;
}