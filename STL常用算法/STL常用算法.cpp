// STL常用算法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<algorithm>
#include<functional>
#include<numeric>
#include<vector>
using namespace std;

//涉及比较、交换、查找、遍历、复制、修改等

//普通函数
void print01(int val) 
{
    cout << val << " ";
}

class print02 
{
public:
    void operator()(int val) 
    {
        cout << val << " ";
    }
};

class Transform 
{
public:
    int operator()(int v) 
    {
        return v;
    }
};

void test01() 
{
    vector<int>v1;
    for (int i = 0; i < 10; i++) 
    {
        v1.push_back(i);
    }
    for_each(v1.begin(), v1.end(), print01);
    cout << endl;

    for_each(v1.begin(), v1.end(), print02());
    cout << endl;
}

void test02() 
{
    vector<int>v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    for_each(v1.begin(), v1.end(), print01);
    cout << endl;

    vector<int>target;
    target.resize(v1.size());
    transform(v1.begin(), v1.end(), target.begin(), Transform());
    for_each(target.begin(), target.end(), print02());
    cout << endl;
}

int main()
{
    test02();
    system("pause");
}


