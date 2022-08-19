#pragma once
#include "Worker.h"
#include<iostream>
#include<string>
using namespace std;

class employee:public Worker
{public:
	employee(int id, string name, int dId);
	virtual void showInfo();
	virtual string getDeptName();
};

