#include <iostream>
#include <string>
using namespace std;

class person {
public:		//thisָ��ı�����ָ�볣����ָ���ָ�򲻿����޸�
			//Person * const this;
			//�ڳ�Ա���������const ���ε���thisָ�룬��ָ��ָ���ֵ�޷��ı�

	//������

	void showPerson() const//�����ֵ�Ͳ������޸���
	{                  //�������const���൱�ڣ�const Person * const this;
		//this->m_A = 100;
		//this = NULL;//thisָ���ǲ������޸�ָ��
		this->m_B = 100;
	}
	void showPerson2() //�����ֵ�Ͳ������޸���
	{                  //�������const���൱�ڣ�const Person * const this;
		this->m_A = 100;
		//this = NULL;//thisָ���ǲ������޸�ָ��
		
	}
	int m_A;
	mutable int m_B;//��ɫ�������ڳ�����Ҳ�����޸�ֵ �ӹؼ���mutable

};

void test02() {
	const person p;//�����󣬲������޸�ָ������ֵ
	//p.m_A = 100;//����
	p.m_B = 100;//b�йؼ���mutable����ʹ�ڳ�������Ҳ�����޸�ֵ
	//������ֻ�ܵ��ó�����
	p.showPerson();
	//p.showPerson2();//���ò��˳�����

}



int main() {




	system("pause");
	return 0;

}