#include<iostream>
#include<string>
#include<algorithm>//标准算法的头文件
#include<vector>
using namespace std;
//一：容器初识
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
	//通过迭代器访问容器中数据
	//vector<int>::iterator itBegin = V.begin();//起始迭代器，指向容器中第一个元素
	//vector<int>::iterator itEnd = V.end();//指向容器中最后一个元素的下一个位置
	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	//常用遍历  //与上类似
	for (vector<int>::iterator it = V.begin(); it != V.end(); it++) 
	{
		cout << *it << endl;
	}
	//第三种遍历方式 利用stl的遍历算法
	for_each (V.begin(), V.end(), myPrint);//利用回调函数
	

}

//二：vector容器中存放自定义数据类型
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
	//遍历容器中的数据
	for (vector<Person>::iterator it = V.begin(); it != V.end(); it++) //it解引用，出来的是person的数据类型
	{
		cout << "姓名：" << (*it).m_name << " " << "年龄：" << it->m_age << endl;//因为it是个指针
	}

}
//三：存放自定义数据类型的指针
void test03() 
{
	vector<Person*>V;//相当于容器中存放的是各个对象的地址
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
	//遍历
	for (vector<Person*>::iterator it = V.begin(); it != V.end(); it++) 
	{
		cout << "姓名：" << (*it)->m_name << " :: " << "年龄：" << (*it)->m_age << endl;//因为it是个指针
	
	}
}

//四：容器中嵌套容器：相当于二维数组
void test04() 
{
	vector<vector<int>>v;
	//创建小容器：
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;
	//向小容器添加数据
	for (size_t i = 0; i < 4; i++) 
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}
	//将小容器插入大容器中
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	//通过大容器把所有数据遍历一次
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) 
	{
		//(*it)--容器，还要遍历vector<int>  （*it）的类型直接看尖括号里面是什么内容
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) 
		{
			cout << *vit << " ";  //(*vit)--int
		}
		cout << endl;
	}

}

//五：STL中常用的类型容器：string的构造函数
void test05() 
{
	string s1;//默认构造
	const char* str = "hello world";
	string s2(str);
	cout << "s2= " << s2 << endl;
	string s3(s2);//拷贝构造
	cout << "s3= " << s3 << endl;
	string s4(10, 'a');
	cout << "s4= " << s4 << endl;
}
//string的赋值操作  等号赋值法和operator=，成员函数赋值法assign
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
	str5.assign("hello c++", 5);//记录字符串的前五个
	cout << "str5= " << str5 << endl;
	string str6;
	str6.assign(str5);//利用另一个str给其赋值
	cout << "str6= " << str6 << endl;
	string str7;
	str7.assign(10, 'w');
	cout << "str7= " << str7 << endl;
}
//string的字符串拼接operator+=的重载，还有成员函数append
void test07() 
{
	string str1 = "我";//字符串拼接
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
	str3.append(str2, 0, 3);//从零开始，截取三个
	cout << "str3: " << str3 << endl;
}
int main() 
{
	test07();

	system("pause");
	return 0;
}