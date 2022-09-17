// List容器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//数据上的物理地址是非连续的，由数据域和指针域构成
//指针是维护下一个节点的地址

//list构造函数

#include <iostream>
#include <list>
using namespace std;

void printList(const list<int>& L) 
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) //it是迭代器，不是数据本身的地址
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01() 
{
    list<int>l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    //遍历容器
    printList(l1);

    //区间构造
    list<int>l2(l1.begin(),l1.end());
    printList(l2);

    list<int>l3(l2);
    printList(l3);

    list<int>l4(10, 1000);
    printList(l4);

}
//list容器的赋值和交换
void test02() 
{
    list<int>l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    printList(l1);
    //利用operator=的方式赋值
    list<int>l2;
    l2 = l1;
    printList(l2);
    list<int>l3;
    l3.assign(l2.begin(), l2.end());
    printList(l3);
    list<int>l4;
    l4.assign(10, 100);
    printList(l4);
}
void test03() 
{
    cout << "交换前" << endl;
    list<int>l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    printList(l1);
    list<int>l2(10, 100);
    printList(l2);

    cout << "交换后" << endl;
    l1.swap(l2);
    printList(l1);
    printList(l2);

}
//list容器中的大小操作
void test04() 
{
    list<int>l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    printList(l1);
    if (l1.empty()) 
    {
        cout << "l1为空" << endl;
    }
    else
    {
        cout << "l1不为空" << endl;
        cout << "l1的大小为：" << l1.size() << endl;

    }
    //重新指定大小
    l1.resize(10,33);
    printList(l1);
    l1.resize(2);
    printList(l1);

}

//list容器的插入和删除
//比vector容器多了一个remove（elm）//删除容器中所以与elm值匹配的元素

int main()
{
    test04();
    system("pause");
}


