#include<iostream>
#include<string>
#include "Person.hpp"//��һ�ֽ����ʽ��ֱ�Ӱ���Դ�ļ�
using namespace std;

//���ý����ʽ����.h��.cpp�ŵ�һ�𣬽���׺��д��.hpp

//��ģ��ķ��ļ���д�����Լ����

//template<class T1,class T2>
//class Person
//{public:
//	Person(T1 name, T2 age);
//	void showPerson();
//	T1 m_Name;
//	T2 m_age;
//
//};
//���캯��������ʵ��
//template<class T1,class T2>
//Person<T1,T2>::Person(T1 name, T2 age)//���߱���������ģ�������ʵ�� 
//{
//	this->m_Name = name;
//	this->m_age = age;
//}
////��Ա����������ʵ��
//template<class T1,class T2>
//void Person<T1, T2>::showPerson() 
//{
//	cout << "����Ϊ��" << this->m_Name << " " << "����Ϊ��" << this->m_age << endl;
//}
void test01() 
{
	Person<string, int> p("����",30);  //�����޷��������ⲿ����
	p.showPerson();           //�����޷��������ⲿ����  �������Person.h��Ϊ .cpp
}
int main() 
{
	test01();
	system("pause");
	return 0;
}