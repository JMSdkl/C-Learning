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
		
		
		
		vector<int>number = {0,-1,-1,-1,-1};//输入要用pushback给弄成动态的
		for (size_t i = 0; i < data1; i++) {
			if (number[i] >= 0) {
				a++;
				
			}
			else if(number[i] < 0)//遇到-1就进入
			{
				int b = 0;
				
				cout << "此时的num为：" << number[i] << endl;
				cout << "在i为：" << i << "时进入" << endl;
				for (size_t j = i+1 ; j < data1; j++) {
					if (number[j] <= 0) {
						
						b++;
					}
				}
				cout << "k右边小于等于0的错误: " << b << endl;
				cout << "k左边大于等于0的错误: " << a << endl;
			}
		}
		
		//cout << "k左边大于0的错误: " << a<<endl;
		//cout << "k右边小于0的错误: " << b << endl;
		//cout << "至少出现的错误: " << a+b << endl;

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