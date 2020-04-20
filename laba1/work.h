#pragma once

#include <iostream>
#include <fstream>
#include "myStack.h"
#include "univer.h"
#include "sortEnum.h"

using namespace std;

class work
{
private:
	string name_file = "data.txt";
public:
	myStack<univer> _data;

	void write();

	void read();

	void add();

	void print();

	void sort(typeSort);
};

