#include<iostream>
#include<string>
using namespace std;


//**************泛型编程思想：函数模板、类模板****************//

//两个整型交换的函数：
void swapInt(int &a,int &b) 
{
	int temp = a;
	a = b;
	b = temp;
}
//交换两个浮点型的函数
void swapDouble(double& a, double& b) 
{
	double temp = a;
	a = b;
	b = temp;
}
//函数模板typename 和class都行
template<typename T>//声明一个模板，告诉编译器后面代码中紧跟的T不要报错
void mySwap(T& a, T& b) 
{
	T temp = a;
	a = b;
	b = temp;
}

//template<typename T>
//void func() 
//{
//	cout << "func使用" << endl;		 //调用这个函数只能使用指定数据类型才能调用
//									//func<int>();
//}

void test01() 
{
	int a = 10;
	int b = 20;;
	//swapInt(a, b);
	//利用函数模板
	//两种方式使用函数模版
	//1、自动类型推导
	//2、显示指定类型
	mySwap(a, b);//1、自动类型推导
	mySwap<int>(a, b);//2、显示指定类型
	cout << "a:" << a << " " << "b: " << b << endl;
}

int main() 
{

	test01();
	system("pause");
	return 0;
}