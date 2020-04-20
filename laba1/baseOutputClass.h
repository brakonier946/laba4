#pragma once

#include <string>
#include <iostream>

using namespace std;

class baseOutputClass {
public:
	virtual string writeToConsole() = 0;
};