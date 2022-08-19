#include <string>
#include <iostream>
#include "workerManager.h"

using namespace std;

workerManager::workerManager() 
{
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;
}

workerManager::~workerManager() 
{
	if (this->m_EmpArray != NULL) 
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

void workerManager::Show_Menu() 
{
	cout << "***********************************************" << endl;
	cout << "*************��ӭʹ��ְ������ϵͳ**************" << endl;
	cout << "***************0.�˳��������******************" << endl;
	cout << "***************1.����ְ����Ϣ******************" << endl;
	cout << "***************2.��ʾְ����Ϣ******************" << endl;
	cout << "***************3.ɾ����ְְ��******************" << endl;
	cout << "***************4.�޸�ְ����Ϣ******************" << endl;
	cout << "***************5.����ְ����Ϣ******************" << endl;
	cout << "***************6.���ձ������******************" << endl;
	cout << "***************7.��������ĵ�******************" << endl;
	cout << "***********************************************" << endl;
	cout << endl;
}
void workerManager::exitsSystem() 
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);//�˳������õ�
}
void workerManager::AddEmp() 
{
	cout << "���������ְ����������" << endl;
	int addNum = 0;//�����û�����������
	cin >> addNum;
	if (addNum > 0) 
	{	//���
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;//�¿ռ�����=ԭ����¼������+��������
		//�����¿ռ�
		Worker ** newSpace=new Worker* [newSize];
		//��ԭ���ռ��µ����ݣ��������¿ռ���
		if (this->m_EmpArray != NULL) 
		{
			for (int i = 0; i < this->m_EmpNum; i++) 
			{
				newSpace[i] = this->m_EmpArray[i]; //�����ָ��
			}
		}
		//�������������
		for (int i = 0; i < addNum; i++) 
		{
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//����ѡ��
			cout << "�������" << i + 1 << "����ְ�����" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ������" << endl;
			cin >> name;
			cout <<  "��ѡ���ְ����λ���" << endl;
			cout << "1:��ְͨ��" << endl;
			cout << "2:����" << endl;
			cout << "3:�ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new employee(id,name,1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
			case 3:
				worker = new Boss(id, name, 3);

			default:
				break;
			}
			//��������ְ��ָ�룬���浽������
			newSpace[this->m_EmpNum + i] = worker;
		
		}
		//�ͷ�ԭ�еĿռ�
		delete[] this->m_EmpArray;
		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;
		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//�ɹ���Ӻ�Ӧ��Ҫ���浽�ļ���

		this->save();
		//������
		cout << "�ɹ����" << addNum << "����ְ��" << endl;

	}
	else
	{
		cout << "������������" << endl;
	}
	//��������������ҷ�����һĿ¼
	system("pause");
	system("cls");

}

void workerManager::save() 
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ� --д�ļ�
	//��ÿ��������д�뵽�ļ���
	for (size_t i=0; i < this->m_EmpNum; i++) 
	{
		ofs << this->m_EmpArray[i]->m_Id << "  " << this->m_EmpArray[i]->m_Name << "  " << this->m_EmpArray[i]->m_DeptId << endl;
		             //m_EmpArray[i]��һ��������ˣ�����ʹ������ĳ�Ա
	}
	ofs.close();




}