#include<iostream>
#include<string>

using namespace std;
template<class T1,class T2>
class Person;				//且让编译器知道person类存在

//类外实现                  //如果全局函数是类外实现，需要让编译器提前知道这个函数的存在
template<class T1,class T2>//实现时却是模板的实现，需要在声明里加空模板的参数列表
void printPerson2(Person<T1, T2> p)//不用加作用域，因为是全局函数 
{
	cout << "姓名：" << p.name << " " << "年龄：" << p.age << endl;
}
//通过全局函数打印person信息
template<class T1,class T2>
class Person
{	//全局函数类内实现
	friend void printPerson(Person<T1,T2> p)
	{
		cout << "姓名：" << p.name << " " << "年龄：" << p.age << endl;
	}
	//全局函数类外实现
	friend void printPerson2<>(Person<T1, T2> p);//声明时是普通函数的声明
	
public:
	Person(T1 name, T2 age) 
	{
		this->name = name;
		this->age = age;
	}

private:
	T1 name;
	T2 age;


};


//全局函数在类内实现
void test01() 
{
	Person<string,int> p1("张三",12);
	printPerson(p1);

}

//全局函数在类外实现的调用测试
void test02() 
{
	Person<string, int>p2("李四",50);
	printPerson2(p2);
}

int main() 
{
	//test01();
	test02();
	system("pause");
}