// List容器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//数据上的物理地址是非连续的，由数据域和指针域构成
//指针是维护下一个节点的地址

//list构造函数

#include <iostream>
#include <list>
#include <algorithm> 
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
void test05() 
{
    list<int>l1;
    //尾插
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    //头插
    l1.push_front(100);
    l1.push_front(200);
    l1.push_front(300);
    printList(l1);
    //尾删
    l1.pop_back();
    printList(l1);
    //头删
    l1.pop_front();
    printList(l1);

    //insert插入
    list<int>::iterator it=l1.begin();
    it++;
    l1.insert(it, 1000);//在指定位置插入数据，要用迭代器
    printList(l1);
    //删除
    it = l1.begin();
    l1.erase(it);
    printList(l1);
    //移除
    l1.push_back(10000);
    l1.push_back(10000);
    l1.push_back(10000);
    l1.push_back(10000);
    printList(l1);
    l1.remove(10000);//删除所有匹配值
    printList(l1);
    l1.clear();
    printList(l1);

}
//list数据存取
void test06() 
{
    list<int>l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    l1.push_back(50);
    //不可以用[] .at来访问list中的元素  本质是一个链表，不是用连续的线性空间存储数据，所以迭代器也不支持随机访问
    cout << "第一个元素为：" << l1.front() << endl;
    cout << "最后一个为：" << l1.back() << endl;

    //验证迭代器不支持随机访问
    list<int>::iterator it = l1.begin();
    it++;// it=it+1;加1虽然和++是一样的，但是他是不支持、+2、+3这样跳着走的，所以没有这种运算方式
    //没有重载+，但是重载了++
    it--;//支持双向



}

bool myCompare(int v1,int v2) //用int是因为list<int>了
{
    //降序 就让第一个数大于第二个数
    return v1 > v2; //想要降序就这样写    //升序就v1<v2
}

//list容器的反转和排序
//reverse、sort
void test07()
{
    list<int>l1;
    l1.push_back(20);
    l1.push_back(10);
    l1.push_back(30);
    l1.push_back(50);
    l1.push_back(40);
    printList(l1);

    //反转
    
    l1.reverse();
    printList(l1);

    //排序 所有不支持随机访问迭代器容器，不可以用标准算法
    //不支持随机访问迭代器的容器，内部会有成员函数支持
    l1.sort();//默认为从小到大排序
    printList(l1);
    l1.sort(myCompare);
    printList(l1);
}

int main()
{
    test07();
    system("pause");
}


