// deque容器learning.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <iostream>
#include <deque>
#include <algorithm>//标准算法的头文件
using namespace std;

void printfDeque(const deque<int> &d) 
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) 
	{
		//*it = 100;//为了防止这样的操作可以加const,迭代器也要改为const_iterator
		cout << *it << " ";
	}
	cout << endl;
}

//双端数组，可以对头端进行插入删除
void test01() 
{
	deque<int>d1;
	for (int i = 0; i < 10; i++) 
	{
		d1.push_back(i);
	}
	printfDeque(d1);
	deque<int>d2(d1.begin(), d1.end());
	printfDeque(d2);
	deque<int>d3(10, 100);
	printfDeque(d3);
	deque<int>d4(d3);
	printfDeque(d4);
	//等号赋值
	deque<int>d5;
	d5 = d1;
	printfDeque(d5);
	deque<int>d6;
	d6.assign(d3.begin(), d3.end());
	printfDeque(d6);
	deque<int>d7;
	d7.assign(10, 100);
	printfDeque(d7);
}

//deque大小操作  没有容量的限制，只有元素个数
void test02() 
{
	deque<int>d1;
	for (int i = 0; i < 10; i++) 
	{
		d1.push_back(i);
	}
	printfDeque(d1);
	if (d1.empty()) 
	{
		cout << "d1为空" << endl;
	}
	else
	{
		cout << "d1不为空" << endl;
		cout << "d1元素个数为："<<d1.size() << endl;

	}
	//重新指定大小：
	d1.resize(15);
	printfDeque(d1);
	d1.resize(20,1);
	printfDeque(d1);
	d1.resize(5);
	printfDeque(d1);

}

//deque容器的插入和删除
void test03() 
{
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);
	printfDeque(d1);

	//尾删 头删
	d1.pop_back();
	d1.pop_front();
	printfDeque(d1);
	

}

void test04() 
{
	//指定位置插入，可以插区间数据
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);
	printfDeque(d1);
	d1.insert(d1.begin(), 1000);
	printfDeque(d1);
	d1.insert(d1.begin(),2, 10000);
	printfDeque(d1);

	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	d1.insert(d1.begin(), d2.begin(), d2.end()); //在一个指定位置插入区间
	printfDeque(d1);

	deque<int>::iterator it = d1.begin();
	it++;
	d1.erase(it);
	printfDeque(d1);
	//按照区间方式删除
	d1.erase(d1.begin(), d1.end());
	printfDeque(d1);
	d1.clear();
	printfDeque(d1);
}

//数据存取
void test05() 
{
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);
	for (int i = 0; i < d1.size(); i++) 
	{
		cout << d1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1.at(i) << " ";
	}
	cout << endl;

	cout << "第一个元素为：" << d1.front() << endl;
	cout << "最后一个元素为：" << d1.back() << endl;
}

//deque容器排序
//sort可以对deque里的区间排序
void test06()
{
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);
	printfDeque(d1);
	sort(d1.begin(), d1.end());//默认从小到大
	//对于支持随机访问的迭代器，都可以支持sort排序
	printfDeque(d1);
}

int main()
{

	test06();

	system("pause");
	return 0;
}

