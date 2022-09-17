#include <string>
#include <iostream>
#include "workerManager.h"

using namespace std;

workerManager::workerManager() 
{

	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) 
	{
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;//员工人数为0
		this->m_EmpArray = NULL;//员工指针为空
		this->m_FileIsEmpty = true;//文件不存在
		ifs.close();
		return;
	}
	//文件存在，但是数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) 
	{
		//文件为空
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;//员工人数为0
		this->m_EmpArray = NULL;//员工指针为空
		this->m_FileIsEmpty = true;//文件不存在
		ifs.close();
		return;

	}
	//文件存在，并且记录数据
	int num = this->get_EmpNum();
	cout << "职工人数为： " << num << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];//开辟了i个成员的指针数组
	//将文件中的数据存到数组中
	this->init_Emp();
	/*for (int i = 0; i < this->m_EmpNum; i++) 
	{
		cout << "职工编号: " << this->m_EmpArray[i]->m_Id
			<<" " << "姓名: " << this->m_EmpArray[i]->m_Name
			<<" " << "部门编号: " << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
	

}

workerManager::~workerManager() 
{
	if (this->m_EmpArray != NULL)
	{
		//删除堆区的每个对象
		for (size_t i = 0; i < this->m_EmpNum; i++)
		{
			delete this->m_EmpArray[i];
			this->m_EmpArray[i] = NULL;//对象置空
		}
		//删除堆区数组指针
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
		
	}
	
}

void workerManager::Show_Menu() 
{
	cout << "***********************************************" << endl;
	cout << "*************欢迎使用职工管理系统**************" << endl;
	cout << "***************0.退出管理程序******************" << endl;
	cout << "***************1.增加职工信息******************" << endl;
	cout << "***************2.显示职工信息******************" << endl;
	cout << "***************3.删除离职职工******************" << endl;
	cout << "***************4.修改职工信息******************" << endl;
	cout << "***************5.查找职工信息******************" << endl;
	cout << "***************6.按照编号排序******************" << endl;
	cout << "***************7.清空所有文档******************" << endl;
	cout << "***********************************************" << endl;
	cout << endl;
}
void workerManager::exitsSystem() 
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出程序用的
}
void workerManager::AddEmp() 
{
	cout << "请输入添加职工的数量：" << endl;
	int addNum = 0;//保存用户的输入数量
	cin >> addNum;
	if (addNum > 0) 
	{	//添加
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;//新空间人数=原来记录的人数+新增人数
		//开辟新空间
		Worker ** newSpace=new Worker* [newSize];
		//将原来空间下的数据，拷贝到新空间下
		if (this->m_EmpArray != NULL) 
		{
			for (int i = 0; i < this->m_EmpNum; i++) 
			{
				newSpace[i] = this->m_EmpArray[i]; //存的是指针
			}
		}
		//批量添加新数据
		for (int i = 0; i < addNum; i++) 
		{
			int id;//职工编号
			string name;//职工姓名
			int dSelect;//部门选择
			cout << "请输入第" << i + 1 << "个新职工编号" << endl;
			cin >> id;
			for (size_t j = 0; j < this->m_EmpNum; j++) //防止不了一直输入重复的id
			{											//感觉需要嵌套一个可以返回布尔量的函数
														//然后做一个while循环
				if (id == this->m_EmpArray[j]->m_Id)	//只要进入了if条件就一定要输入不同的id
				{ 
					cout << "输入了重复的id号" << endl;
					cout<<"请重新输入第"<< i + 1 << "个新职工编号" << endl;
					cin >> id;
					break;                              //防止误输入
				}
			}
			cout << "请输入第" << i + 1 << "个新职工姓名" << endl;
			cin >> name;
			cout <<  "请选择该职工岗位编号" << endl;
			cout << "1:普通职工" << endl;
			cout << "2:经理" << endl;
			cout << "3:老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new employee(id,name,1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;

			default:
				break;
			}
			//将创建的职工指针，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		
		}
		//释放原有的空间
		delete[] this->m_EmpArray;
		//更改新空间的指向
		this->m_EmpArray = newSpace;
		//更新新的职工人数
		this->m_EmpNum = newSize;

		this->m_FileIsEmpty = false;//成功添加职工后，文件就不为空

		//成功添加后应该要保存到文件中

		this->save();
		//添加完成
		cout << "成功添加" << addNum << "名新职工" << endl;

	}
	else
	{
		cout << "输入数据有误" << endl;
	}
	//按任意键继续，且返回上一目录
	system("pause");
	system("cls");

}

void workerManager::save() 
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件 --写文件
	//将每个人数据写入到文件中
	for (size_t i=0; i < this->m_EmpNum; i++) 
	{
		ofs << this->m_EmpArray[i]->m_Id << "  " << this->m_EmpArray[i]->m_Name << "  " << this->m_EmpArray[i]->m_DeptId << endl;
		             //m_EmpArray[i]是一个类对象了，可以使用里面的成员
	}
	ofs.close();


}

int  workerManager::get_EmpNum() 
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件   读
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs>>id&&ifs>>name&&ifs>>did)
	{
		//统计人数
		num++;
	}
	ifs.close();
	return num;
}

//初始化员工
void workerManager::init_Emp() 
{	
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs>>id&&ifs>>name&&ifs>>did)
	{
		Worker* worker = NULL;
		if (did == 1)//普通员工
		{
			worker = new employee(id, name, did);
		}
		else if (did == 2)//普通员工
		{
			worker = new Manager(id, name, did);
		}
		else//普通员工
		{
			worker = new Boss(id, name, did);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();

}

void workerManager::Show_Emp() 
{
	//判断文件是否为空
	if (this->m_FileIsEmpty) 
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++) 
		{
			//利用多态
			this->m_EmpArray[i]->showInfo();
		}
	}
	//按键后清屏
	system("pause");
	system("cls");
}
int workerManager::IsExit(int id) 
{
	int index = -1;
	for (size_t i = 0; i < this->m_EmpNum; i++) 
	{
		if (this->m_EmpArray[i]->m_Id == id) 
		{//找到职工了
			index = i;
			break;
		}
	}
	return index;
}

void  workerManager::Del_Emp() 
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		//按照职工变换删除
		cout << "请输入想要删除的职工编号：" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExit(id);
		if (index != -1)//说明职工存在，并且要删除index位置上的职工
		{
			//数据前移
			for (size_t i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//更新记录的人员数据
			//数据同步到文件中
			this->save();
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

void workerManager::Mod_Emp() 
{
	if (this->m_FileIsEmpty) 
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;
		int ret = this->IsExit(id);
		if (ret != -1) 
		{
			//找到这个编号的职工
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "查找到：" << id << "号职工，请输入新的职工号：" << endl;
			cin >> newId;
			cout << "请输入新姓名" << endl;
			cin >> newName;
			cout << "请输入新的岗位" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			//更新数据到数组中
			this->m_EmpArray[ret] = worker;
			cout << "修改成功" << endl;
			//保存到文件中
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人！" << endl;
		}
	}

	system("pause");
	system("cls");

}

void workerManager::Find_Emp() 
{
	if (this->m_FileIsEmpty) 
	{
		cout << "文件不存在，或者记录为空" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按照职工编号查找：" << endl;
		cout << "2、按照职工姓名查找：" << endl;
		int Select = 0;
		cin >> Select;
		if (Select == 1) 
		{//按编号查
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;
			int ret=IsExit(id);
			if (ret != -1) 
			{
				cout << "查找成功！该职工信息如下" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败" << endl;
			}
		}
		else if (Select==2)
		{
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;
			//加入判断是否查到的标志
			bool flag = false;
			for (size_t i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，职工编号为：" 
						<< this->m_EmpArray[i]->m_Id
						<<"号职工信息如下："<<endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false) 
			{
				cout << "查找失败" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}
	system("pause");
	system("cls");
}

void workerManager::Sort_Emp() 
{
	if (this->m_FileIsEmpty) 
	{
		cout << "文件不存在或者记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++) 
		{
			int minOrmax = i;
			//cout <<"头：" << minOrmax << endl;
			for (int j = i + 1; j < this->m_EmpNum; j++) 
			{
			if (select == 1)//
			{
				if (this->m_EmpArray[minOrmax]->m_Id > this->m_EmpArray[j]->m_Id) 
				{
					minOrmax = j;
				}
			}
			else//
			{
				if (this->m_EmpArray[minOrmax]->m_Id < this->m_EmpArray[j]->m_Id)
				{
					minOrmax = j;
				}
			}
			}
			//cout << "尾：" << minOrmax << endl;
			if (i != minOrmax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrmax];
				this->m_EmpArray[minOrmax] = temp;
			}

		}
		
	cout << "排序成功！排序后的结果为：" << endl;
	this->save();//排序后的结果保存
	this->Show_Emp();
	}
}

void workerManager::Clean_File() 
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) 
	{
		ofstream ofs(FILENAME,ios::trunc);//删除文件后重建
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			//删除堆区的每个对象
			for (size_t i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;//对象置空
			}
			//删除堆区数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}