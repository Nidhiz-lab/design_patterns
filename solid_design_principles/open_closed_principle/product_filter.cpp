#include "product_filter.hpp"


vector<Product*> ProductFilter::by_color(vector<Product*> items, Color color)
{
	vector<Product*> result;
	for (auto& i : items)
	{
		if (i->color == color)
		{
			result.push_back(i);
		}
	}
	return result;
}

vector<Product*> ProductFilter::by_size(vector<Product*> items, Size size)
{
	vector<Product*> result;
	for (auto& i : items)
	{
		if (i->size == size)
		{
			result.push_back(i);
		}
	}
	return result;
}

vector<Product*> ProductFilter::by_color_and_size(vector<Product*> items, Color color, Size size)
{
	vector<Product*> result;
	for (auto& i : items)
	{
		if ((i->size == size) && (i->color == color))
		{
			result.push_back(i);
		}
	}
	return result;
}


vector<Product*> BetterFilter::filter(vector<Product*> items, Specification<Product>& spec)
{
	vector<Product*> result;
	for (auto& item : items)
	{
		if (spec.is_satisfied(item))
		{
			result.push_back(item);
		}
	}
	return result;
}

bool ColorSpecification::is_satisfied(Product* item)
{
	return item->color == this->color;

}

bool SizeSpecification::is_satisfied(Product* item)
{
	return item->size == this->size;

}
