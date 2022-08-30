#include<iostream>
#include<string>
using namespace std;

//实现通用 对数组进行排序

//排序的算法：
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
		int max = i;//认定一个最大值
		
		for (size_t j = i + 1 ; j < len; j++)
		{
			if (arr[max] < arr[j])//认定的最大值比现有的小 
			{
				max = j;//更新最大值的下标
			}
		}
		if (max != i) 
		{
			MySwap(arr[max], arr[i]);
		}
	}
}
//提供打印数组的模板
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
	//测试char数组排序
	char charArr[] = "badcfe";
	int num = (sizeof(charArr) / sizeof(char))-1;//char类型的最后减一  因为\0是一个字符
	PrintArray(charArr, num);
	MySort(charArr, num);
	PrintArray(charArr, num);
}

void test02()
{
	//测试char数组排序
	int charArr[] = { 7,8,1,3,9,6,5,2 };
	int num = (sizeof(charArr) / sizeof(int));//char类型的最后减一
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