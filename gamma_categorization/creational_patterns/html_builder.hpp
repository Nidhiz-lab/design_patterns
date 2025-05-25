#pragma once
#include<iostream>
#include<sstream>
#include<vector>
using namespace std;


class HtmlElement 
{
	friend class HtmlBuilder;
	string name, text;
	vector<HtmlElement> elements;

	const size_t indent_size = 2;

	HtmlElement() {}
	HtmlElement(const string &name, const string &text): name(name), text(text){ }
public:
	string str(int indent) const;
	static HtmlBuilder create(string root_name);

};

class HtmlBuilder
{
	HtmlElement root;
public:
	HtmlBuilder(string root_name)
	{
		root.name = root_name;
	}

	HtmlBuilder& add_child(string child_name, string child_text);
	string str() const;
	HtmlElement build() { return root; }
	operator HtmlElement() const
	{
		return root;
	}
};