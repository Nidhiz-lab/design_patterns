#pragma once
#include <string>
#include <string>
#include <vector>
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

};