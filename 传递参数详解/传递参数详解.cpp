#include <iostream> //���˷��ͣ���Ҫ�����ж���������ͷ�ļ�����
#include <string>
#include<thread>

using namespace std;

class  A 
{public:
	int m_i;
	//����ת�����캯�������԰�һ��int����ת��Ϊ�����
	A(int a) :m_i(a) 
	{
		cout << "A(int a )���캯��ִ��" <<this<< endl;
	}
	A(const A &a) :m_i(a.m_i) //һ��Ҫ�����ã� ����������캯���еĲ�������һ�����ã�������CClass(const CClass c_class)����ô���൱�ڲ����˴�ֵ�ķ�ʽ(pass-by-value)��
							//����ֵ�ķ�ʽ����ø���Ŀ������캯�����Ӷ��������ݹ�ص��ÿ������캯����
							//��˿������캯���Ĳ���������һ�����á�
	{
		cout << "A()�������캯��ִ��" <<this<< endl;
	}
	~A() 
	{
		cout << "A()��������ִ��" <<this <<endl;
	}
};

//void myprint(const int& i, char* pmybuf) 
//void myprint(const int& i, const string pmybuf)
//{
//	cout << i << endl;//ʵ�ʷ�����Ϊ��i����mvar�����ã���ֵ���ƣ�������death�ǰ�ȫ��
//
//	cout << pmybuf.c_str() << endl;//death���߳�ʱ���������⣬���ܴ�ָ��
//	return;
//
//}
void myprint(const int& i, const A& pmybuf) 
{
	cout <<"��������ĵ�ַΪ:" << &pmybuf << endl;
	return;
}

int main() 
{	//һ��������ʱ������Ϊ�̲߳���
	//int mvar = 1;
	//int& mvary = mvar;
	//char mybuf[] = "test";
	////thread mytobj(myprint, mvar, mybuf);//mvar�ڹ۲��ڴ������Կ�������һ�������ã����Ǹ���һ��ֵ��ȥ��
	//									//����mybuf������ʲôʱ��תΪstring�ģ�
	//									// ��������������ˣ���ûת��Ϊstring���Ǿͳ���������
	//									// ��
	//
	//thread mytobj(myprint, mvar, string(mybuf));//����ֱ�ӽ�mybufת��Ϊstring���󣬿��Ա�֤�ȶ�
	//									//mytobj.join();
	int mvar = 1;
	int mysecondpar = 12;
	thread mytobj(myprint, mvar, A(mysecondpar));//ϣ������תΪA���Ͷ��󴫵ݸ�myprint�ĵڶ�������
	mytobj.detach();
	cout << "I Love China" << endl;
	

	//system("pause");
	return 0;

}