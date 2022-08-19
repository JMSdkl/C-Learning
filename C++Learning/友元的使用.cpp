#include <iostream>
#include <string>
using namespace std;
class Buliding;
class Buliding {
	//是本类的友类，可以访问私有成员
	friend class GoodGay;
	//是buliding的友元，可以访问私有成员
	friend void goodgay(Buliding* building);
public:
	Buliding();
	~Buliding() {
		cout << "调用了buliding的析构" << endl;
	};
	string m_SittingRoom;
private:
	string m_BedRoom;
};
class GoodGay {
public:
	GoodGay() {
		//让内部的building指针来维护堆区的对象//跨类调用，一定要在堆区开辟空间

		building = new Buliding;//在堆区创建一个对象
		// Buliding dfkj;
		//building = &dfkj;//在堆区开辟对象，是要防止析构释放了默认构造函数里的初始化
		cout << "调用了无参构造函数" << endl;
	};
	~GoodGay() {
		cout << "调用了析构函数" << endl;
	}
	void visit() {
		cout << "好基友类正在访问：" << building->m_SittingRoom << endl;
		//cout << "好基友类正在访问：" << building->m_BedRoom << endl;
	};
	Buliding *building;//可以类里用类，不过这样每次都传类对象的全部数据，系统运行较慢，传指针好点
};
//类外写成员函数：
Buliding::Buliding() {
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
	cout << "调用了buliding" << endl;
}
//全局函数
void goodgay(Buliding *building) {
	cout << "好盆友的全局函数正在访问：" << building->m_SittingRoom << endl;
	cout << "好盆友的全局函数正在访问：" << building->m_BedRoom << endl;
}
void test01() {
	Buliding building;
	goodgay(&building);
}
void test02() {
	GoodGay good_gay;
	good_gay.visit();
}
int  main() {
	test02();
	system("pause");
	return 0;
}