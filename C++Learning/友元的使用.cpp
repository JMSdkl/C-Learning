#include <iostream>
#include <string>
using namespace std;
class Buliding;
class Buliding {
	//�Ǳ�������࣬���Է���˽�г�Ա
	friend class GoodGay;
	//��buliding����Ԫ�����Է���˽�г�Ա
	friend void goodgay(Buliding* building);
public:
	Buliding();
	~Buliding() {
		cout << "������buliding������" << endl;
	};
	string m_SittingRoom;
private:
	string m_BedRoom;
};
class GoodGay {
public:
	GoodGay() {
		//���ڲ���buildingָ����ά�������Ķ���//������ã�һ��Ҫ�ڶ������ٿռ�

		building = new Buliding;//�ڶ�������һ������
		// Buliding dfkj;
		//building = &dfkj;//�ڶ������ٶ�����Ҫ��ֹ�����ͷ���Ĭ�Ϲ��캯����ĳ�ʼ��
		cout << "�������޲ι��캯��" << endl;
	};
	~GoodGay() {
		cout << "��������������" << endl;
	}
	void visit() {
		cout << "�û��������ڷ��ʣ�" << building->m_SittingRoom << endl;
		//cout << "�û��������ڷ��ʣ�" << building->m_BedRoom << endl;
	};
	Buliding *building;//�����������࣬��������ÿ�ζ���������ȫ�����ݣ�ϵͳ���н�������ָ��õ�
};
//����д��Ա������
Buliding::Buliding() {
	m_SittingRoom = "����";
	m_BedRoom = "����";
	cout << "������buliding" << endl;
}
//ȫ�ֺ���
void goodgay(Buliding *building) {
	cout << "�����ѵ�ȫ�ֺ������ڷ��ʣ�" << building->m_SittingRoom << endl;
	cout << "�����ѵ�ȫ�ֺ������ڷ��ʣ�" << building->m_BedRoom << endl;
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