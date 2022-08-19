#include <iostream>
#include <string>
using namespace std;
//重载关系运算符
class person {
public:
	person(string name,int age) {
		m_Name = name;
		m_Age = age;
	}
	//重载关系运算符==
	bool operator==(person &p) {
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
			return true;
		}
		else
		{
			return false;		//是布尔类型的
		}
	}
	bool operator!=(person& p) {
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
			return false;
		}
		else
		{
			return true;		//是布尔类型的
		}
	}
	string m_Name;
	int m_Age;
};
void test01() {
	person p1("tom", 18);
	person p2("tom", 18);

	if (p1 != p2) {
		cout << "p1!=p2" << endl;
	}
	else
	{
		cout << "p1=p2" << endl;
	}

}

int main() {
	
	test01();







	system("pause");
	return 0;

}