#include<iostream>
#include<string>
using namespace std;

void MyPrint(int a,int b) 
{
	cout << "��������ͨ����" << endl;
}
template<class T>
void MyPrint(T a, T b) 
{
	cout << "���ú���ģ��" << endl;
}
template<class T>
void MyPrint(T a, T b,T c)
{
	cout << "�������صĺ���ģ��" << endl;
}

void test01() 
{
	int a = 10;
	int b = 20;
	//MyPrint(a, b);
	//ͨ����ģ��ǿ�Ƶ��ú���ģ��
	//MyPrint<>(a, b);
	//MyPrint<>(a, b,a);
	//���ģ��������õ�ƥ�����ȵ���ģ��
	char c = 'a';
	char d = 'b';
	MyPrint(c, d);//��Ϊ����Ĭ�ϵĺ���Ҫ����һ��ת����������ģ��ֱ���Ƶ����ͼ���
	
}

int main() 
{
	test01();

	system("pause");
	return 0;
}