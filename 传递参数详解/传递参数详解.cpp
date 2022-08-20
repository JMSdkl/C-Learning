#include <iostream> //用了泛型，需要把所有东西都放在头文件里面
#include <string>
#include<thread>

using namespace std;

class  A 
{public:
	 int m_i;
	//类型转换构造函数，可以把一个int整型转换为类对象
	A(int a) :m_i(a) 
	{
		cout << "A(int a )构造函数执行" <<this<<"threadid= "<<std::this_thread::get_id() << endl;
	}
	A(const A &a) :m_i(a.m_i) //一定要传引用， 如果拷贝构造函数中的参数不是一个引用，即形如CClass(const CClass c_class)，那么就相当于采用了传值的方式(pass-by-value)，
							//而传值的方式会调用该类的拷贝构造函数，从而造成无穷递归地调用拷贝构造函数。
							//因此拷贝构造函数的参数必须是一个引用。
	{
		cout << "A()拷贝构造函数执行" <<this << "threadid= " << std::this_thread::get_id() << endl;
	}
	~A() 
	{
		cout << "A()析构函数执行" <<this << "threadid= " << std::this_thread::get_id() <<endl;
	}
};

//void myprint(const int& i, char* pmybuf) 
//void myprint(const int& i, const string pmybuf)
//{
//	cout << i << endl;//实际分析认为，i不是mvar的引用，是值复制，所以用death是安全的
//
//	cout << pmybuf.c_str() << endl;//death子线程时绝对有问题，不能传指针
//	return;
//
//}
void myprint(const int& i, const A& pmybuf) //不用引用的话会构造出3次临时变量出来，现在以经有两次了
{
	cout <<"传入参数的地址为:" << &pmybuf << endl;
	return;
}

void myprint2( A& pmybuf) 
{
	pmybuf.m_i = 199;//修改该值不会影响main函数
	cout << "子线程myprint2的参数地址：" << &pmybuf << "threadid= " << std::this_thread::get_id()<<endl;
}

int main() 
{	//一：传递临时对象作为线程参数
	//int mvar = 1;
	//int& mvary = mvar;
	//char mybuf[] = "test";
	////thread mytobj(myprint, mvar, mybuf);//mvar在观察内存结果可以看出不是一个真引用，而是复制一个值进去的
	//									//但是mybuf到底是什么时侯转为string的？
	//									// 就怕主程序结束了，还没转换为string，那就出现问题了
	//									// 答：
	//
	//thread mytobj(myprint, mvar, string(mybuf));//这里直接将mybuf转化为string对象，可以保证稳定
	//									//mytobj.join();
	//int mvar = 1;
	//int mysecondpar = 12;
	//thread mytobj(myprint, mvar, A(mysecondpar));//希望整型转为A类型对象传递给myprint的第二给参数

	/*cout << "主线程id：" << std::this_thread::get_id() << endl;
	int mvar = 1;
	thread mytobj(myprint2, A(mvar));
	mytobj.detach();*/

	A myobj(10);
	thread mytobj(myprint2,ref(myobj));//把子线程的199传递出来了    ref可以让传参成为真正的引用了，当没有ref时，会进行拷贝构造
	mytobj.join();
	cout << "I Love China" << endl;
	

	

	system("pause");
	return 0;

}