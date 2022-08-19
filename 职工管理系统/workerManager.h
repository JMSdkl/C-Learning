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
	//记录职工人数
	int m_EmpNum;
	//职工数组的指针
	Worker** m_EmpArray; //父类的指针管理 子类的指针
	//添加职工的函数
	void AddEmp();
	void save();
	~workerManager();
};

