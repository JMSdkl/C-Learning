#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Data_splitting
{
public:
	Data_splitting();
	~Data_splitting();
	void test(long data1) {
		int a = 0;
		
		
		
		vector<int>number = {0,-1,-1,-1,-1};//����Ҫ��pushback��Ū�ɶ�̬��
		for (size_t i = 0; i < data1; i++) {
			if (number[i] >= 0) {
				a++;
				
			}
			else if(number[i] < 0)//����-1�ͽ���
			{
				int b = 0;
				
				cout << "��ʱ��numΪ��" << number[i] << endl;
				cout << "��iΪ��" << i << "ʱ����" << endl;
				for (size_t j = i+1 ; j < data1; j++) {
					if (number[j] <= 0) {
						
						b++;
					}
				}
				cout << "k�ұ�С�ڵ���0�Ĵ���: " << b << endl;
				cout << "k��ߴ��ڵ���0�Ĵ���: " << a << endl;
			}
		}
		
		//cout << "k��ߴ���0�Ĵ���: " << a<<endl;
		//cout << "k�ұ�С��0�Ĵ���: " << b << endl;
		//cout << "���ٳ��ֵĴ���: " << a+b << endl;

	}

private:
	
};

Data_splitting::Data_splitting()
{
}

Data_splitting::~Data_splitting()
{
}



int main() {

	Data_splitting d1;
	d1.test(5);


	system("pause");
	return 0;

}