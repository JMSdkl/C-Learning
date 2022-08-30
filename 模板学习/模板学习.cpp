#include<iostream>
#include<string>
using namespace std;


//**************���ͱ��˼�룺����ģ�塢��ģ��****************//

//�������ͽ����ĺ�����
void swapInt(int &a,int &b) 
{
	int temp = a;
	a = b;
	b = temp;
}
//�������������͵ĺ���
void swapDouble(double& a, double& b) 
{
	double temp = a;
	a = b;
	b = temp;
}
//����ģ��typename ��class����
template<typename T>//����һ��ģ�壬���߱�������������н�����T��Ҫ����
void mySwap(T& a, T& b) 
{
	T temp = a;
	a = b;
	b = temp;
}

//template<typename T>
//void func() 
//{
//	cout << "funcʹ��" << endl;		 //�����������ֻ��ʹ��ָ���������Ͳ��ܵ���
//									//func<int>();
//}

void test01() 
{
	int a = 10;
	int b = 20;;
	//swapInt(a, b);
	//���ú���ģ��
	//���ַ�ʽʹ�ú���ģ��
	//1���Զ������Ƶ�
	//2����ʾָ������
	mySwap(a, b);//1���Զ������Ƶ�
	mySwap<int>(a, b);//2����ʾָ������
	cout << "a:" << a << " " << "b: " << b << endl;
}

int main() 
{

	test01();
	system("pause");
	return 0;
}