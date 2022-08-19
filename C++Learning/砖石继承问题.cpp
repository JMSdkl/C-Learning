#include <iostream>
#include <string>
using namespace std;

//动物类
class Animal
{
public:
	Animal();
	~Animal();
	int m_age;
private:

};

Animal::Animal()
{
}

Animal::~Animal()
{
}
class Sheep :virtual public Animal {
};
class TUO :virtual public Animal {
};
class SheepTUO :public Sheep, public TUO {
};
void test01() {
	SheepTUO st;
	st.Sheep::m_age = 18;
	st.TUO::m_age = 39;
	st.m_age = 50;
	//当在菱形继承时，需加以作用域区分
	cout << "在羊继承的age:" << st.Sheep::m_age << endl;
	cout << "在驼继承的age:" << st.TUO::m_age << endl;
	//这份数据只要有一份就可以了，菱形继承导致数据有两份，导致资源浪费
	//利用虚继承可以解决这个问题  加上virtual
	//Animal称为虚基类
}


int main() {

	test01();





	system("pause");
	return 0;

}