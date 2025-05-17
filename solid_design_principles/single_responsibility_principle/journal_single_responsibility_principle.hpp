#pragma once
#include <string>
#include <vector>
using namespace std;

class journal {
public:
	string title;
	vector<string> entries;
	journal(const string &title) : title(title) {}

	void add_entry(const string& entry);
};