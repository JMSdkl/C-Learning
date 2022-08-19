#include <iostream> //���˷��ͣ���Ҫ�����ж���������ͷ�ļ�����
#include <string>

using namespace std;

//����ͬ�������
class CPU 
{
public:
	//������㺯��
	virtual void calculate() = 0;
	virtual ~CPU()  =0 ;

};
CPU::~CPU() { cout << "1111"; }

class VideoCard
{
public:
	//������ʾ����
	virtual void display() = 0;


};

class Memory
{
public:
	//����洢����
	virtual void storage() = 0;


};

class Computer 
{ public:
	Computer(CPU*cpu,VideoCard*vc,Memory*mem) 
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	
	}
	//�ṩһ�������ĺ���
	void Work() 
	{	//������������������ýӿ�
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	~Computer() {
		if (m_cpu != NULL) { delete m_cpu; m_cpu = NULL; }
		if (m_vc != NULL) { delete m_vc; m_vc = NULL; }
		if (m_mem != NULL) { delete m_mem; m_mem = NULL; }
	
	}
private:  //��Ϊָ������computer��ά�����������������д����
	//���������ָ��
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_mem;

};
//���峧�̣�Intel
class IntelCPU :public CPU
{
public:
	virtual void calculate() 
	{
		cout << "Intel��cpu��ʼ����" << endl;
	};

	~IntelCPU() { cout << "������������"; };
};
class IntelVideoCard :public VideoCard
{
public:
	virtual void display() 
	{
		cout << "Intel��VideoCard��ʼ��ʾ" << endl;
	};
};
class IntelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel��Memory�洢����" << endl;
	};
};

//���峧�̣�Lenovo
class LenovoCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo��cpu��ʼ����" << endl;
	};
	

};
class LenovoVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Lenovo��VideoCard��ʼ��ʾ" << endl;
	};
};
class LenovoMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo��Memory�洢����" << endl;
	};
};

void test01() 
{	//��һ̨�������
	cout << "��һ̨���Կ�ʼ����" << endl;
	CPU* intelCpu = new IntelCPU;				//�����û�ͷţ�Ҫ�����������ͷ�
	VideoCard* intelcard = new IntelVideoCard;
	Memory* intelmem = new IntelMemory;
	//������һ̨����
	Computer* computer1 = new Computer(intelCpu, intelcard, intelmem);
	computer1->Work();
	delete computer1;

	cout << "�ڶ�̨���Կ�ʼ����" << endl;
	Computer* computer2 = new Computer(new LenovoCPU,new LenovoVideoCard ,new LenovoMemory );
	computer2->Work();
	delete computer2;

}



int main() {

	test01();

	system("pause");
	return 0;

}