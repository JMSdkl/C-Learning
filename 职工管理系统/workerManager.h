#pragma once
#include<iostream>
#include "Worker.h"
#include"employee.h"
#include"BOSS.h"
#include"Manager.h"
#include<fstream>
#define FILENAME "wmpFile1.txt"

using namespace std;
class workerManager
{
public:
	workerManager();
	void Show_Menu();
	void exitsSystem();
	//��¼ְ������
	int m_EmpNum;
	//ְ�������ָ��
	Worker** m_EmpArray; //�����ָ����� �����ָ��
	//���ְ���ĺ���
	void AddEmp();
	void save();
	~workerManager();
	//�ж��ļ��Ƿ�Ϊ�յı�־
	bool m_FileIsEmpty;
	int get_EmpNum();
	//��ʼ��Ա��
	void init_Emp();
	//��ʾְ��
	void Show_Emp();
	//�ж�ְ���Ƿ���ڵĺ���  ������ھͷ������������е�λ�� ���ھͷ���-1
	int IsExit(int id);
	//ɾ��ְ��
	void Del_Emp();
	//�޸�ְ��
	void Mod_Emp();
	//����Ա��
	void Find_Emp();
	//ְ���������
	void Sort_Emp();
	//����ļ�
	void Clean_File();
};

