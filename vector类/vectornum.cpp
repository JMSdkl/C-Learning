#include <iostream>
#include <string>
#include "MyArray.h"
using namespace std;
    /*	1:c����
		2��cָ�� malloc ��̬����
		 3���� new
		 4:���� ��ģ��
		 5:��̬����� ���漼���ֶ� �ǳ����ֶ�
		 6����ţ��������ݽṹ
	 */

int main() {
	MyArray a;
	for (int i = 0; i < 10; i++) 
	{
		a.push(i);
	}
	a.travel();
	system("pause");
	return 0;

}