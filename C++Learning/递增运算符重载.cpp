#include <iostream>
#include <string>
using namespace std;
//***********************���������������**********************//
class MyInteger {
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger() {
		m_Num = 0;
	};
	//����++�����ǰ��
	MyInteger& operator++() {//����������Ϊ�˽�����ʽ���
							//������ص�����ֵ���ڶ��μ��Ǽӵ����������Ķ�������
		m_Num++;
		//�ٽ�������з���
		return *this;//�ǵ��ǽ�����
	}
	//����++���������  ��int��ֻ����int
	const MyInteger operator++(int) {//�������Ͳ�ͬ���������ص�����������Ҫ������ͬ�����ββ�ͬ
						//ռλ���������ÿ������֣�������������ǰ�úͺ��õ���
		//�� ��¼��ʱ���
		MyInteger temp = *this;
		//�� ����
		this->m_Num++;//һ��ʡ��this
		//��󽫼�¼�Ľ��������
		return temp;
	}
private:
	int m_Num;
};
//��������
ostream& operator<<(ostream& cout, MyInteger myint) {
	cout << myint.m_Num ;
	return cout;
}
void test02(){
	MyInteger myint,myint2;
		//myint2 = (myint++)++;//���ּ�ʹ����ԭ�����е�Ҳ�Ǵ����,���þ���
		myint = myint++;
		cout << myint << endl;
		cout << myint << endl;
		
}
void test01() {
	MyInteger myint;
	cout << ++(++myint) << endl;
}

int main() {
	test01();
	test02();
	size_t i = 1;
	i +=i++;
	cout << "000:" << i << endl;
	system("pause");
	return 0;


}