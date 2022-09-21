// STL函数对象.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//函数对象和仿函数是一件事情

#include <iostream>
#include<string>
using namespace std;

class Myadd 
{
public:
    int operator()(int v1,int v2) 
    {
        return v1 + v2;
    }
};

void test01() 
{
   // Myadd myadd;
    cout << Myadd()(10, 10)<<endl;
}
//函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint
{
public:
    MyPrint() 
    {
        this->count = 0;
    }
    void operator()(string test) 
    {
        cout << test << endl;
        this->count++;
    }
    int count;
};

void test02() 
{
    MyPrint my;
    my("dsf");
    my("dsf");
    cout << "myp调用次数" << my.count << endl;
}
//函数对象可以作为参数传递
void doprint(MyPrint&mp,string stt) 
{
    mp(stt);
}

void test03() 
{
    MyPrint myprint;
    doprint(myprint, "hello c++");
}

int main()
{
    test03();
    std::cout << "Hello World!\n";
}


