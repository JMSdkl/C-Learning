#include <string>
#include <iostream>
#include "workerManager.h"

using namespace std;

workerManager::workerManager() 
{

	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) 
	{
		cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;//Ա������Ϊ0
		this->m_EmpArray = NULL;//Ա��ָ��Ϊ��
		this->m_FileIsEmpty = true;//�ļ�������
		ifs.close();
		return;
	}
	//�ļ����ڣ���������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) 
	{
		//�ļ�Ϊ��
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;//Ա������Ϊ0
		this->m_EmpArray = NULL;//Ա��ָ��Ϊ��
		this->m_FileIsEmpty = true;//�ļ�������
		ifs.close();
		return;

	}
	//�ļ����ڣ����Ҽ�¼����
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ�� " << num << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];//������i����Ա��ָ������
	//���ļ��е����ݴ浽������
	this->init_Emp();
	/*for (int i = 0; i < this->m_EmpNum; i++) 
	{
		cout << "ְ�����: " << this->m_EmpArray[i]->m_Id
			<<" " << "����: " << this->m_EmpArray[i]->m_Name
			<<" " << "���ű��: " << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
	

}

workerManager::~workerManager() 
{
	if (this->m_EmpArray != NULL)
	{
		//ɾ��������ÿ������
		for (size_t i = 0; i < this->m_EmpNum; i++)
		{
			delete this->m_EmpArray[i];
			this->m_EmpArray[i] = NULL;//�����ÿ�
		}
		//ɾ����������ָ��
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
			for (size_t j = 0; j < this->m_EmpNum; j++) //��ֹ����һֱ�����ظ���id
			{											//�о���ҪǶ��һ�����Է��ز������ĺ���
														//Ȼ����һ��whileѭ��
				if (id == this->m_EmpArray[j]->m_Id)	//ֻҪ������if������һ��Ҫ���벻ͬ��id
				{ 
					cout << "�������ظ���id��" << endl;
					cout<<"�����������"<< i + 1 << "����ְ�����" << endl;
					cin >> id;
					break;                              //��ֹ������
				}
			}
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
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;

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

		this->m_FileIsEmpty = false;//�ɹ����ְ�����ļ��Ͳ�Ϊ��

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

int  workerManager::get_EmpNum() 
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�   ��
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs>>id&&ifs>>name&&ifs>>did)
	{
		//ͳ������
		num++;
	}
	ifs.close();
	return num;
}

//��ʼ��Ա��
void workerManager::init_Emp() 
{	
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs>>id&&ifs>>name&&ifs>>did)
	{
		Worker* worker = NULL;
		if (did == 1)//��ͨԱ��
		{
			worker = new employee(id, name, did);
		}
		else if (did == 2)//��ͨԱ��
		{
			worker = new Manager(id, name, did);
		}
		else//��ͨԱ��
		{
			worker = new Boss(id, name, did);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();

}

void workerManager::Show_Emp() 
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty) 
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++) 
		{
			//���ö�̬
			this->m_EmpArray[i]->showInfo();
		}
	}
	//����������
	system("pause");
	system("cls");
}
int workerManager::IsExit(int id) 
{
	int index = -1;
	for (size_t i = 0; i < this->m_EmpNum; i++) 
	{
		if (this->m_EmpArray[i]->m_Id == id) 
		{//�ҵ�ְ����
			index = i;
			break;
		}
	}
	return index;
}

void  workerManager::Del_Emp() 
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		//����ְ���任ɾ��
		cout << "��������Ҫɾ����ְ����ţ�" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExit(id);
		if (index != -1)//˵��ְ�����ڣ�����Ҫɾ��indexλ���ϵ�ְ��
		{
			//����ǰ��
			for (size_t i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//���¼�¼����Ա����
			//����ͬ�����ļ���
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}
	//�����������
	system("pause");
	system("cls");
}

void workerManager::Mod_Emp() 
{
	if (this->m_FileIsEmpty) 
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;
		int ret = this->IsExit(id);
		if (ret != -1) 
		{
			//�ҵ������ŵ�ְ��
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "���ҵ���" << id << "��ְ�����������µ�ְ���ţ�" << endl;
			cin >> newId;
			cout << "������������" << endl;
			cin >> newName;
			cout << "�������µĸ�λ" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			//�������ݵ�������
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ�" << endl;
			//���浽�ļ���
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}
	}

	system("pause");
	system("cls");

}

void workerManager::Find_Emp() 
{
	if (this->m_FileIsEmpty) 
	{
		cout << "�ļ������ڣ����߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1������ְ����Ų��ң�" << endl;
		cout << "2������ְ���������ң�" << endl;
		int Select = 0;
		cin >> Select;
		if (Select == 1) 
		{//����Ų�
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;
			int ret=IsExit(id);
			if (ret != -1) 
			{
				cout << "���ҳɹ�����ְ����Ϣ����" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ��" << endl;
			}
		}
		else if (Select==2)
		{
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;
			//�����ж��Ƿ�鵽�ı�־
			bool flag = false;
			for (size_t i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��" 
						<< this->m_EmpArray[i]->m_Id
						<<"��ְ����Ϣ���£�"<<endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false) 
			{
				cout << "����ʧ��" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}
	system("pause");
	system("cls");
}

void workerManager::Sort_Emp() 
{
	if (this->m_FileIsEmpty) 
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ" << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++) 
		{
			int minOrmax = i;
			//cout <<"ͷ��" << minOrmax << endl;
			for (int j = i + 1; j < this->m_EmpNum; j++) 
			{
			if (select == 1)//
			{
				if (this->m_EmpArray[minOrmax]->m_Id > this->m_EmpArray[j]->m_Id) 
				{
					minOrmax = j;
				}
			}
			else//
			{
				if (this->m_EmpArray[minOrmax]->m_Id < this->m_EmpArray[j]->m_Id)
				{
					minOrmax = j;
				}
			}
			}
			//cout << "β��" << minOrmax << endl;
			if (i != minOrmax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrmax];
				this->m_EmpArray[minOrmax] = temp;
			}

		}
		
	cout << "����ɹ��������Ľ��Ϊ��" << endl;
	this->save();//�����Ľ������
	this->Show_Emp();
	}
}

void workerManager::Clean_File() 
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) 
	{
		ofstream ofs(FILENAME,ios::trunc);//ɾ���ļ����ؽ�
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			//ɾ��������ÿ������
			for (size_t i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;//�����ÿ�
			}
			//ɾ����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}