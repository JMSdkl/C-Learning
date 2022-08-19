#include <iostream>
#include <string>

using namespace std;

struct student {
	string name = "klj";
	int age = 10;
	int score = 60;
};

struct teacher
{
	int id;
	string name;
	int age;
	student stu;

};
const int MAX = 3;
void BubbleSort(int* arr, int len);
void printArray(int* arr, int len);
void printstudent(student s);
void printstudent2(student* p);

int* func() {
//在堆区创建整型数据
	int* p = new int(10);
	return p;

}

void test01() {
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	delete p;//释放内存的关键字

}

void test02() {
	//在堆区创建10个数据的数组
	int* arr=new int[10];//10是指有十个元素   返回的是连续空间的首地址

	for (int i = 0; i < 10; i++) {
		arr[i] = i + 100;
		cout << arr[i] << endl;
	
	}
	//释放堆区的数组
	delete[] arr;//加上[]是提示要释放一段长的空间


}

int swapp(int& a, int& b) {//&a是下面输入函数的别名
	int temp = a;
	a = b;
	b = temp;
	return 0;
}

int& test() {//返回引用的函数可以作为左值
	static int a = 10;
	return a;

}

void fun(int& a) {//int &a=10,不合法
	cout << "func(int& a)调用" << endl;

}

void fun(const int& a) {//const int& a=10  编译器会自动合法化（产生一个空的中间项）
	cout << "func(const int& a)调用" << endl;

}

//函数重载碰到默认参数//语法可以通过，但编译不通过
void func2(int a) {

	cout << "func2(int a)调用" << endl;
}

void func2(int a,int b=10) {

	cout << "func2(int a,int b=10)调用" << endl;
}

class Point {

public:
	void setX(int x) {
		m_x = x;
	}
	int getX() {
		return m_x;
	}
	void setY(int y) {
		m_y = y;
	}
	int getY() {
		return m_y;
	}

private:
	int m_x;
	int m_y;


};

class Circle
{
public:						//成员在类内可以访问，类外也可以访问
	int m_r;				//成员属性，成员变量                   //统称为成员
	double calculateZC() {	//成员行为，成员方法
		return 2 * 3.14 * m_r;
	}													//在继承里有区别

	void setR(int r) {
		m_R = r;
	}
	int getR() {
		return m_R;
	}
	void setcenter(Point center) {
		m_Center = center;
	}
	Point getcenter() {
		return m_Center;
	}


private:					//私有权限  //成员在类内可以访问，类外不可以访问  //儿子不可以访问父亲中私有的内容
	int m_R;
	Point m_Center;

protected:					//保护权限  //成员在类内可以访问，类外不可以访问   //儿子也可以访问父亲中保护的内容



};

//判断点圆的位置关系
void isincircle(Circle& c, Point& p) {
	int DISTANCE = (c.getcenter().getX() - p.getX()) * (c.getcenter().getY() - p.getY()) + (c.getcenter().getY() - p.getY()) * (c.getcenter().getY() - p.getY());
	int Rdiatance = c.getR() * c.getR();

	if (Rdiatance == DISTANCE) {
		cout << "在圆上" << endl;
	
	}

}

class person {
public:
	person() {//构造函数
		cout << "person 无参构造函数的调用" << endl;
	}
	person(int a,int height) {

		
		age = a;
		m_height=new int(height);//在堆区创造数据要用指针接收
		cout << "person 有参构造函数的调用" << endl;
	
	}
	//拷贝构造函数,自己构造的拷贝构造函数可以解决浅拷贝的问题，编译器默认的是浅拷贝
	person(const person &p) {
		//将传入的人身上的所有属性，拷贝到我身上
		age = p.age;
		//m_height = p.m_height;//浅拷贝就是类似这样的操作
		//深拷贝操作
		m_height=new int(*p.m_height);//在堆区重新创建了内存
		cout << "person 拷贝构造函数的调用" << endl;
	}


	//析构函数记得加  ~  不可以有参数
	~person() {//将堆区开劈的数据可以释放
		if (m_height != NULL) {
			delete m_height;
			m_height = NULL;//防止野指针出现
		
		}
		cout << "person 析构函数的调用" << endl;
	
	}
	int age;
	int* m_height;
};
//构造和析构都是必须有的，如果不提供编译器会自行提供
//void test111() {
//	person p1(20);//在站上的数据，test111在执行完之后会释放，所以会调用对象的析构函数
//	person p2(p1);//把p1的数据都拷过来
//	cout << "person p2的年龄为：" << p2.age << endl;
//}
void doWork(person p) {

}
void test0001() {
	person p1(18,160);
	cout << "p1年龄为：" << p1.age << endl;
	cout << "p1身高为：" << *p1.m_height << endl;
	person p2(p1);//编译器自动提供的拷贝构造函数，是一个浅拷贝
	cout << "p2年龄为：" << p2.age << endl;
	cout << "p2身高为：" << *p2.m_height << endl;
}


//person dowork() {
//	person p1(10);
//	return p1;//返回时会调用拷贝构造函数
//}

void test002() {
	person p;
	doWork( p);//值传递相当于隐式转换法
	//实参传递给行参时会调用拷贝构造函数
}
//void test003() {
//	person p1= dowork();
//	
//	cout << "person p1的年龄为：" << p1.age << endl;
//
//}


//void test113() {
//	//括号法
//	//person p;//默认构造函数的调用
//	//person p2(10);//会调有参构造函数（括号法）
//	//person p3(p2);//会调拷贝构造函数
//
//	//显示法
//	//person p1;
//	//person p2 = person(10);//调用有参构造
//	//person p3 = person(p2);//调用拷贝构造
//	//person(10);
//	//cout << "aaaa" << endl;
//	//隐式转换法
//	person p4 = 10;//相当于person p4 = person(10)
//	person p5 = p4;
//}

