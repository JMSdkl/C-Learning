#include <iostream>
#include<string>
using namespace std;
//实现普通页面

//Java页面
//class Java {
//public:
//	void header() {
//		cout << "首页、公开课、登录、注册。。（公共头部）" << endl;
//	
//	}
//	void footer() {
//		cout << "帮助中心、交流合作、站内地图。。（公共底部）" << endl;
//
//	}
//	void left() {
//		cout << "Java、Python、C++。。（公共分类列表）" << endl;
//
//	}
//	void content() {
//		cout << "Java学科视频" << endl;
//
//	}
//
//};
//class Python
//{
//public:
//	void header() {
//		cout << "首页、公开课、登录、注册。。（公共头部）" << endl;
//
//	}
//	void footer() {
//		cout << "帮助中心、交流合作、站内地图。。（公共底部）" << endl;
//
//	}
//	void left() {
//		cout << "Java、Python、C++。。（公共分类列表）" << endl;
//
//	}
//	void content() {
//		cout << "Python学科视频" << endl;
//
//	}
//
//};
//class Cpp
//{
//public:
//	void header() {
//		cout << "首页、公开课、登录、注册。。（公共头部）" << endl;
//
//	}
//	void footer() {
//		cout << "帮助中心、交流合作、站内地图。。（公共底部）" << endl;
//
//	}
//	void left() {
//		cout << "Java、Python、C++。。（公共分类列表）" << endl;
//
//	}
//	void content() {
//		cout << "C++学科视频" << endl;
//
//	}
//
//};

//***********继承实现页面************//
class BasePage
{public:
		void header() {
		cout << "首页、公开课、登录、注册。。（公共头部）" << endl;

	}
	void footer() {
		cout << "帮助中心、交流合作、站内地图。。（公共底部）" << endl;

	}
	void left() {
		cout << "Java、Python、C++。。（公共分类列表）" << endl;

	}
};
//语法：class 子类：继承方式  父类

//Java页面：
class Java :public BasePage //继承
{
public:
	void content()
	{
		cout << "Java学科的视频" << endl;
	}


};


//Python页面：
class Python :public BasePage //继承
{
public:
	void content()
	{
		cout << "Python学科的视频" << endl;
	}


};
//C++页面：
class Cpp :public BasePage //继承
{
public:
	void content()
	{
		cout << "Cpp学科的视频" << endl;
	}


};

void test01() {
	cout << "Java下载视频页面如下：" << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "----------------" << endl;
	cout << "Python下载视频页面如下：" << endl;
	Java py;
	py.header();
	py.footer();
	py.left();
	py.content();
	cout << "----------------" << endl;
	cout << "cpp下载视频页面如下：" << endl;
	Java cpp;
	cpp.header();
	cpp.footer();
	cpp.left();
	cpp.content();
}


int main() {

	test01();



	system("pause");
	return 0;

}