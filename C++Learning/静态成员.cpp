#include <iostream>
#include <string>
using namespace std;
class person {
public:
	person(int age) {
		this->age = age;	//�����ˣ���Ա���Ժʹ����β���Ҫ�淶
	}				//thisָ��ɽ���������
	~person() {
		cout << "����������������m_B:" << m_B << endl;
	}
	//���ж��󶼹���ͬһ������
	//����׶ξͷ����ڴ�
	//���������������ʼ������  �Ǳ���Ҫ�еĲ��������򱨴�
	static int m_A;				//Ҳ���з���Ȩ�޵�
	int age;
	person& personaddage(person& p) //��������Ҫ�ı�
	{
		this->age += p.age;//������ʽ����this ��дҲ��
		//this��ָ��p2��ָ�룬��*this�Ϳ��Խ�����ָ��p2����
		return *this;
	}
	static void func() {
		cout << "�����˾�̬��������" << endl;
	}

private:
	static int m_B;				//��̬�������������ڳ�ʼ��
	

};
int person::m_A=100;//��������person����ĳ�Ա  ͨ����������
int person::m_B=20;//������Գ�ʼ��
void test01() {						//��̬��Ա����������ĳһ�������ϣ����ж��󶼹���ͬһ������
	//person p;						//���������ַ��ʷ�ʽ��1��ͨ���������  2��ͨ����������
	//cout << p.m_A << endl;
	//person p2;
	//p2.m_A = 200;        //ͨ���������
	//cout << p.m_A << endl;
	//cout << person::m_A << endl;
	////cout << person::m_B << endl;//�����Է���
	//ͨ��������з���
	person p(18);
	p.func();
	person::func();
	cout <<"p��Ա������Ϊ��" << p.age << endl;

}

void test02() {

	person p1(10);
	person p2(10);
	p2.personaddage(p1).personaddage(p1).personaddage(p1);
	cout << "p2������Ϊ:" << p2.age << endl;

}

int main() {

	test01();
	test02();
	system("pause");
	return 0;
}