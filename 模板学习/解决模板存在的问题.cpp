#include<iostream>
#include<string>
using namespace std;

//ģ��ľ�����
class person 
{public:
	person(string name, int age) 
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

template<class T>
bool myCompare(T& a, T& b) 
{
	if (a == b) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

//���þ��廯��person�汾ʵ�ִ��룬���廯���ȵ���
template<>bool myCompare(person& p1, person& p2) //ר�Ŵ���person��ʵ��
{
	if (p1.name == p2.name && p1.age == p2.age) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test01() 
{
	int a = 10;
	int b = 20;
	bool ret = myCompare(a, b);
	if (ret == 1) 
	{
		cout << "����" << endl;
	}
	else
	{
		cout << "����" << endl;
	}
}

void test02() 
{
	person A("tom", 10);
	person B("tom", 20);
	bool ret = myCompare(A, B);//������ֵ��Ҫ�������������
	if (ret == 1)
	{
		cout << "����" << endl;
	}
	else
	{
		cout << "����" << endl;
	}
}

int main() 
{
	test02();

	system("pause");
	return 0;
}