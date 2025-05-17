#include <iostream>
#include <boost/lexical_cast.hpp>
#include "journal_single_responsibility_principle.hpp"
using namespace boost;

void journal::add_entry(const string& entry)
{
	static int count = 1;
	entries.push_back(lexical_cast<string>(count++) + ": " + entry);
}
