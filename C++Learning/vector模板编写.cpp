#include <iostream>
#include <string>
using namespace std;
int* p = NULL;//�������ڵ�ַ
int num = 0;//��ǰ����Ŀ

void push(int data) {
	int* pNew = (int*)malloc (sizeof(int)*(num+1));//�����ڴ�
	if (p) {//���p��Ϊ��  ��ָ��һ���ֽڣ�������ָ��һ���ڴ棬����������sizeof(int) * num
		memcpy(pNew,p, sizeof(int) * num );//�����Ǹ��� ��ǰ ��������ĳ���
		delete(p);//��ԭ��p��������ͷ�
	}
	p = pNew; //pָ���¿����ڴ�
	p[num++] = data;//�����ݴ���
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