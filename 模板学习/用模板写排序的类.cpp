#include<iostream>
#include<string>
using namespace std;

//ʵ��ͨ�� �������������

//������㷨��
template<class T>
void MySwap(T& a, T& b) 
{
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
void MySort(T arr[],int len) 
{
	for (size_t i = 0; i < len; i++) 
	{
		int max = i;//�϶�һ�����ֵ
		
		for (size_t j = i + 1 ; j < len; j++)
		{
			if (arr[max] < arr[j])//�϶������ֵ�����е�С 
			{
				max = j;//�������ֵ���±�
			}
		}
		if (max != i) 
		{
			MySwap(arr[max], arr[i]);
		}
	}
}
//�ṩ��ӡ�����ģ��
template<class T>
void PrintArray(T arr[],int len) 
{
	for (size_t i = 0; i < len; i++) {
		cout << arr[i] ;
	}
	cout << endl;
}

void test01() 
{
	//����char��������
	char charArr[] = "badcfe";
	int num = (sizeof(charArr) / sizeof(char))-1;//char���͵�����һ  ��Ϊ\0��һ���ַ�
	PrintArray(charArr, num);
	MySort(charArr, num);
	PrintArray(charArr, num);
}

void test02()
{
	//����char��������
	int charArr[] = { 7,8,1,3,9,6,5,2 };
	int num = (sizeof(charArr) / sizeof(int));//char���͵�����һ
	PrintArray(charArr, num);
	MySort(charArr, num);
	PrintArray(charArr, num);
}

int main() 
{
	test01();
	test02();
	system("pause");
	return 0;
}