#include "Helpers.h"

std::vector<std::string> SplitString(std::string text, char delim, bool ignoreEmpty)
{
    using namespace std;

    int lastDelim = 0;
    int foundDelim;
    vector<string> result;

    while (1) {
        foundDelim = text.find(delim, lastDelim);
        if (foundDelim == string::npos) {
            if (text.length() != lastDelim || !ignoreEmpty) {
                result.push_back(text.substr(lastDelim, text.length() - lastDelim));
            }
            break;
        }
        if (foundDelim != lastDelim || !ignoreEmpty) {
            result.push_back(text.substr(lastDelim, foundDelim - lastDelim));
        }
        lastDelim = foundDelim + 1;
    }

    return result;
}

std::string JoinString(std::vector<std::string> strings, char delim)
{
    if (strings.size() > 0) {
        std::string result = strings.at(0);
        for (int i = 1; i < strings.size(); i++) {
            result = result + delim + strings.at(i);
        }
        return result;
    }
    return std::string();
}

int FindInVector(std::vector<int> v, int value)
{
    for (int i = 0; i < v.size(); i++) {
        if (v.at(i) == value) return i;
    }
    return -1;
}
