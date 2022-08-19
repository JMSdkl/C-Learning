#include<iostream>
#include<string>
using namespace std;
class MyPrint {
public:
	//重载函数调用运算符
	void operator()(string test) {
		cout << test << endl;
	}
};
void MyPrint02(string test) {
	cout << test << endl;
}
//仿函数和普通函数最大的区别是：通过类来调用
void test01() {
	MyPrint myPrint;
	myPrint("hello world");//重载函数调用运算符
						//由于使用起来非常像函数调用，所以称为仿函数
	MyPrint02("hello world");//函数调用
}
//仿函数非常灵活，没有固定写法
//加法类
class MyAdd {
public:
	int operator()(int num1,int num2) {
		return num1 + num2;
	}
};
void test02() {
	MyAdd myadd;
	int ret=myadd(100, 255);
	cout << ret << endl;
	//匿名函数对象
	cout << MyAdd()(100, 100) << endl;//MyAdd()创造了一个匿名对象，使用完就会被释放
}
int main() {
	test01();
	test02();
	system("pause");
	return 0;
}