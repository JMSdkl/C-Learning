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
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        default:
            system("cls");
            break;
            
        }
    }

    system("pause");
    return 0;
}


