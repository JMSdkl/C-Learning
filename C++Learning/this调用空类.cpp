#include <iostream>
#include <string>
using namespace std;

class person {
public:
	void showClassName() {
	
		cout << "this is person class" << endl;
	}
	void showPersonAge() {
	//报错原因是传入指针为空
		if (this == NULL) {    //预防传入空指针
			return;
		}
		cout << "age=" << this->m_Age << endl;//系统默认会加上this
	}					//这样this会指向了空指针而报错
	int m_Age=10;
};
void test01() {
	person* p = NULL;	//空指针是可以访问成员的
	p->showClassName();
	p->showPersonAge();
}


int main() {

	test01();




	system("pause");
	return 0;
}