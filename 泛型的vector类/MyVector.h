#pragma once
#include <iostream> //用了泛型，需要把所有东西都放在头文件里面
#include <string>
using namespace std;

template<class T>
class MyArray {
public:              //类模板可以不用特殊的类型了：int、doubt等
					//可以智能的识别各种类型
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
	T* pNew = new T[num + 1];//分配内存
	if (p)
	{//如果p不为空  是指向一个字节，而不是指向一段内存，所以下面是sizeof(int) * num
		memcpy(pNew, p, sizeof(T) * num);//第三是复制 当前 存在数组的长度
		delete[]p;//把原来p里的内容释放
	}
	p = pNew; //p指向新开的内存
	p[num++] = data;//将数据传入

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
