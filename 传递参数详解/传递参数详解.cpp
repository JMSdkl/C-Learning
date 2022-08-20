#include <iostream> //用了泛型，需要把所有东西都放在头文件里面
#include <string>
#include<thread>

using namespace std;

//void myprint(const int& i, char* pmybuf) 
void myprint(const int& i, const string pmybuf)
{
	cout << i << endl;//实际分析认为，i不是mvar的引用，是值复制，所以用death是安全的

	cout << pmybuf.c_str() << endl;//death子线程时绝对有问题，不能传指针
	return;

}
int main() 
{	//一：传递临时对象作为线程参数
	int mvar = 1;
	int& mvary = mvar;
	char mybuf[] = "test";
	thread mytobj(myprint, mvar, mybuf);//mvar在观察内存结果可以看出不是一个真引用，而是复制一个值进去的
	//mytobj.join();
	mytobj.detach();
	cout << "I Love China" << endl;
	

	system("pause");
	return 0;

}