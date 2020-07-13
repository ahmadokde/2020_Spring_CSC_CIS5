#include "Rectangle.h"

Rectangle::Rectangle(double l, double w)
{
	length = l;
	width = w;
}
double Rectangle::getLength()
{
	return length;
}
double Rectangle::getWidth()
{
	return width;
}
void Rectangle::setLength(double l)
{
	length = l;
}
void Rectangle::setWidth(double w)
{
	width = w;
}
double Rectangle::getArea()
{
	return length * width;
}
double Rectangle::getPerimeter()
{
	return 2 * (length + width);
}
