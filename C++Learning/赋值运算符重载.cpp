#include <iostream>
#include <string>
using namespace std;
										//��ֵ���������
class person {
public:
	person(int age) {
		m_Age=new int(age);
	
	}
	~person() {
		if (m_Age != NULL) {
			delete m_Age;
			m_Age = NULL;
		}
	}
	//���ظ�ֵ�����
	person& operator=(person& p) {
	//�������ṩ��ǳ������m_Age=p.m_Age;
		//Ӧ�����ж��Ƿ��������ڶ������еĻ����ͷŸɾ� Ȼ�������
		if (m_Age != NULL) {
			delete m_Age;
			m_Age = NULL;
		}
		//���
		m_Age = new int(*p.m_Age);
		return *this;
	}
	int* m_Age;
};
void test01() {
	person p1(18);
	person p2(20);
	person p3(20);
	p3=p2 = p1;
	cout << "p1������Ϊ��" << *p1.m_Age << endl;
	cout << "p2������Ϊ��" << *p2.m_Age << endl;
	cout << "p3������Ϊ��" << *p3.m_Age << endl;
}
int main() {

	test01();
	//��ֵ���ϵķ������������е�

	system("pause");
	return 0;

}