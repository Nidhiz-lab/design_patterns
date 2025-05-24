#pragma once
#include<iostream>
#include<vector>
#include <tuple>
using namespace std;

enum class Relationship 
{
	parent,
	child,
	sibling
};

class Person {
public:
	string name;
};

class RelationshipBrowser
{
public:
	virtual vector<Person> find_all_children_of(const string& name) = 0;
};


class Relationships : public RelationshipBrowser  // LOW level
{
public:
	vector<tuple<Person, Relationship, Person>> relations;
	Relationships(){}
	void add_parent_and_child(const Person& parent, const Person& child);
	vector<Person> find_all_children_of(const string& name) override;
};

class Research	// High level
{
public:
	Research(Relationships& browser)
	{
		for (auto& child : browser.find_all_children_of("Jhon"))
		{
			cout << "Jhon has a child called " << child.name << endl;
		}
	}
};





