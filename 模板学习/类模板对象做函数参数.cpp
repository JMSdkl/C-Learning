#include<iostream>
#include<string>
using namespace std;

//��ģ���������������


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
		cout << "������" << this->m_Name<<" " << "���䣺" << this->m_age << endl;
	}
	T1 m_Name;
	T2 m_age;

};

//ָ���������������				//���
void printPerson1(Person<string, int> &p)//�ú���������������ķ�������Ҫ��һ��ָ������ģ��Ĳ���
{
	p.showPerson();
}
void test01() 
{
	Person<string, int>p("����", 10);
	printPerson1(p);
}
//����ģ�廯
template<class T1,class T2>
void printPerson2(Person<T1, T2>& p)
{
	p.showPerson();
	cout << "T1������Ϊ��" << typeid(T1).name() << endl;//��ϵͳ�ƶϵ�����Ϊʲô
	cout << "T2������Ϊ��" << typeid(T2).name() << endl;
}
void test02() 
{
	Person<string, int>p("����", 10);
	printPerson2(p);
	
}
//������ģ��    �൱�ں���ģ�������ģ��
template<class T>
void printPerson3(T& p) 
{
	p.showPerson();
	cout << "T������Ϊ��" << typeid(T).name() << endl;
}

void test03() 
{
	Person<string, int>p("����", 30);
	printPerson3(p);
}


int main() 
{
	test03();
	system("pause");
	return 0;

}