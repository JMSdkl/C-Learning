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
		arr1.Push_Back(i);//����β�巨�������в�������
	}
	cout << "array1�Ĵ�ӡ���Ϊ��" << endl;
	printIntArray(arr1);
	cout << arr1.getCapacity() <<" " << arr1.getSize() << endl;
	MyArray<int> arr2(arr1);
	cout << "array2�Ĵ�ӡ���Ϊ��" << endl;
	printIntArray(arr2);
	//βɾ
	arr2.Pop_Back();
	cout << "array2�Ĵ�ӡ���Ϊ��" << endl;
	printIntArray(arr2);
	cout << "βɾ��" << endl;
	cout << arr2.getCapacity() << " " << arr2.getSize() << endl;
}
//�����Զ������������
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
		cout << "������" << arr[i].Name << "���䣺" << arr[i].age << endl;
	}
}
void test02() 
{
	MyArray<Person>arr(10);
	Person p1("����", 110);
	Person p2("����", 53);
	Person p3("��2��", 33);
	Person p4("��3��", 23);
	Person p5("��4��", 13);
	//�����ݲ��뵽������
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);
	//��ӡ����
	printPersonArray(arr);
	//��������
	cout << "arr������Ϊ��" << arr.getCapacity() << endl;
	//�����С
	cout << "arr��СΪ��" << arr.getSize() << endl;
}
int main() 
{
	test02();
	system("pause");
	return 0;

}