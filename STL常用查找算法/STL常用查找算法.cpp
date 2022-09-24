// STL常用查找算法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
//查找内置的类型 find  、、具体查找
void test01() 
{
    vector<int>v1;
    for (int i = 0; i < 10; i++) 
    {
        v1.push_back(i);
    }
   
    vector<int>::iterator pos= find(v1.begin(), v1.end(), 5);
    if (pos == v1.end()) 
    {
        cout << "没有找到" << endl;
    }
    else
    {
        cout << "该元素为：" << *pos << endl;
    }
}
class Person 
{
public:
    Person(string name, int age) 
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    //重载==号让底层知道如何对比Person数据类型
    bool operator==(const Person&p) //底层要加const
    {
        if ( this->m_Age == p.m_Age) 
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string m_Name;
    int m_Age;
};
class GreaterFive 
{
public:
    bool operator()(int val) 
    {
        return val > 5;
    }
};

void test02() 
{
    vector<Person>v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    Person pp("bbb", 20);
    vector<Person>::iterator pos=find(v.begin(), v.end(), pp);
    if (pos == v.end()) 
    {
        cout << "找不到这个人" << endl;
    }
    else
    {
        cout << "这个人是：" << pos->m_Name << " " << "年龄为：" << pos->m_Age << endl;
    }
}

//内置函数find_if 对于内置数据类型   //条件查找
void test03()
{
    vector<int>v1;
    for (int i = 0; i < 10; i++) 
    {
        v1.push_back(i);
    }
    vector<int>::iterator pos = find_if(v1.begin(), v1.end(), GreaterFive());//条件查找
    if (pos == v1.end()) 
    {
        cout << "没找到该元素" << endl;
    }
    else
    {
        cout << "该元素为：" << *pos << endl;
    }
}
//查找自定义类型
class Greater20 
{
public:
    bool operator()(Person p) 
    {
        return p.m_Age > 20;
       
    }
};
void test04() 
{
    vector<Person>v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    vector<Person>::iterator pos = find_if(v.begin(), v.end(), Greater20());//年龄大于20
    if (pos == v.end())
    {
        cout << "没找到该元素" << endl;
    }
    else
    {
        cout << "姓名为：" << pos->m_Name<<" 年龄为："<<pos->m_Age << endl;
    }
}

//查找相邻重复元素 adjacent_find
//返回相邻重复元素的第一个元素的迭代器
void test05() 
{
    vector<int>v;
    v.push_back(0);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    v.push_back(3);
    v.push_back(0);
    vector<int>::iterator pos=adjacent_find(v.begin(), v.end());
    if (pos == v.end())
    {
        cout << "没找到该元素" << endl;
    }
    else
    {
        cout << "该元素为：" << *pos << endl;
    }
}
//查找相邻重复元素 查找指定元素是否存在 ，返回bool//速度非常快，但需要有序的
void test06() 
{
    vector<int>v;
    for (int i = 0; i < 10; i++) 
    {
        v.push_back(i);
    }
    bool res=binary_search(v.begin(),v.end(),9);//要是升序的，不然重载才行
    if (res) 
    {
        cout << "找到了" << endl;
    }
    else
    {
        cout << "找不到" << endl;
    }
}

//count统计个数
//统计内置
//统计自定义
void test07() 
{
    vector<Person>v;
    Person p1("aaa", 12);
    Person p2("bbb", 12);
    Person p3("ccc", 12);
    Person p4("ddd", 30);
    Person p5("eee", 40);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    Person p("zzz", 12);
    int num = count(v.begin(), v.end(), p);
    cout << "与zzz一样大的有" << num << "个" << endl;
}

//count_if按条件来找个数
//统计自定义数据类型

int main()
{
    test07();
    system("pause");
}


