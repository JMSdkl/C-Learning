#include<iostream>
#include<string>
using namespace std;
class MyPrint {
public:
	//���غ������������
	void operator()(string test) {
		cout << test << endl;
	}
};
void MyPrint02(string test) {
	cout << test << endl;
}
//�º�������ͨ�������������ǣ�ͨ����������
void test01() {
	MyPrint myPrint;
	myPrint("hello world");//���غ������������
						//����ʹ�������ǳ��������ã����Գ�Ϊ�º���
	MyPrint02("hello world");//��������
}
//�º����ǳ���û�й̶�д��
//�ӷ���
class MyAdd {
public:
	int operator()(int num1,int num2) {
		return num1 + num2;
	}
};
void test02() {
	MyAdd myadd;
	int ret=myadd(100, 255);
	cout << ret << endl;
	//������������
	cout << MyAdd()(100, 100) << endl;//MyAdd()������һ����������ʹ����ͻᱻ�ͷ�
}
int main() {
	test01();
	test02();
	system("pause");
	return 0;
}