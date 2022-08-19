#include <iostream>
#include<string>
using namespace std;
//继承方式
//公共继承
class Base1
{
public:
	int A;
protected:
	int B;
private:
	int C;


};
class son1 :public Base1
{
public:
	void func() {
		A = 10;//父类成员公共权限依然是公共
		B = 10;//父类成员保护权限依然是保护
		//C = 10;//父类中的私有成员访问不到
	}

};

void test01() {
	son1 s1;
	s1.A = 100;
	//s1.B = 100;//是一个保护权限类外不能访问
}

class base2 {
public:
	int A;
protected:
	int B;
private:
	int C;


};
class son2 :protected base2 {

public:
	void func() {
		A = 100;	//父类公共的，到子类为保护
		B = 100;	//父类保护的，到子类为保护
		//C = 100;//子类访问不到
	
	}


};

void test02(){
	son2 s2;
	//s2.A = 1000;//在子类中为保护权限


}
class Base3
{
public:
	int A;
protected:
	int B;
private:
	int C;


};
class son3 :private Base3 {

public:
	void func() {
		A = 100;	//父类公共的，到子类为私有
		B = 100;	//父类保护的，到子类为私有
		//C = 100;//子类访问不到

	}


};

void test03() {
	son3 s3;
	//s3.A = 100;//是一个私有权限类外不能访问
	//s1.B = 100;//是一个私有权限类外不能访问
}

class grandson3 :public son3 {
public:
	void func() {
		//A = 100;//孙子类继承不到了
	}


};
class Son :public Base1 {//父类的私有成员也有被继承只是访问不了而已

public:
	int m_D;

};
void test33() {
	cout << "Son 的大小" << sizeof(Son) << endl;

}


int main() {



	test33();








	system("pause");
	return 0;

}