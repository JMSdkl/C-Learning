#include <iostream>
#include<string>
using namespace std;
//�̳з�ʽ
//�����̳�
class Base1
{
public:
	int A;
protected:
	int B;
private:
	int C;


};
class son1 :public Base1
{
public:
	void func() {
		A = 10;//�����Ա����Ȩ����Ȼ�ǹ���
		B = 10;//�����Ա����Ȩ����Ȼ�Ǳ���
		//C = 10;//�����е�˽�г�Ա���ʲ���
	}

};

void test01() {
	son1 s1;
	s1.A = 100;
	//s1.B = 100;//��һ������Ȩ�����ⲻ�ܷ���
}

class base2 {
public:
	int A;
protected:
	int B;
private:
	int C;


};
class son2 :protected base2 {

public:
	void func() {
		A = 100;	//���๫���ģ�������Ϊ����
		B = 100;	//���ౣ���ģ�������Ϊ����
		//C = 100;//������ʲ���
	
	}


};

void test02(){
	son2 s2;
	//s2.A = 1000;//��������Ϊ����Ȩ��


}
class Base3
{
public:
	int A;
protected:
	int B;
private:
	int C;


};
class son3 :private Base3 {

public:
	void func() {
		A = 100;	//���๫���ģ�������Ϊ˽��
		B = 100;	//���ౣ���ģ�������Ϊ˽��
		//C = 100;//������ʲ���

	}


};

void test03() {
	son3 s3;
	//s3.A = 100;//��һ��˽��Ȩ�����ⲻ�ܷ���
	//s1.B = 100;//��һ��˽��Ȩ�����ⲻ�ܷ���
}

class grandson3 :public son3 {
public:
	void func() {
		//A = 100;//������̳в�����
	}


};
class Son :public Base1 {//�����˽�г�ԱҲ�б��̳�ֻ�Ƿ��ʲ��˶���

public:
	int m_D;

};
void test33() {
	cout << "Son �Ĵ�С" << sizeof(Son) << endl;

}


int main() {



	test33();








	system("pause");
	return 0;

}