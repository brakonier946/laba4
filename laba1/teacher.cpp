#include "teacher.h"
#include <iostream>
#include <string>
#include "stringUtilities.h"

using namespace std;

teacher teacher::createFromConsole() {
	teacher t;

	cout << "	write data about teacher:" << endl;
	cout << "		name: ";
	cin >> t.name;

	cout << "		surname: ";
	cin >> t.surname;

	cout << "		patronymic: ";
	cin >> t.patronymic;

	return t;
}

teacher teacher::createFromFile(string data) {
	teacher t;

	auto dataSplitted = stringUtilities::split(data, t.delimiter);

	t.name = dataSplitted.at(0);
	t.surname = dataSplitted.at(1);
	t.patronymic = dataSplitted.at(2);

	return t;
}

string teacher::toFileString() {
	return name + delimiter + surname + delimiter + patronymic;
}

string teacher::writeToConsole() {
	return
		"	name: " + name + "\n" +
		"	surname: " + surname + "\n" +
		"	patronymic: " + patronymic + "\n";
}