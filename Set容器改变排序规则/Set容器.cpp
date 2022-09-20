#include <iostream>
#include<set>
#include<string>
using namespace std;

class Person 
{
public:
	Person(string name,int age,int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}
	string m_Name;
	int m_Height;
	int m_Age;
};

class myCompare 
	           //��һ�����������������const
	     /*�ڶ���֮���Ա�����˵�㲻����const���У�����Ϊ����һ��const��������������ص���������
	            bool operator>(const RationalNumber& ration)
	            return (ration < *this);
                ration����������Ϊconst������ֻ�ܵ���const���������������������*/
{
public:
	bool operator()( int v1 , int v2)const 
	{
		return v1 > v2;//ǰ��������ں������������
	}

	bool operator()(const Person &p1 ,const Person &p2) const//��������ã������ڴ���
	{
		if (p1.m_Age == p2.m_Age) 
		{
			return p1.m_Height > p2.m_Height;//����
		}
		else
		{
			return p1.m_Age < p2.m_Age;//����
		}
	}

};


void myPrintSet(const set<int, myCompare>S)
{
	for (set<int, myCompare>::const_iterator it = S.begin(); it != S.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void myPrintSet(const set<int>S) 
{
	for (set<int>::const_iterator it = S.begin(); it != S.end(); it++) 
	{
		cout << *it << " ";
	}
	cout << endl;
}

void myPrintSet(const set<Person, myCompare>S)
{
	for (set<Person, myCompare>::const_iterator it = S.begin(); it != S.end(); it++)
	{
		cout  << "����Ϊ�� "<<it->m_Name<<" "<<"����Ϊ��" <<it->m_Age<<" "<<"���Ϊ��"<<it->m_Height<<endl;
	}
	cout << endl;
}


void test01() 
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	myPrintSet(s1);

//ָ���������Ϊ�Ӵ�С  Ҫ�ڲ�����ǰ�������������: set<int,myCompare> ������()

	set<int,myCompare>s2;

	s2.insert(10);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);
	myPrintSet(s2);


}

//set�����Զ�����������
void test02() 
{
	set<Person,myCompare>s1;//�������������򣬻ᱨ���Զ�������Ͷ���Ҫ�������
	Person p1("����", 18, 165);
	Person p2("����", 18, 180);
	Person p3("����", 18, 163);
	Person p4("����", 12, 120);
	Person p5("�ϰ�", 43, 170);
	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);
	s1.insert(p5);
	myPrintSet(s1);

}


int main() 
{
	test02();

	system("pause");
	return 0;
}