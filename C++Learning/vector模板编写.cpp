#include <iostream>
#include <string>
using namespace std;
int* p = NULL;//数组的入口地址
int num = 0;//当前的数目

void push(int data) {
	int* pNew = (int*)malloc (sizeof(int)*(num+1));//分配内存
	if (p) {//如果p不为空  是指向一个字节，而不是指向一段内存，所以下面是sizeof(int) * num
		memcpy(pNew,p, sizeof(int) * num );//第三是复制 当前 存在数组的长度
		delete(p);//把原来p里的内容释放
	}
	p = pNew; //p指向新开的内存
	p[num++] = data;//将数据传入
}
void travel() {
	cout << "array: " ;
	for (size_t i=0; i < num; i++) {
		cout << p[i];
	}
	cout << endl;

}


int main() {

	for (size_t i=0; i < 6; i++) {
		push(i);
	}
	travel();

	system("pause");
	return 0;

}