#include <iostream>
#include <string>
using namespace std;

class Animal
{public:
	virtual void speak() {
		cout << "������˵��" << endl;
	}
};
class cat:public Animal
{public:
	virtual void speak() {
		cout << "Сè��˵��" << endl;
	}
};
class Dog :public Animal
{
public:
	void speak() {
		cout << "С����˵��" << endl;
	}
};
//��ַ���,�ڱ���׶ξ�ȷ��������ַ
//�����ִ����è˵������ô��������ĵ�ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ΰ󶨡����������(�����virtual)

//��̬��̬����������
//1���м̳й�ϵ
//2����������Ҫ��д������麯����������virtual�ؼ��ֿ�д�ɲ�д��

//��̬��̬ʹ��
//�����ָ��������� ָ���������

void DoSpeak(Animal& animal) {//����������ڽ���������� ������
	
	animal.speak();//��������ĵ�ַ������ǰȷ��������Ҫ�����е��˲�֪��


}
void test01() {
	cat ct;
	DoSpeak(ct);

	Dog dog;
	DoSpeak(dog);

}

void test02(){
	cout << "sizeof Animal=" << sizeof(Animal) << endl;

}

int main() {


	//test01();
	test02();//�����С��һ������virtual����4��,4�ֽ���һ��ָ�루ʲô����ָ�붼��4�ֽڣ�

	system("pause");
	return 0;

}