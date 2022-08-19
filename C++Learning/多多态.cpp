#include <iostream>
#include <string>
using namespace std;

class Animal
{public:
	virtual void speak() {
		cout << "动物在说话" << endl;
	}
};
class cat:public Animal
{public:
	virtual void speak() {
		cout << "小猫在说话" << endl;
	}
};
class Dog :public Animal
{
public:
	void speak() {
		cout << "小狗在说话" << endl;
	}
};
//地址早绑定,在编译阶段就确定函数地址
//如果想执行让猫说话，那么这个函数的地址就不能提前绑定，需要在运行阶段绑定—》就是晚绑定(父类加virtual)

//动态多态满足条件：
//1：有继承关系
//2：在子类中要重写父类的虚函数（子类中virtual关键字可写可不写）

//动态多态使用
//父类的指针或者引用 指向子类对象

void DoSpeak(Animal& animal) {//父类的引用在接收子类对象 ：允许
	
	animal.speak();//这个函数的地址不能提前确定出来，要等运行到了才知道


}
void test01() {
	cat ct;
	DoSpeak(ct);

	Dog dog;
	DoSpeak(dog);

}

void test02(){
	cout << "sizeof Animal=" << sizeof(Animal) << endl;

}

int main() {


	//test01();
	test02();//空类大小是一，加上virtual后变成4了,4字节是一个指针（什么类型指针都是4字节）

	system("pause");
	return 0;

}