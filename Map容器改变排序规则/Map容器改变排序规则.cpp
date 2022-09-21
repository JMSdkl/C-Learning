// Map容器改变排序规则.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<map>
#include <iostream>
#include<string>
using namespace std;
//map容器中的排序规则改变
class Person 
{
public:
    Person(string name, int age, int height) 
    {
        this->m_Name = name;
        this->m_age;
        this->m_height;
    }
    string m_Name;
    int m_age;
    int m_height;
};


class myCompare //是比较key的吧？还是比较value，如果是比较value，那改怎么写？
{
public:
    bool operator()( int v1 , int v2) const
    {
        return v1 > v2;//降序
    }
    bool operator()(map<int, Person, myCompare>m1, map<int, Person, myCompare>m2) const //明天研究一下
    {
        if (0);
    }


};

void myPrintMap(const map<int,int, myCompare>m)
{
    for (map<int, int, myCompare>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key=" << it->first << " " << "value=" << it->second << endl;
    }
    cout << endl;

}

void test01() 
{
    map<int, int,myCompare>m;
    /*Person p1("张三", 18, 165);
    Person p2("李四", 18, 180);
    Person p3("赵五", 18, 163);
    Person p4("老六", 12, 120);
    Person p5("老八", 43, 170);
    m.insert(make_pair(1, p1));
    m.insert(make_pair(2, p2));
    m.insert(make_pair(3, p3));
    m.insert(make_pair(4, p4));
    m.insert(make_pair(5, p5));*/
    //myPrintMap(m);
    m.insert(make_pair(1, 20));
    m.insert(make_pair(2, 50));
    m.insert(make_pair(3, 10));
    m.insert(make_pair(4, 30));
    m.insert(make_pair(5, 40));  //这样重载是比较key值
        myPrintMap(m);

}

int main()
{
    test01();


    //std::cout << "Hello World!\n";
    system("pause");
    return 0;
}
