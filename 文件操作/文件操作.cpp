#include <iostream> //���˷��ͣ���Ҫ�����ж���������ͷ�ļ�����
#include <string>
#include <fstream>

using namespace std;
//�ı��ļ�  д�ļ�
void test01() 
{	//1.����ͷ�ļ�
	//2.����������
	ofstream ofs;
	//3.ָ���򿪷�ʽ
	ofs.open("test.txt", ios::out);//��д��ϸ·����Ĭ������Ŀ����
	//4.д����
	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺18" << endl;
	//5.�ر�
	ofs.close();

}
//�ı��ļ���  ���ļ�
void test02() 
{	//1:����ͷ�ļ�
	//2:����������
	ifstream ifs;
	//3�����ļ������ж��Ƿ��
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()) 
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//4��������
	////��һ��
	//char buf[1024] = { 0 };
	//while (ifs>>buf)
	//{
	//	cout << buf << endl;
	//}
	// �ڶ���
	/*char buf[1024] = { 0 };
	while (ifs.getline(buf,sizeof(buf)))
	{
		cout << buf << endl;
	}*/
	////������
	//string buf;
	//while (getline(ifs,buf))
	//{
	//	cout << buf << endl;
	//}
	//������
	//char c;
	//while ((c=ifs.get())!=EOF)//EOF��ָ�ļ�β  .get()��һ������ȡ
	//{
	//	cout << c;
	//}
	//5���ر�
	
	ifs.close();
}
//������д�ļ�
class Person 
{public:
	char m_Name[64];
	int m_Age;

};

void test03()
{
	ofstream ofs;
	ofs.open("person.txt", ios::out | ios::binary);//�Ѷ����Ƶķ�ʽд
	Person p = { "����",18 };
	ofs.write((const char*)&p, sizeof(Person));
	ofs.close();
}
void test04() 
{
	//1:����ͷ�ļ�
	//2������������
	ifstream ifs;
	//3�����ļ����ж��Ƿ�򿪳ɹ�
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open()) 
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//4:���ļ�
	Person p;
	ifs.read((char*)&p, sizeof(Person));//��Ϊread���÷�������Ҫ����һ����ַ������Ҫ��&p�����������ǣ�char *������Ҫǿת
	cout << "������" << p.m_Name << " ���䣺" << p.m_Age << endl;
	//5���ر��ļ�

}
int main() 
{
	//test02();
	test04();
	system("pause");
	return 0;

}