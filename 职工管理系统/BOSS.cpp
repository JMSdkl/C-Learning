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
	cout << "ְ����ţ�" << m_Id << "\t�ϰ�������" << m_Name << "\t��λ��" << this->getDeptName() << "\t��λְ�𣺹���˾��������" << endl;
}
string Boss::getDeptName()
{
	return string("�ϰ�");
}