#include<iostream>
#include<string>
#include<algorithm>//��׼�㷨��ͷ�ļ�
#include<vector>
using namespace std;
void myPrint() 
{
}
void test01() 
{
	vector<int> V;
	V.push_back(10);
	V.push_back(20);
	V.push_back(30);
	V.push_back(40);
	//ͨ����������������������
	//vector<int>::iterator itBegin = V.begin();//��ʼ��������ָ�������е�һ��Ԫ��
	//vector<int>::iterator itEnd = V.end();//ָ�����������һ��Ԫ�ص���һ��λ��
	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	//���ñ���  //��������
	for (vector<int>::iterator it = V.begin(); it != V.end(); it++) 
	{
		cout << *it << endl;
	}
	//�����ֱ�����ʽ ����stl�ı����㷨
	for each (V.begin(),V.end())
	{

	}

}
int main() 
{
	test01();

	system("pause");
	return 0;
}