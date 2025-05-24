#include <fstream>
#include "rectangle_and_square.hpp"

void process(Rectangle& r)
{
	int w = r.getWidth();
	r.setHeight(10);

	cout << "Expected area = " << w * 10 << ", got " << r.area() << endl;

}