#include <iostream>
#include <string>
using namespace std;

//�ڸ������麯��һ����û�õģ����Զ���Ϊ���麯��

class Base	//�д��麯���ǳ����࣬�ǲ���ʵ���������
			//��������ʵ����������Ҫ���´��麯��.����Ҳ���ڳ�����
{public:
				//���麯�����麯����ʹ��=0��
	virtual void func()=0;



};
//��Ʒ�ĳ�����

class AbstractDrinking
{
public:
	AbstractDrinking();
	~AbstractDrinking();
	//��ˮ
	virtual void Boil() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourInCup() = 0;
	//���븨��
	virtual void PutSomeThing() = 0;
	//������Ʒ
	void makeDring() 
	{
		Boil();
		Brew();
		PourInCup();
		PutSomeThing();
	}

private:

};

AbstractDrinking::AbstractDrinking()
{
}

AbstractDrinking::~AbstractDrinking()
{
}

class Coffee:public AbstractDrinking
{
public:
	virtual void Boil() 
	{
		cout << "��ũ��ɽȪ" << endl;
	};
	//����
	virtual void Brew() {
		cout << "���ݿ���" << endl;
	};
	//���뱭��
	virtual void PourInCup() {
		cout << "���뱭��" << endl;
	};
	//���븨��
	virtual void PutSomeThing() {
		cout << "�����Ǻ�ţ��" << endl;
	};


private:

};

class Tea :public AbstractDrinking
{
public:
	virtual void Boil()
	{
		cout << "���Ȫˮ" << endl;
	};
	//����
	virtual void Brew() {
		cout << "���ݲ�Ҷ" << endl;
	};
	//���뱭��
	virtual void PourInCup() {
		cout << "���뱭��" << endl;
	};
	//���븨��
	virtual void PutSomeThing() {
		cout << "��������" << endl;
	};


private:

};

void doWork(AbstractDrinking *abs)   //�β�Ϊ���࣬���յ�ʵ��Ϊ���࣬������̬    AbstractDrinking *abs=new Coffee
{	
	abs->makeDring();//���������ﴫ�������������������ֱ���ͷ�          ��̬��  һ���ӿڣ��ж�����̬
	delete abs;//�ͷţ���ֹ�ڴ�й¶
	abs = NULL;

}

void test02(){
	doWork(new Coffee);

	doWork(new Tea);
}


class Son :public Base 
{public:
	virtual void func() {
	
		cout << "func�����ĵ���" << endl;
	
	};



};

void test01(){
	Base* so = new Son;//��̬����������
	so->func();

}


int main() {

	test02();








	system("pause");
	return 0;

}