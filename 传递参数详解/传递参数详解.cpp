#include <iostream> //���˷��ͣ���Ҫ�����ж���������ͷ�ļ�����
#include <string>
#include<thread>

using namespace std;

//void myprint(const int& i, char* pmybuf) 
void myprint(const int& i, const string pmybuf)
{
	cout << i << endl;//ʵ�ʷ�����Ϊ��i����mvar�����ã���ֵ���ƣ�������death�ǰ�ȫ��

	cout << pmybuf.c_str() << endl;//death���߳�ʱ���������⣬���ܴ�ָ��
	return;

}
int main() 
{	//һ��������ʱ������Ϊ�̲߳���
	int mvar = 1;
	int& mvary = mvar;
	char mybuf[] = "test";
	thread mytobj(myprint, mvar, mybuf);//mvar�ڹ۲��ڴ������Կ�������һ�������ã����Ǹ���һ��ֵ��ȥ��
	//mytobj.join();
	mytobj.detach();
	cout << "I Love China" << endl;
	

	system("pause");
	return 0;

}