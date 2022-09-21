// STL案例2-员工分类.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include<map>
#include<vector>
#include<ctime>//真随机数
#define CEHUA 0
#define MEISHU 1
#define YANFA 2
using namespace std;

class Worker 
{
public:
   /* Worker(string name,int salary) 
    {
        this->m_Name = name;
        this->m_Salary = salary;
    }*/
    string m_Name;
    int m_Salary;

};

void createWorker(vector<Worker>&wk) 
{
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++) 
    {
        Worker worker;
        worker.m_Name = "员工";
        worker.m_Name += nameSeed[i];
        worker.m_Salary = rand() % 10000 + 10000;//1~1.99w
        wk.push_back(worker);
    }
}

void myPrint(const vector<Worker>&wk) 
{
    for (vector<Worker>::const_iterator it = wk.begin(); it != wk.end(); it++)
    {
        cout << "姓名：" << it->m_Name << " " << "工资：" << it->m_Salary << endl;
    }
}
void setGroup(vector<Worker>&v,multimap<int,Worker>&m) 
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) 
    {
        //产生随机部门编号
        int deptId = rand() % 3;
        //将员工插入分组中  key是部门编号 *it是具体员工
        m.insert(make_pair(deptId, *it));

    }
}
void showWorkerByGourp(multimap<int,Worker>&mw) 
{
    cout << "策划部门：" << endl;
    multimap<int,Worker>::iterator pos=mw.find(CEHUA);
    int count = mw.count(CEHUA);//统计具体人数
    int index = 0;
    for (; pos != mw.end()&&index<count; pos++,index++) 
    {
        cout << "姓名：" << pos->second.m_Name << " " << "工资：" << pos->second.m_Salary << endl;
    }
    cout << "美术部门：" << endl;
     pos = mw.find(MEISHU);
    count = mw.count(MEISHU);//统计具体人数
     index = 0;
    for (; pos != mw.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.m_Name << " " << "工资：" << pos->second.m_Salary << endl;
    }

    cout << "研发部门：" << endl;
    pos = mw.find(YANFA);
    count = mw.count(YANFA);//统计具体人数
    index = 0;
    for (; pos != mw.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.m_Name << " " << "工资：" << pos->second.m_Salary << endl;
    }

}


int main()
{
    srand((unsigned int)time(NULL));//真随机
    //1：创建员工
    vector<Worker> vWorker;
    createWorker(vWorker);

    //2：员工分组
    multimap<int, Worker>mWorker;
    setGroup(vWorker,mWorker);

    //3：分组显示员工
    showWorkerByGourp(mWorker);

    //测试
   // myPrint(vWorker);


   // std::cout << "Hello World!\n";
    system("pause");
    return 0;
}


