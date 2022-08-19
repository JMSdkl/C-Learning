#include "MyArray.h"
#include <iostream>
#include <string>
using namespace std;

MyArray::MyArray()
	{
		p = NULL, num = 0;
	}
MyArray::	~MyArray()
	{
		if (p) {
			delete[] p;
			p = NULL;
		}
	}

void MyArray::push(int data)
{
	int* pNew = new int[num + 1];//�����ڴ�
	if (p)
	{//���p��Ϊ��  ��ָ��һ���ֽڣ�������ָ��һ���ڴ棬����������sizeof(int) * num
		memcpy(pNew, p, sizeof(int) * num);//�����Ǹ��� ��ǰ ��������ĳ���
		delete[]p;//��ԭ��p��������ͷ�
	}
	p = pNew; //pָ���¿����ڴ�
	p[num++] = data;//�����ݴ���

}
void MyArray::travel()
{
	cout << "array: ";
	for (size_t i = 0; i < num; i++)
	{
		cout << p[i]<<" ";
	}
	cout << endl;
}