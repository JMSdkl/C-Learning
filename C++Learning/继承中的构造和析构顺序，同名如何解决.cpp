#include <iostream>
#include<string>
using namespace std;

class Base {
public:
	Base() {
		m_A = 100;
		cout << "base�Ĺ��캯��" << endl;
	}
	~Base() {
		cout << "base����������" << endl;
	
	}
	int m_A;
	static int m_B;
	 void func() {
		cout << "base���st����" << endl;
	}
	static void func(int r) {
		cout << "base���st func(int r)����" << endl;
	}
};
int Base::m_B=100;

class son :public Base {
public:
	son() {
		m_A = 200;
		cout << "son�Ĺ��캯��" << endl;
	}
	~son() {
		cout << "son����������" << endl;

	}
	int m_A;
	static int m_B;
	static void func() {
		cout << "Son���st ����" << endl;
	}

};
int son::m_B = 200;

void test01() {
	son s1;//ֱ�ӷ��ʾ��Ƿ��������
	cout<<"Son ��m_A:" << s1.m_A << endl;
	//���Ҫ���ʸ������Ҫ��������
	cout << "Base ��m_A:" << s1.Base::m_A << endl;

}
void test02() {
	son s2;
	s2.func();
	s2.Base::func();//�������Ƽ�����������Ƿ��ʸ�����ĺ���

	//��������г��ֺ͸���ͬ���ĳ�Ա�����������ͬ����Ա�����ص�����������ͬ����Ա����
	//�������ʸ���ͬ���ĳ�Ա��������������
	s2.Base::func(100);
}

void test03() {
	//1:ͨ������������
	son s3;
	cout << "Son�µ� m_B:" << s3.m_B << endl;
	cout << "Base�µ� m_B:" << s3.Base::m_B << endl;
	//2��ͨ������������
	cout << "Son�µ� m_B:" << son::m_B << endl;
	//��һ����������ͨ��������ʽ���ʣ��ڶ�������������ʸ�����������
	cout << "Base�µ� m_B:" << son::Base::m_B << endl;

}
void test04() {

	son s;
	s.func();
	s.Base::func();
	s.Base::func(10);

	son::func();//
	//son::Base::func();//�ò��˵�ԭ���ǷǾ�̬��ԱҪ�ö��������ã��ڸ���funcǰ��static����

}


//˳���ȹ��츸�������࣬�����빹���෴

int main() {

	//test01();
	//test02();
	//test03();
	test04();
	system("pause");
	return 0;

}