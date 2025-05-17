#include <iostream>
#include <fstream>
#include <boost/lexical_cast.hpp>
#include "journal_single_responsibility_principle.h"
using namespace boost;

void journal::add_entry(const string& entry)
{
	static int count = 1;
	entries.push_back(lexical_cast<string>(count++) + ": " + entry);
}

void journal::save(const string& filename)
{
	ofstream ofs(filename);
	for (auto& e : entries)
	{
		ofs << e << endl;
	}
}