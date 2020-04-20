#include "work.h"
#include "myStack.h"
#include "univer.h"
#include <iostream>
#include <fstream>
#include "sortEnum.h"
#include <string>

using namespace std;

void work::read() {
	_data = myStack<univer>();

	ifstream in(name_file, ios::in | ios::binary);

	in.read((char*)&_data, sizeof(myStack<univer>));

	in.close();
}

void work::write() {
	ofstream os(name_file, ios::out | ios::binary);
	os.write((char*)&_data, sizeof(myStack<univer>));
	os.close();
}

void work::add() {
	_data.push(univer::createFromConsole());
}

void work::print() {
	_data.show();
}

void work::sort(typeSort tSort) {
	auto head = _data.getLastNode();
	while (head) {
		head->data.sortedVariable = tSort;
		head = head->prev;
	}
	_data.sort();
}