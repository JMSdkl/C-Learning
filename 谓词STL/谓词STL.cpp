// 谓词STL.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
//一元谓词

class GreaterFive 
{
public:
    bool operator()(int val) 
    {
        return val > 5;
    }
};

void test01() 
{
    vector<int>v;
    for (int i = 0; i < 10; i++) 
    {
        v.push_back(i);
    }
    //查找容器中大于5的数字    find_if只找一个，有一个就退出
    vector<int>::iterator it= find_if(v.begin(), v.end(), GreaterFive());//pred是谓词   GreaterFive()是一个匿名的函数对象
    if (it == v.end()) 
    {
        cout << "没有" << endl;
    }
    else
    {
        cout << "找到了 为：" << *it << endl;
    }


}

class mycompare 
{
public:
    bool operator()(int v1,int v2) 
    {
        return v2 < v1;
    }
};

//二元谓词
void test02() 
{
    vector<int>v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    mycompare my;  //_pred 传函数对象 

    sort(v.begin(), v.end(), mycompare());//降序
    sort(v.begin(),v.end());//升序
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) 
    {
        cout << *it << " ";
    }
    cout << endl;
}


int main()
{
    test02();
    std::cout << "Hello World!\n";
}


