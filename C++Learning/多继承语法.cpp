#include <iostream>
#include <string>
using namespace std;

//������ʹ�ö�̳�
//�������г���ͬ���ĳ�Ա��Ҫ��������

class Base1 {
public:
	Base1() {
		m_A = 100;
	}
	int m_A;

};

class Base2 {
public:
	Base2() {
		m_B = 200;
	}
	int m_B;

};
//�������г���ͬ���ĳ�Ա��Ҫ��������
class son :public Base1, public Base2 {  //���ŷָ����
public:
	son() {
		m_C = 300;
	}
	int m_C;

};

void test01(){
	son s1;
	cout << "s1ռ�Ŀռ�" << sizeof(s1) << endl;
}

int main() {

	test01();




	system("pause");
	return 0;

}