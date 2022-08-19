#include <iostream>
#include <string>

using namespace std;
//类对象作为类成员
class Phone {
public:
	Phone(string pName) {
		m_PName = pName;
		cout << "调用了Phone有参构造函数" << endl;
	}
	~Phone() {
	
		cout << "调用了Phone的析构函数" << endl;
	}
//private:加入私有之后要写一个输出接口才能调用私有成员
	//手机品牌名称
	string m_PName;
};


class person {
public:

												//Phone m_Phone=pName;//调用了有参构造函数（隐式转换法）
	person(string name, string pName) :m_Name(name),m_Phone(pName)
	{
		cout << "调用了person的有参构造函数" << endl;
	}
	~person() {
	
		cout << "调用了person的析构函数" << endl;
	}

//private:
	//姓名
	string m_Name;
	//手机
	Phone m_Phone;
};
void test01() {
	person p("张三", "苹果");
	cout << p.m_Name << "拿着：" << p.m_Phone.m_PName << endl;
}
int main() {

	test01();




	system("pause");
	return 0;

}