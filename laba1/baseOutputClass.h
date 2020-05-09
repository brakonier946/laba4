#pragma once

#include <string>
#include <iostream>

using namespace std;

class baseOutputClass {
public:
	virtual void writeToConsole() = 0;
};