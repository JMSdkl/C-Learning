#include<iostream>
#include<string>
using namespace std;

template<class T>
class Base
{
	T m;

};
//class Son :public Base//ȷ�����˸���ռ�����ڴ�ռ䣬����Ҫ֪��������T���������Ͳ��ܼ̳�
class Son :public Base<int>
{


};
void test01() 
{
	Son s1;
}
//��������ָ��������T���ͣ�֮��Ҳ��Ҫ��ģ��
template<class T1,class T2>
class Son2 :public Base<T2> 
{
public:
	Son2() 
	{
		cout << "T1����������Ϊ��" << typeid(T1).name() << " " << "T2����������Ϊ��" << typeid(T2).name() << endl;
	}
	T1 obj;
};
void test02() 
{
	Son2<int, char> s2;

}
int main() 
{
	test02();

	system("pause");
	return 0;
}