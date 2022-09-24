// vector_learning.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <string>
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>&v) 
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) 
	{
		cout << *it << " ";
	}
	cout << endl;
}


void test01() 
{
	vector<int>v1;//默认构造
	for (int i = 0; i < 10; i++) 
	{
		v1.push_back(i);
	}
	printVector(v1);
//通过区间的方式构造
	vector<int>v2(v1.begin(), v1.end());
	printVector(v2);
	//n个elem方式构造
	vector<int>v3(10, 100);
	printVector(v3);
	vector<int>v4(v3);//常用
	printVector(v4);
	
}
//vector的赋值
void test02() 
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	//operator=
	vector<int>v2;
	v2 = v1;
	printVector(v2);
	//assign赋值
	vector<int>v3;
	v3.assign(v1.begin(), v1.end());//前闭后开
	printVector(v3);
	vector<int>v4;
	v4.assign(10,100);//10个100
	printVector(v4);
}

//vector容器的容量和大小
void test03() 
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	if (v1.empty()) 
	{
		cout << "v1为空" << endl;
	}
	else
	{
		cout << "v1不为空" << endl;
		cout << "v1的容量为：" << v1.capacity() << endl;//动态扩展
		cout << "v1的大小为：" << v1.size() << endl;
	}
	//重新指定大小
	v1.resize(15,50);//默认用0来填充（如果重新指定的过长）可以指定默认的填充值是多少
	printVector(v1);//
	v1.resize(5);
	printVector(v1);//如果指定短了，超出的部分删除
	//指定大了容量会改变，指定小了容量不会改变
	cout << "v1的容量为：" << v1.capacity() << endl;
}

//vector容器的插入和删除
void test04() 
{
	vector<int>v1;
	//尾插
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printVector(v1);
	//尾删
	v1.pop_back();
	printVector(v1);
	//插入
	v1.insert(v1.begin()+1, 100);   //记得提供迭代器
	printVector(v1);
	v1.insert(v1.begin(), 2, 1000);//开头插入两个1000
	printVector(v1);
	//删除
	v1.erase(v1.begin());
	printVector(v1);

	v1.erase(v1.begin()+2, v1.end());//可以提供区间的清空
	printVector(v1);

	v1.clear();
	printVector(v1);
}

void test05() 
{
	vector<int>v1;
	for (int i = 0; i < 10; i++) 
	{
		v1.push_back(i);
	}
	for (int i = 0; i < v1.size(); i++) 
	{
		cout << v1[i] << " ";//利用中括号的方式访问元素
	}
	cout << endl;
	for (int i = 0; i < v1.size(); i++) 
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;
	//获取第一个元素
	cout<<v1.front()<<endl;
	//获取最后一个元素
	cout << v1.back() << endl;
}

//两个容器互换
//swap（vec）
//基本使用
void test06() 
{
	vector<int>v1;
	cout << "互换前打印" << endl;
	for (int i = 0; i < 10; i++) 
	{
		v1.push_back(i);
	}
	printVector(v1);
	vector<int>v2;
	for (int i = 10; i > 0; i--) 
	{
		v2.push_back(i);
	}
	printVector(v2);
	cout << "互换后打印" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);

}
//实际用途 巧用swap可以收缩内存空间
void test07() 
{
	vector<int>v;
	for (int i = 0; i < 100000; i++) 
	{
		v.push_back(i);
	}
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;
	v.resize(3);//重新指定大小，大小变为3，容量不变 这样太浪费空间了
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;
	//巧用swap收缩内存
	vector<int>(v).swap(v);
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;
}

//vector预留空间，分配内存了，但没有初始化，减少自动分配内存的次数
void test08() 
{
	vector<int>v1;
	//利用reserve预留空间
	v1.reserve(100000);//在已知数据集多大的时候可用
	int num=0;
	int *p = NULL;
	for (int i = 0; i < 100000; i++) 
	{
		v1.push_back(i);//因为每次插数据到当前上限后，会动态的扩展空间，看下扩展了多少次
		if (p != &v1[0]) //每次分配内存，是在一个新的内存段分配的，所以判断
		{				//是否为首地址 
			p = &v1[0];
			num++;
		}
	}
	cout << num << endl;
}


int main()
{
	test08();
	system("pause");
	return 0;
}


