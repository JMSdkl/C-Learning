// set_multiset容器learning.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//属于关联式容器，底层是用二叉树实现
//所有元素都会在插入时自动排序



#include <string>
#include <iostream>
#include <set>
using namespace std;

void myprintfSet(const set<int>s) 
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++) 
	{
		cout << *it << " ";
	}
	cout << endl;
}


//set容器赋值、构造
void test01() 
{
	set<int>s1;
	//插入数据只有insert可以使用 且不可以重复  会自动排序
	//重复插入只会插入一个数据
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(30);
	s1.insert(20);
	s1.insert(50);
	myprintfSet(s1);

	//拷贝构造
	set<int>s2(s1);
	myprintfSet(s2);

	//赋值
	set<int>s3;
	s3 = s2;
	myprintfSet(s3);
}
 
//set容器的大小和交换  不支持resize的
void test02() 
{
	set<int>s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(50);
	
	if (s1.empty()) 
	{
		cout << "set容器为空" << endl;
	}
	else
	{
		cout << "set容器不为空" << endl;
		cout << "set大小为：" << s1.size() << endl;
	}
	set<int>s2;
	s2.insert(120);
	s2.insert(506);
	s2.insert(70);
	s2.insert(66);
	s2.insert(65);
	cout << "交换前为：" << endl;
	myprintfSet(s1);
	myprintfSet(s2);
	s1.swap(s2);
	cout << "交换后为：" << endl;
	myprintfSet(s1);
	myprintfSet(s2);
	
}

//set容器的插入和删除
void test03() 
{
	set<int>s1;
	s1.insert(30);
	s1.insert(10); 
	s1.insert(20);
	
	s1.insert(40);
	myprintfSet(s1);
	//删除
	s1.erase(s1.begin());
	myprintfSet(s1);
	s1.erase(30);
	myprintfSet(s1);
	//清空
	s1.erase(s1.begin(), s1.end());
	myprintfSet(s1);
	s1.clear();
	myprintfSet(s1);
}

//set查找和统计  查找key是否存在若存在返回迭代器，不存在就返回s1.end()  还可以统计key的个数
void test04() 
{
	set<int>s1;
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);
	myprintfSet(s1);
	set<int>::iterator it=s1.find(200);
	if (it != s1.end()) 
	{
		cout << "找到该元素:" << *it << endl;
	}
	else
	{
		cout << "未找到该元素" << endl;
	}
	int num = s1.count(30);
	cout << "num:" << num << endl;
}


int main()
{
	test04();
	system("pause");
	return 0;
}


