#include<iostream>
#include<string>
using namespace std;

void MyPrint(int a,int b) 
{
	cout << "调用了普通函数" << endl;
}
template<class T>
void MyPrint(T a, T b) 
{
	cout << "调用函数模板" << endl;
}
template<class T>
void MyPrint(T a, T b,T c)
{
	cout << "调用重载的函数模板" << endl;
}

void test01() 
{
	int a = 10;
	int b = 20;
	//MyPrint(a, b);
	//通过空模板强制调用函数模板
	//MyPrint<>(a, b);
	//MyPrint<>(a, b,a);
	//如果模板产生更好的匹配优先调用模板
	char c = 'a';
	char d = 'b';
	MyPrint(c, d);//因为调用默认的函数要进行一步转换，而调用模板直接推导类型即可
	
}

int main() 
{
	test01();

	system("pause");
	return 0;
}