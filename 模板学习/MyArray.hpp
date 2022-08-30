#pragma once
//自己通用的数组类
#include<iostream>
using namespace std;
template<class T>
class MyArray
{
public:
	MyArray(int capacity)//容量
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
		//cout << "有参构造函数的调用" << endl;
	}
	//拷贝构造
	MyArray(const MyArray& arr)
	{
		//cout << "拷贝构造函数的调用" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//this->pAddress = arr.pAddress;//直接赋值会导致浅拷贝的问题
		//深拷贝
		this->pAddress = new T[arr.m_Capacity];
		//将arr中的数据拷贝过来
		for (size_t i = 0; i < this->m_Size; i++) 
		{
			this->pAddress[i] = arr.pAddress[i];
		
		}
	}
	//operator=也可以防止浅拷贝的问题
	MyArray& operator=(const MyArray& arr)
	{
		//cout << "MyArray& operator=的调用" << endl;
		//先判断原来堆区是否有数据，如果有先释放
		if (this->pAddress != NULL)
		{
			delete[]this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
	//深拷贝
		this->m_Size = arr.m_Size;
		this->m_Capacity = arr.m_Capacity;
		this->pAddress = new T[arr.m_Capacity];
		for (size_t i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];//把数组的数据拷过来

		}
		return *this;
	}

	//尾插法
	void Push_Back(const T &val) 
	{
	//判断容量是否等于大小
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;//在数组末尾插入数据
		this->m_Size++;//更新数组大小
	}
	//尾删法
	void Pop_Back() 
	{
		//让用户访问不到最后一个元素，即为尾删，逻辑删除
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}
	//通过下标来访问数据  arr[0]=100
	T& operator[](int index) //函数调用想作为左值调用，要加个引用，加了引用才能对本体操作，不然就是对临时变量操作
	{
		return this->pAddress[index];
	}
	//返回数组的容量
	int getCapacity() 
	{
		return this->m_Capacity;
	}
	//返回数组的大小
	int getSize() 
	{
		return this->m_Size;
	}

	//析构
	~MyArray() 
	{
		if (this->pAddress != NULL) 
		{
		//cout << "析构函数的调用" << endl;
			delete[]this->pAddress;
			this->pAddress = NULL;
		}
	}
	
private:
	T* pAddress;//指针指向堆区真实开辟的数组
	int m_Capacity;//数组容量
	int m_Size;//数组大小
};