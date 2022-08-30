#pragma once
//�Լ�ͨ�õ�������
#include<iostream>
using namespace std;
template<class T>
class MyArray
{
public:
	MyArray(int capacity)//����
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
		//cout << "�вι��캯���ĵ���" << endl;
	}
	//��������
	MyArray(const MyArray& arr)
	{
		//cout << "�������캯���ĵ���" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//this->pAddress = arr.pAddress;//ֱ�Ӹ�ֵ�ᵼ��ǳ����������
		//���
		this->pAddress = new T[arr.m_Capacity];
		//��arr�е����ݿ�������
		for (size_t i = 0; i < this->m_Size; i++) 
		{
			this->pAddress[i] = arr.pAddress[i];
		
		}
	}
	//operator=Ҳ���Է�ֹǳ����������
	MyArray& operator=(const MyArray& arr)
	{
		//cout << "MyArray& operator=�ĵ���" << endl;
		//���ж�ԭ�������Ƿ������ݣ���������ͷ�
		if (this->pAddress != NULL)
		{
			delete[]this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
	//���
		this->m_Size = arr.m_Size;
		this->m_Capacity = arr.m_Capacity;
		this->pAddress = new T[arr.m_Capacity];
		for (size_t i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];//����������ݿ�����

		}
		return *this;
	}

	//β�巨
	void Push_Back(const T &val) 
	{
	//�ж������Ƿ���ڴ�С
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;//������ĩβ��������
		this->m_Size++;//���������С
	}
	//βɾ��
	void Pop_Back() 
	{
		//���û����ʲ������һ��Ԫ�أ���Ϊβɾ���߼�ɾ��
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}
	//ͨ���±�����������  arr[0]=100
	T& operator[](int index) //������������Ϊ��ֵ���ã�Ҫ�Ӹ����ã��������ò��ܶԱ����������Ȼ���Ƕ���ʱ��������
	{
		return this->pAddress[index];
	}
	//�������������
	int getCapacity() 
	{
		return this->m_Capacity;
	}
	//��������Ĵ�С
	int getSize() 
	{
		return this->m_Size;
	}

	//����
	~MyArray() 
	{
		if (this->pAddress != NULL) 
		{
		//cout << "���������ĵ���" << endl;
			delete[]this->pAddress;
			this->pAddress = NULL;
		}
	}
	
private:
	T* pAddress;//ָ��ָ�������ʵ���ٵ�����
	int m_Capacity;//��������
	int m_Size;//�����С
};