int main()
{
	/*int a, b, c;*/
	//int  var[3] = { 10, 100, 200 };
	//int *p;
	//p = var;
	//for (int i = 0; i < 3; i++)
	//{
	//	    // 这是正确的语法
	//	//var++;       // 这是不正确的
	//	std::cout << *(p + i) << std::endl;
	//	std::cout << (*p + i) << std::endl;
	//}
	//std::cout << var[0] << std::endl;
	//for (int i = 100; i < 1000; i++) {
	//
	//	a = i % 10;//获得个位
	//	b = i / 10 % 10;//获得十位
	//	c = i / 100;//获得百位
	//	if (a*a*a+b*b*b+c*c*c==i) {

	//		std::cout << i << std::endl;
	//	}
	//	/*std::cout << i << std::endl;*/
	//
	//}
	//for (int i = 1; i <= 100; i++) {//把可以整除7以及个位有7、十位有7的不打印出来
	//	if ((i % 10)!=7  && i % 7&&(i/10%10)!=7) {
	//		std::cout << i << std::endl;
	//	}
	//	else {
	//		
	//	
	//		std::cout << "1212112" << std::endl;
	//	}
	//
	//
	//}
	/*for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= i;j++) {
			std::cout << j << "*" << i << "=" << j * i<<"\t"  ;

		}

		cout << endl;

	}*/

	//**********************************数组元素倒置********************************//

	/*int arr[5] = { 1,2,3,4,5 };
	int start, end;
	start = 0;
	end = sizeof(arr) / sizeof(arr[0]) - 1;
	while (start<end)
	{
		int temp;
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++) {

		cout << arr[i] << endl;
	}
	*/
	//**********************************冒泡排序********************************//

	//int arr[9] = { 4,2,8,6,5,7,3,9,1 };     
	//for (int i = 0; i < 9 - 1; i++)		  //排序总轮数=元素个数-1								
	//{
	//	for (int j = 0; j < 9 - i - 1; j++) {  //内层循环对比次数=元素个数-当前轮数-1
	//	
	//		if (arr[j] > arr[j + 1]) {
	//			int temp=arr[j];
	//			arr[j] = arr[j + 1];
	//			arr[j + 1] = temp;
	//		}
	//	
	//	}

	//}
	//for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {

	//	cout << arr[i] << endl;
	//}
	//****************************指针遍历数组**************************************//
	/*int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int *p2=arr;
	for (int i = 0; i < 10; i++) {
		cout << *p2 << endl;
		p2++;

	}*/

	//****************************指针数组函数**************************************//
	/*int arr[10] = { 7,2,10,4,5,6,1,8,3,9 };

	int len = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr,len);
	printArray(arr, len);*/
	//****************************结构体**************************************//
	/*student s1;

	s1.name = "张四";
	s1.age = 100;

	cout << s1.name << s1.age << endl;*/

	//****************************结构体数组**************************************//
	/*student stuarray[3] = {
		{"张三",18,100},
		{"lli",22,55}
	};
	stuarray[2].name = "kjl";
	for (size_t i = 0; i < 3; i++)
	{
		cout << stuarray[i].name << stuarray[i].age << endl;
	}*/
	//****************************结构体指针**************************************//
	//student s = { "zxc",12,100 };
	//student *p = &s;
	//cout << p->name << endl;//指针访问结构体的方法：->
	//****************************结构体嵌套结构体**************************************//
	/*teacher t;
	t.id = 1000;
	t.name = "laowang";
	t.age = 50;
	t.stu.name = "xiaowang";
	t.stu.age = 10;
	t.stu.score = 50;
	cout << t.name << t.age << t.id << t.stu.age << t.stu.score << endl;*/
	//****************************结构体做函数参数**************************************//
	/*student z;
	printstudent(z);//这样用值传递每次都要把结构体中全部东西复制一次数据量大
	printstudent2(&z);//传地址，可以减少内存空间占用 但是在子函数里面改变东西，外面的值也会边，所以用常量指针，可修改指向而不修改值*/
	//****************************new和delete使用**************************************//

	/*test01();
	test02();*/
	
	//****************************普通引用的使用**************************************//
	/*int a, b;
	a = 10;
	b = 20;
	swapp(a, b);
	cout << a << b << endl;*/
	//****************************引用的函数调用方式使用**************************************//
	//int& ref2 = test();
	//cout << ref2 << endl;
	//test() = 1000;//函数调用可以作为左值
	//cout << ref2 << endl;
	//****************************常量引用的原理**************************************//
	//int a = 10;
	////变成常量指针常量了
	//const int& c = 10;//加const之后编译器自动创造了一个临时空间temp
	//int& b = a;
	 
	//****************************函数重载：引用作为重载条件**************************************//
	/*int a = 10;
	fun(a);
	fun(10);*/
	//****************************类和对象封装**************************************************//

	////通过圆类创建具体的圆
	//Circle c1;//实例化
	//c1.m_r = 10;
	//cout << "圆的周长" << c1.calculateZC() << endl;

	//****************************构造函数和析构函数**************************************************//

	//test111();//自动调用的构造函数了
	//person q;//只有构造没有析构，因为q这个对象暂时不会被释放，到pause过后才会调用析构函数

	//****************************构造函数分类以及调用**************************************************//
	/*test0001();*/
	
	system("pause");
	return 0;
}

void printstudent2(student* p) {

	cout << p->name << p->age << endl;

}


void printstudent(student s) {

	cout << s.name << s.age << s.score << endl;


}

void printArray(int* arr, int len) {

	for (int i = 0; i < len; i++) {
		cout << arr[i] << endl;
	}

}

void BubbleSort(int* arr, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}