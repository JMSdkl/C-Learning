#include <iostream>
#include <string>
using namespace std;

class person {
public:
	void showClassName() {
	
		cout << "this is person class" << endl;
	}
	void showPersonAge() {
	//����ԭ���Ǵ���ָ��Ϊ��
		if (this == NULL) {    //Ԥ�������ָ��
			return;
		}
		cout << "age=" << this->m_Age << endl;//ϵͳĬ�ϻ����this
	}					//����this��ָ���˿�ָ�������
	int m_Age=10;
};
void test01() {
	person* p = NULL;	//��ָ���ǿ��Է��ʳ�Ա��
	p->showClassName();
	p->showPersonAge();
}


int main() {

	test01();




	system("pause");
	return 0;
}