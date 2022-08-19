#include <iostream>
#include <string>
using namespace std;
//**************************左移运算符的重载**************************//
class person {
	friend ostream& operator<<(ostream& cout, person& p);
public:
	person(int a, int b) {
		m_A = a;
		m_B = b;
	}
private:
	int m_A;
	int m_B;
	//利用成员函数重载     不知道返回什么就先写void        
	//通常不会利用成员函数来重载<<运算符，因为无法实现cout在左侧    本质调用时：p.operator<<(cout)  简化：p<<cout   
	/*void operator<<(ostream& cout) {
	}*/
};
//只能利用全局函数重载<<运算符
ostream& operator<<(ostream& cout, person& p)//本质：operatro<<(cout,p)  cout<<p     //cout是ostream类  且只能有一个，需要用&  传入的还是cout
{
	cout << " m_A:" << p.m_A << " m_B:" << p.m_B ;
	return cout;
}
void test01() {
	person p1(10,20);
	cout << p1<<endl;		//若返回的是void，就不能链式调用了
}
int main() {

	test01();
	system("pause");
	return 0;

}