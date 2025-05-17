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