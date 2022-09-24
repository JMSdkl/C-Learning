// 排序案例，自定义类型的排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//排序规则：按照年龄升序排列 ,年龄相同就按身高降序
#include <list>
#include <iostream>
#include <string>
using namespace std;

class Person
{public:
    Person(string name, int age, int height) 
    {
        this->m_Name = name;
        this->m_Age = age;
        this->m_Height = height;
    }
    string m_Name;
    int m_Age;
    int m_Height;

};

void myListprint(list<Person> L1) 
{
    for (list<Person>::iterator it = L1.begin(); it != L1.end(); it++)
    {
        cout << "姓名：" << it->m_Name << " ";
        cout << "年龄：" << it->m_Age << " ";
        cout << "身高：" << it->m_Height << endl;
    }
}

//指定排序规则
bool comparePerson(Person &p1,Person &p2) //高级排序只是加if、else就可以了
{
    //按照年龄作为 升序
    if (p1.m_Age == p2.m_Age)
    {
        //年龄相同按照身高 排序   降序
        return p1.m_Height > p2.m_Height; //降序用大于号
    }
    else
    {
    return p1.m_Age < p2.m_Age; //升序是小于号

    }
}

void test01() 
{
    cout << "排序前：" << endl;
    list<Person>L1;
    //准备数据
    Person p1("张三", 35, 175);
    Person p2("李四", 45, 180);
    Person p3("赵五", 40, 170);
    Person p4("老六", 25, 190);
    Person p5("老七", 35, 160);
    Person p6("老八", 35, 165);
    L1.push_back(p1);
    L1.push_back(p2);
    L1.push_back(p3);
    L1.push_back(p4);
    L1.push_back(p5);
    L1.push_back(p6);
    myListprint(L1);
   
    //排序
    cout << "*****************************" << endl;
    cout << "排序后：" << endl;
    L1.sort(comparePerson);//放入的是函数的地址
    myListprint(L1);
}

int main()
{
    test01();
    system("pause");
    return 0;
}


