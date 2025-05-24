#pragma once
#include <string>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
enum class Color {red, green, blue};
enum class Size { small, medium, large };

class Product {
public:
	string name;
	Color color;
	Size size;
	Product(const string& name, const Color& color, const Size& size) : name(name), color(color), size(size) {}
};

class ProductFilter {
public:
	ProductFilter(){ }
	vector<Product*> by_color(vector<Product*> items, Color color);
	vector<Product*> by_size(vector<Product*> items, Size size);
	vector<Product*> by_color_and_size(vector<Product*> items, Color color, Size size);

};


template <typename T> class Specification {
public:
	Specification() {}
	virtual bool is_satisfied(T* item) = 0;
};

template <typename T> class Filter {
public:
	Filter(){}
	virtual vector<T*> filter(vector<T*> items, Specification<T>& spec) = 0;

};

class BetterFilter : public Filter<Product> 
{
public:
	
	BetterFilter(){}
	vector<Product*> filter(vector<Product*> items, Specification<Product>& spec) override;
};

class ColorSpecification : public Specification<Product> {
public:
	Color color;
	ColorSpecification(Color color): color(color){}

	bool is_satisfied(Product* item) override;

};

class SizeSpecification : public Specification<Product> {
public:
	Size size;
	SizeSpecification(Size size) : size(size) {}

	bool is_satisfied(Product* item) override;

};
template<typename T>
class AndSpecification : public Specification<T>
{
public:
	Specification<T>& first;
	Specification<T>& second;
	AndSpecification(Specification<T>& first, Specification<T>& second) : first(first), second(second){}
	bool is_satisfied(T* item) override
	{
		return this->first.is_satisfied(item) && this->second.is_satisfied(item);
	}
};

template<typename T>
AndSpecification<T> operator&&(Specification<T>&& first, Specification<T>&& second)
{
	return AndSpecification<T>(first, second);
}