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
	//记录职工人数
	int m_EmpNum;
	//职工数组的指针
	Worker** m_EmpArray; //父类的指针管理 子类的指针
	//添加职工的函数
	void AddEmp();
	void save();
	~workerManager();
	//判断文件是否为空的标志
	bool m_FileIsEmpty;
	int get_EmpNum();
	//初始化员工
	void init_Emp();
	//显示职工
	void Show_Emp();
	//判断职工是否存在的函数  如果存在就返回所在数组中的位置 不在就返回-1
	int IsExit(int id);
	//删除职工
	void Del_Emp();
	//修改职工
	void Mod_Emp();
	//查找员工
	void Find_Emp();
	//职工编号排序
	void Sort_Emp();
	//清空文件
	void Clean_File();
};

