#include <iostream>
#include <string>
using namespace std;

//������
class Animal
{
public:
	Animal();
	~Animal();
	int m_age;
private:

};

Animal::Animal()
{
}

Animal::~Animal()
{
}
class Sheep :virtual public Animal {
};
class TUO :virtual public Animal {
};
class SheepTUO :public Sheep, public TUO {
};
void test01() {
	SheepTUO st;
	st.Sheep::m_age = 18;
	st.TUO::m_age = 39;
	st.m_age = 50;
	//�������μ̳�ʱ�����������������
	cout << "����̳е�age:" << st.Sheep::m_age << endl;
	cout << "���ռ̳е�age:" << st.TUO::m_age << endl;
	//�������ֻҪ��һ�ݾͿ����ˣ����μ̳е������������ݣ�������Դ�˷�
	//������̳п��Խ���������  ����virtual
	//Animal��Ϊ�����
}


int main() {

	test01();





	system("pause");
	return 0;

}