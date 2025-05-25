#include <fstream>
#include "html_builder.hpp"


string HtmlElement::str(int indent = 0) const
{
	ostringstream oss;
	string i(this->indent_size * indent, ' ');
	oss << i << "<" << name << ">" << endl;
	if (text.size() > 0)
	{
		oss << string(this->indent_size * (indent + 1), ' ') << text << endl;
	}
	for (const auto& e : elements)
	{
		oss << e.str(indent + 1);
	}
	oss << i << "</" << name << ">" << endl;
	return oss.str();
}

HtmlBuilder& HtmlBuilder::add_child(string child_name, string child_text)
{
	HtmlElement e{ child_name , child_text};
	this->root.elements.emplace_back(e);
	return *this;
}

string HtmlBuilder::str() const
{
	return this->root.str();
}
HtmlBuilder HtmlElement::create(string root_name)
{
	return { root_name };
}

