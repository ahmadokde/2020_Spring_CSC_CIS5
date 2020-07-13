#include "Circle.h"

Circle::Circle(double r)
{
	radius = r;
}
double Circle::getRadius()
{
	return radius;
}
void Circle::setRadius(double r)
{
	radius = r;
}
double Circle::getArea() //pi * r * r
{
	return 3.14 * radius * radius;
}
double Circle::getPerimeter() //2 * pi * r
{
	return 2 * 3.14 * radius;
}

