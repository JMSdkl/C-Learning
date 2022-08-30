#include<iostream>
#include<string>
#include<algorithm>//标准算法的头文件
#include<vector>
using namespace std;
void myPrint() 
{
}
void test01() 
{
	vector<int> V;
	V.push_back(10);
	V.push_back(20);
	V.push_back(30);
	V.push_back(40);
	//通过迭代器访问容器中数据
	//vector<int>::iterator itBegin = V.begin();//起始迭代器，指向容器中第一个元素
	//vector<int>::iterator itEnd = V.end();//指向容器中最后一个元素的下一个位置
	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	//常用遍历  //与上类似
	for (vector<int>::iterator it = V.begin(); it != V.end(); it++) 
	{
		cout << *it << endl;
	}
	//第三种遍历方式 利用stl的遍历算法
	for each (V.begin(),V.end())
	{

	}

}
int main() 
{
	test01();

	system("pause");
	return 0;
}