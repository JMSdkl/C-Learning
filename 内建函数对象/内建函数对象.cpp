// 内建函数对象.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include<functional>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//算数仿函数
//negate 一元仿函数 取反仿函数
void test01() 
{
    negate<int>n;

    cout<<n(50)<<endl;

    plus<int>p;//只能同种数据类型
    cout << p(10, 20) << endl;
}

class myCompare 
{
public:
    bool operator()(int v1,int v2) 
    {
        return v1 > v2;
    }
};

//关系仿函数
//大于 greater
void test02() 
{
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(40);
    v.push_back(30);
    v.push_back(50);
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) 
    {
        cout << *it << " ";
    }
    cout << endl;
    //降序
    //sort(v.begin(), v.end(),myCompare());//有内建的函数的可以直接使用： greater<int>()  默认的情况是用less<int>()
    sort(v.begin(), v.end(),greater<int>());//与自己写的差不多
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}


//逻辑仿函数 与或非 logical_not
void test03() 
{
    vector<bool>v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    //利用逻辑非将v搬运到v2中，并取反
    vector<bool>v2;
    v2.resize(v.size());//需要开辟空间才能搬运
    transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
    for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;


}


int main()
{

    test03();

    system("pause");
    return 0;
}


