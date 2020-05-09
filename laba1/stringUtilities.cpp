#include "stringUtilities.h"
#include <string>
#include <iostream>
#include <regex>
#include "myStack.h"

using namespace std;

myStack<char*> stringUtilities::split(string data, char delimiter) {
	myStack<char*> m;

	size_t pos = 0;
	std::string token;
	while ((pos = data.find(delimiter)) != std::string::npos) {
		token = data.substr(0, pos);
		m.push(_strdup(token.c_str()));
		data.erase(0, pos + 1);
	}

	if (data != "")
		m.push(_strdup(data.c_str()));

	myStack<char*> temp;

	auto head = m.getLastNode();
	while (head) {
		temp.push(head->data);
		head = head->prev;
	}

	return temp;
}