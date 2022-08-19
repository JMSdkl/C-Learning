#pragma once
#include <iostream>
#include <string>
class MyArray {
public:
	MyArray();
	
	~MyArray();
	
	void push(int data);
	void travel();


private:
	int* p;
	int num;
};




