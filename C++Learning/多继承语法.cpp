#include <iostream>
#include <string>
using namespace std;

//不建议使用多继承
//当父类中出现同名的成员，要加作用域

class Base1 {
public:
	Base1() {
		m_A = 100;
	}
	int m_A;

};

class Base2 {
public:
	Base2() {
		m_B = 200;
	}
	int m_B;

};
//当父类中出现同名的成员，要加作用域
class son :public Base1, public Base2 {  //逗号分割就行
public:
	son() {
		m_C = 300;
	}
	int m_C;

};

void test01(){
	son s1;
	cout << "s1占的空间" << sizeof(s1) << endl;
}

int main() {

	test01();




	system("pause");
	return 0;

}