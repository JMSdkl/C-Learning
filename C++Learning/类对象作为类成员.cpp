#include <iostream>
#include <string>

using namespace std;
//�������Ϊ���Ա
class Phone {
public:
	Phone(string pName) {
		m_PName = pName;
		cout << "������Phone�вι��캯��" << endl;
	}
	~Phone() {
	
		cout << "������Phone����������" << endl;
	}
//private:����˽��֮��Ҫдһ������ӿڲ��ܵ���˽�г�Ա
	//�ֻ�Ʒ������
	string m_PName;
};


class person {
public:

												//Phone m_Phone=pName;//�������вι��캯������ʽת������
	person(string name, string pName) :m_Name(name),m_Phone(pName)
	{
		cout << "������person���вι��캯��" << endl;
	}
	~person() {
	
		cout << "������person����������" << endl;
	}

//private:
	//����
	string m_Name;
	//�ֻ�
	Phone m_Phone;
};
void test01() {
	person p("����", "ƻ��");
	cout << p.m_Name << "���ţ�" << p.m_Phone.m_PName << endl;
}
int main() {

	test01();




	system("pause");
	return 0;

}