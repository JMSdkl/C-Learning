#include<iostream>
#include<string>
using namespace std;

template<class T>
class Base
{
	T m;

};
//class Son :public Base//确定不了父类占多少内存空间，必须要知道父类中T的数据类型才能继承
class Son :public Base<int>
{


};
void test01() 
{
	Son s1;
}
//如果想灵活指定父类中T类型，之类也需要变模板
template<class T1,class T2>
class Son2 :public Base<T2> 
{
public:
	Son2() 
	{
		cout << "T1的数据类型为：" << typeid(T1).name() << " " << "T2的数据类型为：" << typeid(T2).name() << endl;
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