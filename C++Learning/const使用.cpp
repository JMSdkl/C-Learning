#include <iostream>
#include <string>
using namespace std;

class person {
public:		//this指针的本质是指针常量，指针的指向不可以修改
			//Person * const this;
			//在成员函数后面加const 修饰的是this指针，让指针指向的值无法改变

	//常函数

	void showPerson() const//里面的值就不可以修改了
	{                  //这里加了const就相当于：const Person * const this;
		//this->m_A = 100;
		//this = NULL;//this指针是不可以修改指向
		this->m_B = 100;
	}
	void showPerson2() //里面的值就不可以修改了
	{                  //这里加了const就相当于：const Person * const this;
		this->m_A = 100;
		//this = NULL;//this指针是不可以修改指向
		
	}
	int m_A;
	mutable int m_B;//特色变量，在常数中也可以修改值 加关键字mutable

};

void test02() {
	const person p;//常对象，不允许修改指针对象的值
	//p.m_A = 100;//报错
	p.m_B = 100;//b有关键字mutable，即使在常对象中也可以修改值
	//常对象只能调用常函数
	p.showPerson();
	//p.showPerson2();//调用不了常函数

}



int main() {




	system("pause");
	return 0;

}