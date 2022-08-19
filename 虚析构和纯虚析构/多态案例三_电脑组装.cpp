#include <iostream> //用了泛型，需要把所有东西都放在头文件里面
#include <string>

using namespace std;

//抽象不同零件的类
class CPU 
{
public:
	//抽象计算函数
	virtual void calculate() = 0;
	virtual ~CPU()  =0 ;

};
CPU::~CPU() { cout << "1111"; }

class VideoCard
{
public:
	//抽象显示函数
	virtual void display() = 0;


};

class Memory
{
public:
	//抽象存储函数
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
	//提供一个工作的函数
	void Work() 
	{	//让零件工作起来，调用接口
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	~Computer() {
		if (m_cpu != NULL) { delete m_cpu; m_cpu = NULL; }
		if (m_vc != NULL) { delete m_vc; m_vc = NULL; }
		if (m_mem != NULL) { delete m_mem; m_mem = NULL; }
	
	}
private:  //因为指针是在computer里维护零件，可以在这里写析构
	//各种零件的指针
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_mem;

};
//具体厂商：Intel
class IntelCPU :public CPU
{
public:
	virtual void calculate() 
	{
		cout << "Intel的cpu开始计算" << endl;
	};

	~IntelCPU() { cout << "调用子类析构"; };
};
class IntelVideoCard :public VideoCard
{
public:
	virtual void display() 
	{
		cout << "Intel的VideoCard开始显示" << endl;
	};
};
class IntelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel的Memory存储数据" << endl;
	};
};

//具体厂商：Lenovo
class LenovoCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo的cpu开始计算" << endl;
	};
	

};
class LenovoVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Lenovo的VideoCard开始显示" << endl;
	};
};
class LenovoMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo的Memory存储数据" << endl;
	};
};

void test01() 
{	//第一台电脑零件
	cout << "第一台电脑开始工作" << endl;
	CPU* intelCpu = new IntelCPU;				//零件还没释放，要在析构那里释放
	VideoCard* intelcard = new IntelVideoCard;
	Memory* intelmem = new IntelMemory;
	//创建第一台电脑
	Computer* computer1 = new Computer(intelCpu, intelcard, intelmem);
	computer1->Work();
	delete computer1;

	cout << "第二台电脑开始工作" << endl;
	Computer* computer2 = new Computer(new LenovoCPU,new LenovoVideoCard ,new LenovoMemory );
	computer2->Work();
	delete computer2;

}



int main() {

	test01();

	system("pause");
	return 0;

}