// stack容器_learning.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//先进后出类似堆栈

#include <iostream>
#include<stack>
using namespace std;
//不能遍历

void test01() 
{
	stack<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	cout << "栈的大小" << s.size() << endl;
	//只要栈不为空，就查看栈顶，并执行出栈
	while (!s.empty())
	{
		cout << "栈顶元素为：" << s.top() << endl;
		//出栈
		s.pop();
	}
	cout << "栈的大小" << s.size() << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}


