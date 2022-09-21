// Map容器学习.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <map>
#include <iostream>
#include <string>
using namespace std;

//map容器构造和赋值  //一个是key、一个是value
void myprintMap(const map<int,int>m) 
{
    for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++) 
    {
        cout << "key值为：" << it->first << " " << "value值为：" << it->second <<endl;
    }
    cout << endl;
}
void test01() 
{
    map<int, int>m;
    m.insert(pair<int, int>(1, 10));//匿名队组放到容器中
    m.insert(pair<int, int>(4, 40));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));//按照key自动排序
    myprintMap(m);
    //拷贝构造
    map<int, int>m2(m);
    myprintMap(m2);

    map<int, int>m3;
    m3 = m2;
    myprintMap(m3);
}

//map容器的大小和交换
void test02() 
{
    map<int, int>m;
    m.insert(pair<int, int>(1, 10));//匿名队组放到容器中
    m.insert(pair<int, int>(4, 40));
    m.insert(pair<int, int>(2, 80));
    //m.insert(pair<int, int>(2, 20));//插不进去，不会更新
    m.insert(pair<int, int>(3, 30));//按照key自动排序
    myprintMap(m);

    if (m.empty()) 
    {
        cout << "map容器为空" << endl;
    }
    else
    {
        cout << "map不为空" << endl;
        cout << "map的大小为：" << m.size() << endl;
    }
    cout << "交换前" << endl;
    map<int, int>m2;
    m2.insert(pair<int, int>(10, 1320));
    myprintMap(m);
    myprintMap(m2);

    cout << "交换后" << endl;
    m2.swap(m);
    myprintMap(m);
    myprintMap(m2);

}
//map容器插入和删除
void test03() 
{
    map<int, int>m;
    //第一种
    m.insert(pair<int, int>(1, 10));
    //第二种
    m.insert(make_pair(2, 20));//不用写模板参数
    //第三种
    m.insert(map<int, int>::value_type(3, 30));

    //第四种
    m[4] = 40;//重载了中括号  有问题 不建议插入，可以利用key来访问value  //可以替换旧值  其他的不可以
   // cout << m[5] << endl;//差错了，创造了个新数据0

    myprintMap(m);

    //删除
    m.erase(m.begin());
    myprintMap(m);

    m.erase(3);//按照key删除
    myprintMap(m);

    m.erase(m.begin(), m.end());
    myprintMap(m);

    m.clear();
    myprintMap(m);


}

//map容器中的查找和统计
void test04() 
{
    //查找
    map<int, int>m;
    m.insert(pair<int, int>(1, 10));//匿名队组放到容器中
    m.insert(pair<int, int>(4, 40));
    m.insert(pair<int, int>(2, 80));
    //m.insert(pair<int, int>(2, 20));//插不进去，不会更新
    m.insert(pair<int, int>(3, 30));//按照key自动排序
    myprintMap(m);
    map<int,int>::iterator pos=m.find(4);
    if (pos != m.end()) //end是最后一个元素的后方
    {
        cout << "查找到了元素key= " << pos->first << " " << "value=" << pos->second << endl;
    }
    else 
    {
        cout << "未找到元素" << endl;
    }
    //统计
    int num=m.count(3);
    cout << "num:" << num << endl;//要不为1要不为0 multimap会大于1

}

int main()
{

    test04();


    //std::cout << "Hello World!\n";
    system("pause");
    return 0;
}


