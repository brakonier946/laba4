#pragma once

#include <string>
#include <iostream>
#include "myStack.h"

using namespace std;

class stringUtilities {
public:
	static myStack<char*> split(string data, char delimiter);
};

