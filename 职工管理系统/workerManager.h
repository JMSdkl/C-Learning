#pragma once
#include<iostream>
#include "Worker.h"
#include"employee.h"
#include"BOSS.h"
#include"Manager.h"
#include<fstream>
#define FILENAME "wmpFile.txt"

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
};

