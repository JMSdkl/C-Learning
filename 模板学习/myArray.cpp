#include<iostream>
#include<string>
#include"MyArray.hpp"
using namespace std;
void printIntArray(MyArray<int> arr)
{
	for (size_t i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}
void test01() 
{
	MyArray<int> arr1(5);
	//MyArray<int> arr2(arr1);
	//MyArray<int>arr3(100);
	//arr3 = arr1;
	for (size_t i = 0; i < 5; i++) 
	{
		arr1.Push_Back(i);//利用尾插法向数组中插入数据
	}
	cout << "array1的打印输出为：" << endl;
	printIntArray(arr1);
	cout << arr1.getCapacity() <<" " << arr1.getSize() << endl;
	MyArray<int> arr2(arr1);
	cout << "array2的打印输出为：" << endl;
	printIntArray(arr2);
	//尾删
	arr2.Pop_Back();
	cout << "array2的打印输出为：" << endl;
	printIntArray(arr2);
	cout << "尾删后：" << endl;
	cout << arr2.getCapacity() << " " << arr2.getSize() << endl;
}
//测试自定义的数据类型
class Person
{
public:
	Person() {};
	Person(string name, int age) 
	{
		this->Name = name;
		this->age = age;
	}
	string Name;
	int age;

};
void printPersonArray(MyArray<Person>&arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "姓名：" << arr[i].Name << "年龄：" << arr[i].age << endl;
	}
}
void test02() 
{
	MyArray<Person>arr(10);
	Person p1("张三", 110);
	Person p2("赵四", 53);
	Person p3("赵2四", 33);
	Person p4("赵3四", 23);
	Person p5("赵4四", 13);
	//将数据插入到数组中
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);
	//打印数据
	printPersonArray(arr);
	//输入容量
	cout << "arr的容量为：" << arr.getCapacity() << endl;
	//输入大小
	cout << "arr大小为：" << arr.getSize() << endl;
}
int main() 
{
	test02();
	system("pause");
	return 0;

}