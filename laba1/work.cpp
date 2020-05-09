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

	univer u;
	while (in.read((char*)&u, countWritedCharacter)) {
		_data.push(u);
	}

	in.close();
}

void work::write() {

	ofstream os;

	os.open(name_file, ios::out | ios::binary);

	auto head = _data.getLastNode();
	while (head) {
		os.write((char*)&head->data, sizeof(univer));

		head = head->prev;
	}

	os.close();
}

void work::add() {
	_data.push(univer::createFromConsole());
}

void work::print() {
	ifstream in(name_file.c_str(), ios_base::binary);

	cout << "		PRINT DATA FROM FILE" << endl;

	univer u;
	while (in.read((char*)&u, sizeof(univer))) {
		u.writeToConsole();
		cout << endl;
	}

	in.close();
}

void work::sort(typeSort tSort) {
	fstream file(name_file, ios::in | ios::out | ios::binary);

	file.seekg(0, ios::end);
	int d = sizeof(univer);
	int k = file.tellg();
	int maxElements = file.tellg() / sizeof(univer);
	file.seekg(0, ios::beg);
	int i = 0;
	int countShiftObjects = 0;
	bool isEndFile = false;
	while (true) {
		
		int d = file.tellg();
		if (isEndFile) {
			if (countShiftObjects == 0)
				break;
			i = 0;
			countShiftObjects = 0;
			file.seekg(0, ios::beg);
			isEndFile = false;
		}

		int seekPosition = (int)(i / 2) * sizeof(univer);
		file.seekg(seekPosition, ios::beg);

		d = file.tellg();

		univer first;
		univer second;

		if (file.read((char*)&first, sizeof(univer)))
			i++;
		else
			isEndFile = true;
		d = file.tellg();
		if (d != k) {
			if (file.read((char*)&second, sizeof(univer)))
				i++;
		}
		else
			isEndFile = true;

		d = file.tellg();
		if (!isEndFile) {
			if (second < first) {
				file.seekg(seekPosition, ios::beg);

				file.write((char*)&second, sizeof(univer));
				file.write((char*)&first, sizeof(univer));

				countShiftObjects++;
			}
		}

		d = file.tellg();

	}

	file.close();
}

void work::printAt(int index) {
	ifstream file(name_file, ios::in | ios::binary);

	file.seekg(0, ios::end);
	int maxCount = file.tellg() / sizeof(univer);
	file.seekg(0, ios::beg);

	if (index > maxCount - 1 || index < 0) {
		cout << endl << "verify your idex" << endl;
		return;
	}

	int seekPosition = index * sizeof(univer);
	file.seekg(seekPosition);
	univer u;
	file.read((char*)&u, sizeof(univer));
	cout << endl;
	u.writeToConsole();
	cout << endl;

	file.close();
}