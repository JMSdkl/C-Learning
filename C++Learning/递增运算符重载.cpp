#include <iostream>
#include <string>
using namespace std;
//***********************递增运算符的重载**********************//
class MyInteger {
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger() {
		m_Num = 0;
	};
	//重载++运算符前置
	MyInteger& operator++() {//返回引用是为了进行链式编程
							//如果返回的是数值，第二次加是加到拷贝出来的东西上了
		m_Num++;
		//再将自身进行返回
		return *this;//记得是解引用
	}
	//重载++运算符后置  （int）只能是int
	const MyInteger operator++(int) {//返回类型不同不满足重载的条件，起码要作用域不同或者形参不同
						//占位参数的作用可以体现，可以用于区分前置和后置递增
		//先 记录当时结果
		MyInteger temp = *this;
		//后 递增
		this->m_Num++;//一般省略this
		//最后将记录的结果做返回
		return temp;
	}
private:
	int m_Num;
};
//重载左移
ostream& operator<<(ostream& cout, MyInteger myint) {
	cout << myint.m_Num ;
	return cout;
}
void test02(){
	MyInteger myint,myint2;
		//myint2 = (myint++)++;//这种即使是在原来固有的也是错误的,不用纠结
		myint = myint++;
		cout << myint << endl;
		cout << myint << endl;
		
}
void test01() {
	MyInteger myint;
	cout << ++(++myint) << endl;
}

int main() {
	test01();
	test02();
	size_t i = 1;
	i +=i++;
	cout << "000:" << i << endl;
	system("pause");
	return 0;


}