#pragma once
#include <iostream>
#include<string>
using namespace std;

class Worker
{
public:

	 //��ʾ������Ϣ
	virtual void showInfo() = 0;//����Ϊ�����ö�̬�ģ���ͬ�������в�ͬ����Ϣ�����Դ���
	virtual string getDeptName() = 0;


	string m_Name;
	int m_DeptId;
	int m_Id;
};

