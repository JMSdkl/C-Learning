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
	           //第一，重载运算符不必须const
	     /*第二，之所以编译器说你不加上const不行，是因为你让一个const对象调用了你重载的这个运算符
	            bool operator>(const RationalNumber& ration)
	            return (ration < *this);
                ration对象被你声明为const对象，它只能调用const函数（包括重载运算符）*/
{
public:
	bool operator()( int v1 , int v2)const 
	{
		return v1 > v2;//前面的数大于后面的数、降序
	}

	bool operator()(const Person &p1 ,const Person &p2) const//最好用引用，消耗内存少
	{
		if (p1.m_Age == p2.m_Age) 
		{
			return p1.m_Height > p2.m_Height;//降序
		}
		else
		{
			return p1.m_Age < p2.m_Age;//升序
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
		cout  << "姓名为： "<<it->m_Name<<" "<<"年龄为：" <<it->m_Age<<" "<<"身高为："<<it->m_Height<<endl;
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

//指定排序规则为从大到小  要在插数据前告诉他排序规则: set<int,myCompare> 重载了()

	set<int,myCompare>s2;

	s2.insert(10);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);
	myPrintSet(s2);


}

//set容器自定义类型排序
void test02() 
{
	set<Person,myCompare>s1;//如果不给排序规则，会报错，自定义的类型都需要排序规则
	Person p1("张三", 18, 165);
	Person p2("李四", 18, 180);
	Person p3("赵五", 18, 163);
	Person p4("老六", 12, 120);
	Person p5("老八", 43, 170);
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