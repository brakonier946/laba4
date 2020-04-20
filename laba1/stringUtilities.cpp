#include "stringUtilities.h"
#include <vector>
#include <string>
#include <iostream>
#include <regex>

using namespace std;

vector<string> stringUtilities::split(string data, string delimiter) {
	std::regex regex(delimiter);

	std::vector<std::string> out(
		std::sregex_token_iterator(data.begin(), data.end(), regex, -1),
		std::sregex_token_iterator()
	);

	return out;
}