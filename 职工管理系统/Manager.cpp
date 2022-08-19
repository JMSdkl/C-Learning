#include "Manager.h"
#include<string>
using namespace std;

Manager::Manager(int id, string name, int dId) 
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
void Manager::showInfo() 
{
	cout << "经理编号：" << m_Id << "\t经理姓名：" << m_Name << "\t岗位：" << this->getDeptName() << "\t岗位职责：完成老板交给的任务，并且下发任务给普通员工" << endl;
}
string Manager::getDeptName() 
{
	return string("经理");
}