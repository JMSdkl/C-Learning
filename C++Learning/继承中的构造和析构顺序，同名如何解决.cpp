#include <iostream>
#include<string>
using namespace std;

class Base {
public:
	Base() {
		m_A = 100;
		cout << "base的构造函数" << endl;
	}
	~Base() {
		cout << "base的析构函数" << endl;
	
	}
	int m_A;
	static int m_B;
	 void func() {
		cout << "base里的st函数" << endl;
	}
	static void func(int r) {
		cout << "base里的st func(int r)函数" << endl;
	}
};
int Base::m_B=100;

class son :public Base {
public:
	son() {
		m_A = 200;
		cout << "son的构造函数" << endl;
	}
	~son() {
		cout << "son的析构函数" << endl;

	}
	int m_A;
	static int m_B;
	static void func() {
		cout << "Son里的st 函数" << endl;
	}

};
int son::m_B = 200;

void test01() {
	son s1;//直接访问就是访问自身的
	cout<<"Son 的m_A:" << s1.m_A << endl;
	//如果要访问父类的需要加作用域
	cout << "Base 的m_A:" << s1.Base::m_A << endl;

}
void test02() {
	son s2;
	s2.func();
	s2.Base::func();//与上类似加作用域可以是访问父类里的函数

	//如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所以同名成员函数
	//如果想访问父类同名的成员函数，加作用域
	s2.Base::func(100);
}

void test03() {
	//1:通过对象来访问
	son s3;
	cout << "Son下的 m_B:" << s3.m_B << endl;
	cout << "Base下的 m_B:" << s3.Base::m_B << endl;
	//2：通过类名来访问
	cout << "Son下的 m_B:" << son::m_B << endl;
	//第一个：：代表通过类名方式访问，第二个：：代表访问父类作用域下
	cout << "Base下的 m_B:" << son::Base::m_B << endl;

}
void test04() {

	son s;
	s.func();
	s.Base::func();
	s.Base::func(10);

	son::func();//
	//son::Base::func();//用不了的原因是非静态成员要用对象来调用，在父类func前加static就行

}


//顺序：先构造父类再子类，析构与构造相反

int main() {

	//test01();
	//test02();
	//test03();
	test04();
	system("pause");
	return 0;

}