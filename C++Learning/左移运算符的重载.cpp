#include <iostream>
#include <string>
using namespace std;
//**************************���������������**************************//
class person {
	friend ostream& operator<<(ostream& cout, person& p);
public:
	person(int a, int b) {
		m_A = a;
		m_B = b;
	}
private:
	int m_A;
	int m_B;
	//���ó�Ա��������     ��֪������ʲô����дvoid        
	//ͨ���������ó�Ա����������<<���������Ϊ�޷�ʵ��cout�����    ���ʵ���ʱ��p.operator<<(cout)  �򻯣�p<<cout   
	/*void operator<<(ostream& cout) {
	}*/
};
//ֻ������ȫ�ֺ�������<<�����
ostream& operator<<(ostream& cout, person& p)//���ʣ�operatro<<(cout,p)  cout<<p     //cout��ostream��  ��ֻ����һ������Ҫ��&  ����Ļ���cout
{
	cout << " m_A:" << p.m_A << " m_B:" << p.m_B ;
	return cout;
}
void test01() {
	person p1(10,20);
	cout << p1<<endl;		//�����ص���void���Ͳ�����ʽ������
}
int main() {

	test01();
	system("pause");
	return 0;

}