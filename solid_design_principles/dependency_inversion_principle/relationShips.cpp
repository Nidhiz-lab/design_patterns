#include <fstream>
#include "relationShips.hpp"


void Relationships::add_parent_and_child(const Person& parent, const Person& child)
{
	this->relations.push_back({ parent , Relationship::parent, child });
	this->relations.push_back({ child , Relationship::child, parent });
}

vector<Person> Relationships::find_all_children_of(const string& name)
{
	vector<Person> result;
	for (auto&& [first, rel, second] : this->relations)
	{
		if (first.name == name && rel == Relationship::parent)
		{
			result.push_back(second);
		}
	}
	return result;
}





