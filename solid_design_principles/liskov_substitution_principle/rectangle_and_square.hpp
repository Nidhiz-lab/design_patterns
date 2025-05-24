#pragma once
#include<iostream>
using namespace std;

class Rectangle {
protected:
	int width, height;
public:
	Rectangle(int width, int height):width(width), height(height){}

	int getWidth() const
	{
		return this->width;
	}
	virtual void setWidth(int width)
	{
		this->width = width;
	}
	int getHeight() const
	{
		return this->height;
	}
	virtual void setHeight(int height)
	{
		this->height = height;
	}
	int area() const
	{
		return this->width * this->height;
	}
};

class Square : public Rectangle 
{
public:
	Square(int size): Rectangle(size, size){}

	void setWidth(int width) override
	{
		this->width = this->height = width;
	}
	void setHeight(int height) override
	{
		this->width = this->height = height;
	}
};


class RectangleFactory 
{
	static Rectangle create_rectangle(int w, int h);
	static Rectangle create_square(int w, int h);
};
void process(Rectangle& r);
