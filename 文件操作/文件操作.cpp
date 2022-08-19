#include <iostream> //用了泛型，需要把所有东西都放在头文件里面
#include <string>
#include <fstream>

using namespace std;
//文本文件  写文件
void test01() 
{	//1.包含头文件
	//2.创建流对象
	ofstream ofs;
	//3.指定打开方式
	ofs.open("test.txt", ios::out);//不写详细路径，默认在项目底下
	//4.写内容
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;
	//5.关闭
	ofs.close();

}
//文本文件的  读文件
void test02() 
{	//1:包含头文件
	//2:创建流对象
	ifstream ifs;
	//3：打开文件，并判断是否打开
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()) 
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//4：读数据
	////第一种
	//char buf[1024] = { 0 };
	//while (ifs>>buf)
	//{
	//	cout << buf << endl;
	//}
	// 第二种
	/*char buf[1024] = { 0 };
	while (ifs.getline(buf,sizeof(buf)))
	{
		cout << buf << endl;
	}*/
	////第三种
	//string buf;
	//while (getline(ifs,buf))
	//{
	//	cout << buf << endl;
	//}
	//第四种
	//char c;
	//while ((c=ifs.get())!=EOF)//EOF是指文件尾  .get()是一个个读取
	//{
	//	cout << c;
	//}
	//5：关闭
	
	ifs.close();
}
//二进制写文件
class Person 
{public:
	char m_Name[64];
	int m_Age;

};

void test03()
{
	ofstream ofs;
	ofs.open("person.txt", ios::out | ios::binary);//已二进制的方式写
	Person p = { "张三",18 };
	ofs.write((const char*)&p, sizeof(Person));
	ofs.close();
}
void test04() 
{
	//1:包含头文件
	//2：创建流对象
	ifstream ifs;
	//3：打开文件，判断是否打开成功
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open()) 
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//4:读文件
	Person p;
	ifs.read((char*)&p, sizeof(Person));//因为read内置方法是需要传入一个地址，所以要（&p），而类型是（char *）所以要强转
	cout << "姓名：" << p.m_Name << " 年龄：" << p.m_Age << endl;
	//5：关闭文件

}
int main() 
{
	//test02();
	test04();
	system("pause");
	return 0;

}