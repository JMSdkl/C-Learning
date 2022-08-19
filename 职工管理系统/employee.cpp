#include "employee.h"

employee::employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

string employee::getDeptName() 
{
	return string("员工");
}
void employee::showInfo() 
{
	cout << "员工编号：" << m_Id<<  "\t员工姓名：" << m_Name << "\t岗位：" << this->getDeptName()<<"\t岗位职责：完成经理交给的任务" << endl;

}