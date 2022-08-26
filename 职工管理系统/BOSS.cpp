#include "BOSS.h"

#include<string>
using namespace std;

Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
void Boss::showInfo()
{
	cout << "职工编号：" << m_Id << "\t老板姓名：" << m_Name << "\t岗位：" << this->getDeptName() << "\t岗位职责：管理公司所有事务" << endl;
}
string Boss::getDeptName()
{
	return string("老板");
}