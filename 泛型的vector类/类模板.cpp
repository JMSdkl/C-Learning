#include <iostream> //���˷��ͣ���Ҫ�����ж���������ͷ�ļ�����
#include <string>
#include "MyVector.h"
using namespace std;


int main() {
	
	MyArray<int> intArr;
	MyArray<double> doubleArr;
	for (int i = 1; i < 11; i++) {
		intArr.push(i);
		doubleArr.push(i+0.06);
	}
	intArr.travel();
	doubleArr.travel();

	system("pause");
	return 0;

}