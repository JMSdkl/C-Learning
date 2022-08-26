// 职工管理系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <string>
#include <iostream>
#include "workerManager.h"
#include"Worker.h"
#include"employee.h"
#include "BOSS.h"
#include"Manager.h"
using namespace std;

int main()
{
    workerManager wk;
    int choice=0;
   /* Worker* wkk = new employee(18, "张三", 1);
    wkk->showInfo();
    delete wkk;
    Worker* wkkk = new Manager(2, "李四", 2);
    wkkk->showInfo();
    delete wkkk;
    Worker* wck = new Boss(3, "王五", 3);
    wck->showInfo();
    delete wck;*/

    while (true)
    {
        wk.Show_Menu();
        cout << "请输入您的选择：" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
            wk.exitsSystem();
            break;
        case 1:
            wk.AddEmp();
            break;
        case 2:
            wk.Show_Emp();
            break;
        case 3:
            wk.Del_Emp();
            break;
        case 4:
            wk.Mod_Emp();
            break;
        case 5:
            wk.Find_Emp();
            break;
        case 6:
            wk.Sort_Emp();
            break;
        case 7:
            wk.Clean_File();
            break;
        default:
            system("cls");
            break;
            
        }
    }

    system("pause");
    return 0;
}


