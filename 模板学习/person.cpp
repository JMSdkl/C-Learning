#include<iostream>
#include<string>

using namespace std;
template<class T1,class T2>
class Person;				//���ñ�����֪��person�����

//����ʵ��                  //���ȫ�ֺ���������ʵ�֣���Ҫ�ñ�������ǰ֪����������Ĵ���
template<class T1,class T2>//ʵ��ʱȴ��ģ���ʵ�֣���Ҫ��������ӿ�ģ��Ĳ����б�
void printPerson2(Person<T1, T2> p)//���ü���������Ϊ��ȫ�ֺ��� 
{
	cout << "������" << p.name << " " << "���䣺" << p.age << endl;
}
//ͨ��ȫ�ֺ�����ӡperson��Ϣ
template<class T1,class T2>
class Person
{	//ȫ�ֺ�������ʵ��
	friend void printPerson(Person<T1,T2> p)
	{
		cout << "������" << p.name << " " << "���䣺" << p.age << endl;
	}
	//ȫ�ֺ�������ʵ��
	friend void printPerson2<>(Person<T1, T2> p);//����ʱ����ͨ����������
	
public:
	Person(T1 name, T2 age) 
	{
		this->name = name;
		this->age = age;
	}

private:
	T1 name;
	T2 age;


};


//ȫ�ֺ���������ʵ��
void test01() 
{
	Person<string,int> p1("����",12);
	printPerson(p1);

}

//ȫ�ֺ���������ʵ�ֵĵ��ò���
void test02() 
{
	Person<string, int>p2("����",50);
	printPerson2(p2);
}

int main() 
{
	//test01();
	test02();
	system("pause");
}