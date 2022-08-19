#include <iostream>
#include <string>
using namespace std;
class person {
public:
	person(int age) {
		this->age = age;	//重名了，成员属性和传入形参需要规范
	}				//this指针可解决这个问题
	~person() {
		cout << "调用了析构函数且m_B:" << m_B << endl;
	}
	//所有对象都共享同一份数据
	//编译阶段就分配内存
	//类内声明，类外初始化操作  是必须要有的操作，否则报错
	static int m_A;				//也是有访问权限的
	int age;
	person& personaddage(person& p) //返回类型要改变
	{
		this->age += p.age;//可以隐式调用this 不写也行
		//this是指向p2的指针，而*this就可以解引用指向p2本体
		return *this;
	}
	static void func() {
		cout << "调用了静态变量函数" << endl;
	}

private:
	static int m_B;				//静态变量不能在类内初始化
	

};
int person::m_A=100;//告诉他是person里面的成员  通过类名访问
int person::m_B=20;//类外可以初始化
void test01() {						//静态成员变量不属于某一个对象上，所有对象都共享同一份数据
	//person p;						//所以有两种访问方式：1、通过对象访问  2、通过类名访问
	//cout << p.m_A << endl;
	//person p2;
	//p2.m_A = 200;        //通过对象访问
	//cout << p.m_A << endl;
	//cout << person::m_A << endl;
	////cout << person::m_B << endl;//不可以访问
	//通过对象进行访问
	person p(18);
	p.func();
	person::func();
	cout <<"p成员的年龄为：" << p.age << endl;

}

void test02() {

	person p1(10);
	person p2(10);
	p2.personaddage(p1).personaddage(p1).personaddage(p1);
	cout << "p2的年龄为:" << p2.age << endl;

}

int main() {

	test01();
	test02();
	system("pause");
	return 0;
}