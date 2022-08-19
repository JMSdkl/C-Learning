#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
	Animal();
	//纯虚析构 有了就是抽象类   是为了解决在子类中析构的代码用不到的问题
	virtual~Animal()=0;//虚析构需要代码实现，纯虚析构也需要代码实现
	//纯虚函数
	virtual void speak() = 0;

private:

};

Animal::Animal()
{
	cout << "动物构造" << endl;
}

Animal::~Animal()
{
	cout << "纯虚析构" << endl;
} 

class Cat:public Animal
{
public:
	Cat(string name);
	~Cat();
	virtual void speak() {
		cout <<*m_Name<< "小猫在说话" << endl;
	}
	string* m_Name;

private:

};

Cat::Cat(string name)
{
	cout << "小猫构造" << endl;
	m_Name=new string(name);//在堆区创建了姓名
}

Cat::~Cat()
{
	if (m_Name != NULL) {
		cout << "小猫析构" << endl;
		delete m_Name;
		m_Name = NULL;
	}
}

void test01(){
	Animal* animal = new Cat("Tom");
	animal->speak();
	//父类的指针在析构时不会调用子类中析构函数，导致子类如果有堆区属性会出现泄露  加个virtual	用虚析构就可以
	delete animal;//为什么没有用delete 父类中不走析构函数？
}

int main()
{



	test01();










	system("pause");
	return 0;

}