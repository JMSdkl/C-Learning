#pragma once
#include <iostream> //���˷��ͣ���Ҫ�����ж���������ͷ�ļ�����
#include <string>
using namespace std;

template<class T>
class MyArray {
public:              //��ģ����Բ�������������ˣ�int��doubt��
					//�������ܵ�ʶ���������
	MyArray() {
		p = NULL, num = 0;
	};
	~MyArray() {
		if (p) {
			delete[] p;
			p = NULL;
		}
	};
	void push(const T& data);
	void travel();
private:
	T* p;
	int num;
};

template<class T>
void MyArray<T>::push(const T& data)
{
	T* pNew = new T[num + 1];//�����ڴ�
	if (p)
	{//���p��Ϊ��  ��ָ��һ���ֽڣ�������ָ��һ���ڴ棬����������sizeof(int) * num
		memcpy(pNew, p, sizeof(T) * num);//�����Ǹ��� ��ǰ ��������ĳ���
		delete[]p;//��ԭ��p��������ͷ�
	}
	p = pNew; //pָ���¿����ڴ�
	p[num++] = data;//�����ݴ���

}
template<class T>
void MyArray<T>::travel()
{
	cout << "array: ";
	for (size_t i = 0; i < num; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
}
