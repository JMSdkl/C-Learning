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
	cout << "�����ţ�" << m_Id << "\t����������" << m_Name << "\t��λ��" << this->getDeptName() << "\t��λְ������ϰ彻�������񣬲����·��������ͨԱ��" << endl;
}
string Manager::getDeptName() 
{
	return string("����");
}