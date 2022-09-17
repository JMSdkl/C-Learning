#include<iostream>
#include<string>
#include<algorithm>//��׼�㷨��ͷ�ļ�
#include<vector>
using namespace std;
//һ��������ʶ
void myPrint(int val) 
{
	cout << val << endl;
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
	for_each (V.begin(), V.end(), myPrint);//���ûص�����
	

}

//����vector�����д���Զ�����������
class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;

};
void test02() 
{
	vector<Person>V;
	Person p1("as", 132);
	Person p2("asdas", 32);
	Person p3("aghs", 12);
	Person p4("abs", 13);
	Person p5("as,nm", 32);
	V.push_back(p1);
	V.push_back(p2);
	V.push_back(p3);
	V.push_back(p4);
	V.push_back(p5);
	//���������е�����
	for (vector<Person>::iterator it = V.begin(); it != V.end(); it++) //it�����ã���������person����������
	{
		cout << "������" << (*it).m_name << " " << "���䣺" << it->m_age << endl;//��Ϊit�Ǹ�ָ��
	}

}
//��������Զ����������͵�ָ��
void test03() 
{
	vector<Person*>V;//�൱�������д�ŵ��Ǹ�������ĵ�ַ
	Person p1("as", 132);
	Person p2("asdas", 32);
	Person p3("aghs", 12);
	Person p4("abs", 13);
	Person p5("as,nm", 32);
	V.push_back(&p1);
	V.push_back(&p2);
	V.push_back(&p3);
	V.push_back(&p4);
	V.push_back(&p5);
	//����
	for (vector<Person*>::iterator it = V.begin(); it != V.end(); it++) 
	{
		cout << "������" << (*it)->m_name << " :: " << "���䣺" << (*it)->m_age << endl;//��Ϊit�Ǹ�ָ��
	
	}
}

//�ģ�������Ƕ���������൱�ڶ�ά����
void test04() 
{
	vector<vector<int>>v;
	//����С������
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;
	//��С�����������
	for (size_t i = 0; i < 4; i++) 
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}
	//��С���������������
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	//ͨ�����������������ݱ���һ��
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) 
	{
		//(*it)--��������Ҫ����vector<int>  ��*it��������ֱ�ӿ�������������ʲô����
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) 
		{
			cout << *vit << " ";  //(*vit)--int
		}
		cout << endl;
	}

}

//�壺STL�г��õ�����������string�Ĺ��캯��
void test05() 
{
	string s1;//Ĭ�Ϲ���
	const char* str = "hello world";
	string s2(str);
	cout << "s2= " << s2 << endl;
	string s3(s2);//��������
	cout << "s3= " << s3 << endl;
	string s4(10, 'a');
	cout << "s4= " << s4 << endl;
}
//string�ĸ�ֵ����  �ȺŸ�ֵ����operator=����Ա������ֵ��assign
void test06() 
{
	string str1;
	str1 = "hello world";
	cout << "str1= " << str1 << endl;
	string str2;
	str2 = str1;
	cout << "str2= " << str2 << endl;
	string str3;
	str3 = 'a';
	cout << "str3= " << str3 << endl;
	string str4;
	str4.assign("hello c++");
	cout << "str4= " << str4 << endl;
	string str5;
	str5.assign("hello c++", 5);//��¼�ַ�����ǰ���
	cout << "str5= " << str5 << endl;
	string str6;
	str6.assign(str5);//������һ��str���丳ֵ
	cout << "str6= " << str6 << endl;
	string str7;
	str7.assign(10, 'w');
	cout << "str7= " << str7 << endl;
}
//string���ַ���ƴ��operator+=�����أ����г�Ա����append
void test07() 
{
	string str1 = "��";//�ַ���ƴ��
	str1 += "zzz";
	cout << "str1: " << str1 << endl;
	str1 += ':';
	cout << "str1: " << str1 << endl;
	string str2 = "LOL DNF";
	str1 += str2;
	cout << "str1: " << str1 << endl;

	string str3 = "I";
	str3.append(" LLL");
	cout << "str3: " << str3 << endl;
	str3.append(" game abcde", 4);
	cout << "str3: " << str3 << endl;
	str3.append(str2);
	cout << "str3: " << str3 << endl;
	str3.append(str2, 0, 3);//���㿪ʼ����ȡ����
	cout << "str3: " << str3 << endl;
}
int main() 
{
	test07();

	system("pause");
	return 0;
}