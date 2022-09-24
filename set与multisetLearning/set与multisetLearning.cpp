// set与multisetLearning.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<set>
#include <iostream>
#include <string>
using namespace std;

class myCompare
{
public:
	bool operator()(int v1, int v2) 
	{
		return v1 > v2;
	}
};
void printset(const set<int>s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void printmulset(const multiset<int>ms) 
{
	for (multiset<int>::const_iterator it = ms.begin(); it != ms.end(); it++) 
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01() 
{
	set<int>s1;
	
	  //返回类型是pairib是队组，成对出现的数据pait<iterator ,bool>
					//bool表示插成功吗，迭代器是当前插入地方
	pair<set<int>::iterator, bool> ret = s1.insert(10);
	if (ret.second) 
	{
		cout << "第一次插入成功" << endl;
	}
	else
	{
		cout << "第一次插入失败" << endl;
	}
	
	ret= s1.insert(10);
	if (ret.second)
	{
		cout << "第二次插入成功" << endl;
	}
	else
	{
		cout << "第二次插入失败" << endl;
		cout << *ret.first << endl;
	}

	multiset<int>ms;//允许插入重复的值
	ms.insert(10);
	ms.insert(10);
	printmulset(ms);//可看到有重复

}

//pair对组创建
//成对出现的数据，利用对组可以返回两个数据
void test02() 
{
	pair<string, int>p("Tom", 20);
	cout << "姓名：" << p.first << "年龄：" << p.second << endl;
	//第二种方式
	pair<string, int>p2 = make_pair("Jerry", 30);
	cout << "姓名：" << p2.first << "年龄：" << p2.second << endl;
}

//set容器排序 ，默认的排序规则是从小到大，可以改变排序规则
//利用仿函数（之前已经使用过函数来实现了）
void test03() 
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	printset(s1);
	set<int>s2;
	s2.insert(10);
	

}


int main()
{
	test03();
	system("pause");
	return 0;
}


