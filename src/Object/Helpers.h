#pragma once
#include <vector>
#include <string>

#ifndef HELPERS_HEADERS_
	#define HELPERS_HEADERS_
	std::vector<std::string> SplitString(std::string text, char delim = ' ', bool ignoreEmpty = true);
	std::string JoinString(std::vector<std::string> strings, char delim);
	int FindInVector(std::vector<int> v, int value);
#endif