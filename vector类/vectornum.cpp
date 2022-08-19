#include <iostream>
#include <string>
#include "MyArray.h"
using namespace std;
    /*	1:c数组
		2：c指针 malloc 动态数组
		 3：类 new
		 4:泛型 类模板
		 5:动态分配的 常规技术手段 非常规手段
		 6：大牛心里的数据结构
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