#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
	Animal();
	//�������� ���˾��ǳ�����   ��Ϊ�˽���������������Ĵ����ò���������
	virtual~Animal()=0;//��������Ҫ����ʵ�֣���������Ҳ��Ҫ����ʵ��
	//���麯��
	virtual void speak() = 0;

private:

};

Animal::Animal()
{
	cout << "���ﹹ��" << endl;
}

Animal::~Animal()
{
	cout << "��������" << endl;
} 

class Cat:public Animal
{
public:
	Cat(string name);
	~Cat();
	virtual void speak() {
		cout <<*m_Name<< "Сè��˵��" << endl;
	}
	string* m_Name;

private:

};

Cat::Cat(string name)
{
	cout << "Сè����" << endl;
	m_Name=new string(name);//�ڶ�������������
}

Cat::~Cat()
{
	if (m_Name != NULL) {
		cout << "Сè����" << endl;
		delete m_Name;
		m_Name = NULL;
	}
}

void test01(){
	Animal* animal = new Cat("Tom");
	animal->speak();
	//�����ָ��������ʱ�����������������������������������ж������Ի����й¶  �Ӹ�virtual	���������Ϳ���
	delete animal;//Ϊʲôû����delete �����в�������������
}

int main()
{



	test01();










	system("pause");
	return 0;

}