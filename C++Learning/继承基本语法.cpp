#include <iostream>
#include<string>
using namespace std;
//ʵ����ͨҳ��

//Javaҳ��
//class Java {
//public:
//	void header() {
//		cout << "��ҳ�������Ρ���¼��ע�ᡣ��������ͷ����" << endl;
//	
//	}
//	void footer() {
//		cout << "�������ġ�����������վ�ڵ�ͼ�����������ײ���" << endl;
//
//	}
//	void left() {
//		cout << "Java��Python��C++���������������б�" << endl;
//
//	}
//	void content() {
//		cout << "Javaѧ����Ƶ" << endl;
//
//	}
//
//};
//class Python
//{
//public:
//	void header() {
//		cout << "��ҳ�������Ρ���¼��ע�ᡣ��������ͷ����" << endl;
//
//	}
//	void footer() {
//		cout << "�������ġ�����������վ�ڵ�ͼ�����������ײ���" << endl;
//
//	}
//	void left() {
//		cout << "Java��Python��C++���������������б�" << endl;
//
//	}
//	void content() {
//		cout << "Pythonѧ����Ƶ" << endl;
//
//	}
//
//};
//class Cpp
//{
//public:
//	void header() {
//		cout << "��ҳ�������Ρ���¼��ע�ᡣ��������ͷ����" << endl;
//
//	}
//	void footer() {
//		cout << "�������ġ�����������վ�ڵ�ͼ�����������ײ���" << endl;
//
//	}
//	void left() {
//		cout << "Java��Python��C++���������������б�" << endl;
//
//	}
//	void content() {
//		cout << "C++ѧ����Ƶ" << endl;
//
//	}
//
//};

//***********�̳�ʵ��ҳ��************//
class BasePage
{public:
		void header() {
		cout << "��ҳ�������Ρ���¼��ע�ᡣ��������ͷ����" << endl;

	}
	void footer() {
		cout << "�������ġ�����������վ�ڵ�ͼ�����������ײ���" << endl;

	}
	void left() {
		cout << "Java��Python��C++���������������б�" << endl;

	}
};
//�﷨��class ���ࣺ�̳з�ʽ  ����

//Javaҳ�棺
class Java :public BasePage //�̳�
{
public:
	void content()
	{
		cout << "Javaѧ�Ƶ���Ƶ" << endl;
	}


};


//Pythonҳ�棺
class Python :public BasePage //�̳�
{
public:
	void content()
	{
		cout << "Pythonѧ�Ƶ���Ƶ" << endl;
	}


};
//C++ҳ�棺
class Cpp :public BasePage //�̳�
{
public:
	void content()
	{
		cout << "Cppѧ�Ƶ���Ƶ" << endl;
	}


};

void test01() {
	cout << "Java������Ƶҳ�����£�" << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "----------------" << endl;
	cout << "Python������Ƶҳ�����£�" << endl;
	Java py;
	py.header();
	py.footer();
	py.left();
	py.content();
	cout << "----------------" << endl;
	cout << "cpp������Ƶҳ�����£�" << endl;
	Java cpp;
	cpp.header();
	cpp.footer();
	cpp.left();
	cpp.content();
}


int main() {

	test01();



	system("pause");
	return 0;

}