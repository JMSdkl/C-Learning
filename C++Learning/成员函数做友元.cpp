#include <iostream>
#include <string>
using namespace std;
class  Building;
class  GoodGay;
//****************************���Ա������Ϊ��Ԫʱ�����������ڱ�д��������Ҫ�����⣬��Ϊ�漰���������Ա�Ľ������*****************//
class GoodGay {
public:
	GoodGay(); /*{
			building = new Building;
		};*/
	void visit(); //{
	//		cout << "visit���ڷ���:" << building->m_SittingRoom << endl;
	//		cout << "visit���ڷ���:" << building->m_Bedroom << endl;
	//	};//������Է���
	void visit2();// {
	//		cout << "visit2���ڷ���:" << building->m_SittingRoom << endl;
	//		//cout << "visit2���ڷ���:" << building->m_Bedroom << endl;
	//	};//���䲻���Է���
	Building* building;
};
class Building {
	friend void GoodGay::visit();//���߱���������goodgay�µĺ�����Ϊ��Ԫ
public:
	Building() {
			m_SittingRoom="����";
			m_Bedroom="����";
		};
	string m_SittingRoom;
private:
	string m_Bedroom;
};
void GoodGay::visit() {
	cout << "visit���ڷ���:" << building->m_SittingRoom << endl;
	cout << "visit���ڷ���:" << building->m_Bedroom << endl;
}
GoodGay::GoodGay() {
	building = new Building;
}
//Building::Building() {
//	m_SittingRoom="����";
//	m_Bedroom="����";
//}
void GoodGay::visit2() {
	cout << "visit2���ڷ���:" << building->m_SittingRoom << endl;
	//cout << "visit2���ڷ���:" << building->m_Bedroom << endl;
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