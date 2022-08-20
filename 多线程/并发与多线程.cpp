#include <iostream> //用了泛型，需要把所有东西都放在头文件里面
#include <string>
#include<thread>

using namespace std;

void myprint() 
{
	cout << "我的线程开始执行" << endl;

	cout << "我的线程结束了" << endl;
}
class ta 
{public:
	int m_i;
	ta(int i) :m_i(i) 
	{
		cout << "ta()构造函数被执行" << endl;
	}
	ta(const ta &ta) :m_i(ta.m_i)
	{
		cout << "ta()拷贝构造函数被执行" << endl;
	}
	~ta() 
	{
		cout << "~ta()析构函数被执行" << endl;
	}
	void operator()() 
	{
		//cout << "我的线程operator()开始执行" << endl;
		cout << "m_i1的值为" << m_i << endl;
		cout << "m_i2的值为" << m_i << endl;
		cout << "m_i3的值为" << m_i << endl;
		cout << "m_i4的值为" << m_i << endl;
		cout << "m_i5的值为" << m_i << endl;
		cout << "m_i6的值为" << m_i << endl;
		
		cout << "我的线程operator()结束了" << endl;
	}
	
};

int main() {
	//1:对c++有一定把握，中级以及以上水平
	//2：c++11  新内容  和语法要掌握

	//并发、进程、线程基本概念必须掌握
	//并发：两个或多个任务同时进行：一个程序同时进行多个独立任务
	//以往计算器，单核cpu：某一时刻只能执行一个任务，要有操作系统调度，每秒进行多次“任务切换”，来作为并发
	//不是真正的并发

	//可执行程序运行-》生成一个进程，同时该程序所属的的主线程开始运行

	

	//主线程从main开始执行，那自己创建的线程，也需要一个函数开始运行（初始函数），一旦这个函数运行完毕，就代表这个线程运行结束
	//整个进程是否执行完毕的标志是：主线程是否执行完，如果主线程执行完毕，就代表整个进程执行完毕
	//此时如果子线程还没执行完毕，那么这些子线程也会被操作系统强行终止（一般情况下）
	//所以，一般情况下，想要保持子线程的运行状态，要保持主线程一直运行
	//这条规律有例外


	//1：包含头文件 thread
	//2: 写初始函数
	//3：在main中写代码
	//必须明确是有两个线程在跑，相当于有两条平行线在走，可以同时干两件事，即使一条线被堵住了，另外一条还是可以通行的
	//thread： 是标准库里的类，myprint是可调用对象
	//join：加入\汇合，阻塞主线程，让主线程等待子线程执行完毕，然后子线程和主线程汇合完毕，主线程继续走
	//thread mytobj(myprint);//创建了线程，线程执行起点myprint（）；开始执行
	/*if (mytobj.joinable()) 
	{
		cout <<"joinable=1" << endl;
	}
	else
	{
		cout << "joinable=0" << endl;
	}*/
	//mytobj.join();//join的真正使用意义，主线程可以继续执行join之前的指令，子线程执行子线程的指令。
	//但主线程执行到join时必须等待子线程结束，因为主线程需要子线程处理的结果，才能执行join后的指令
	//例外：detach（）主线程可以不等待子线程，先跑完。
	//detach：分离,也就是主线程不和子线程汇合了。且主线程可以先结束，不影响子线程
	//mytobj.detach();与主线程失去联系，此时该子线程会驻留后台运行 由运行时库负责清理该线程相关资源、
	//joinable():判断是否成功可以使用join（）或detach（）返回true或false
	/*if (mytobj.joinable())
	{
		cout << "joinable=1" << endl;
	}
	else
	{
		cout << "joinable=0" << endl;
	}*/

	//其他方法
	//用类作为可调用对象
	int myi = 6;
	ta ee(myi);
	//ee();
	thread mytobj3(ee);//ta可调用对象  因为重载了（），此时是ee();但因为thread 的构造（）里需要地址，所以只写了函数名
	mytobj3.join();
	
	//用lambda表达式：
	auto mylamthread = []
	{cout << "我的线程3开始执行" << endl;

	cout << "我的线程3执行结束" << endl;
	};
	thread mytobj4(mylamthread);
	mytobj4.join();


	cout << "I Love China" << endl;//主线程执行完就是进程执行完毕了
	cout << "I Love China" << endl;
	cout << "I Love China" << endl;
	cout << "I Love China" << endl;
	cout << "I Love China" << endl;
	cout << "I Love China" << endl;         //子线程打印的是主线程myi的引用，但是当主线程结束后，myi就被回收了
	cout << "I Love China" << endl; 		//此时子线程还在打印被回收的内容，会产生不可预料的后果
											//用引用传值会出现问题，把引用变为整型即可
											// 主线程结束ta,被销毁为什么能正确运行？
											// 答：ta对象肯定不在了，这个对象实际上是被复制到了线程中去的，
											// 执行完主线程后，ta会被销毁，但是子线程中ta依旧存在
											// 所以只要这个类对象里面没有引用，没有指针，就不会产生问题
	//system("pause");
	return 0;

}