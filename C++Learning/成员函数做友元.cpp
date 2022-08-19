#include <iostream>
#include <string>
using namespace std;
class  Building;
class  GoodGay;
//****************************类成员函数作为友元时，不能在类内编写函数，需要在类外，因为涉及到各个类成员的交叉关联*****************//
class GoodGay {
public:
	GoodGay(); /*{
			building = new Building;
		};*/
	void visit(); //{
	//		cout << "visit正在访问:" << building->m_SittingRoom << endl;
	//		cout << "visit正在访问:" << building->m_Bedroom << endl;
	//	};//让其可以访问
	void visit2();// {
	//		cout << "visit2正在访问:" << building->m_SittingRoom << endl;
	//		//cout << "visit2正在访问:" << building->m_Bedroom << endl;
	//	};//让其不可以访问
	Building* building;
};
class Building {
	friend void GoodGay::visit();//告诉编译器这是goodgay下的函数作为友元
public:
	Building() {
			m_SittingRoom="客厅";
			m_Bedroom="卧室";
		};
	string m_SittingRoom;
private:
	string m_Bedroom;
};
void GoodGay::visit() {
	cout << "visit正在访问:" << building->m_SittingRoom << endl;
	cout << "visit正在访问:" << building->m_Bedroom << endl;
}
GoodGay::GoodGay() {
	building = new Building;
}
//Building::Building() {
//	m_SittingRoom="客厅";
//	m_Bedroom="卧室";
//}
void GoodGay::visit2() {
	cout << "visit2正在访问:" << building->m_SittingRoom << endl;
	//cout << "visit2正在访问:" << building->m_Bedroom << endl;
}

void test() {
	GoodGay yy;
	yy.visit();
	yy.visit2();
}
int main() {
	test();
	system("pause");
	return 0;
}