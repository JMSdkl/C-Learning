#pragma once
#include <iostream>
#include<string>
using namespace std;

class Worker
{
public:

	 //显示个人信息
	virtual void showInfo() = 0;//是作为父类用多态的，不同的子类有不同的信息，所以纯虚
	virtual string getDeptName() = 0;


	string m_Name;
	int m_DeptId;
	int m_Id;
};

