#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "teacher.h"
#include "baseOutputClass.h"
#include "myStack.h"
#include "sortEnum.h"

using namespace std;

class univer : public baseOutputClass {

private:
	string delimiter = "_";
public:
	string name;
	int number_of_faculties;
	int number_of_graduates;
	myStack<teacher> teachers;
	typeSort sortedVariable;

	void addTeacher(teacher t);

	string printToFile();
	string writeToConsole();
	int getValueSortedProperty();

	static univer createFromFile(string data);

	static univer createFromConsole();

	friend ostream& operator << (ostream& output, univer& u) {
		output << u.printToFile();
		return output;
	}

	friend bool operator >= (univer& first, univer& second) {
		return first.getValueSortedProperty() >= second.getValueSortedProperty();
	}

	friend bool operator <= (univer& first, univer& second) {
		return first.getValueSortedProperty() <= second.getValueSortedProperty();
	}
};