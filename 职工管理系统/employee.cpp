#include "employee.h"

employee::employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

string employee::getDeptName() 
{
	return string("Ա��");
}
void employee::showInfo() 
{
	cout << "Ա����ţ�" << m_Id<<  "\tԱ��������" << m_Name << "\t��λ��" << this->getDeptName()<<"\t��λְ����ɾ�����������" << endl;

}