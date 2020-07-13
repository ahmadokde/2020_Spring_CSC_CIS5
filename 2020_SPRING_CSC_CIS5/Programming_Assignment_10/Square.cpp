#include "Square.h"

Square::Square(double s)
{
	side = s;
}
double Square::getSide()
{
	return side;
}
void Square::setSide(double s)
{
	side = s;
}
double Square::getArea()
{
	return side * side;
}
double Square::getPerimeter()
{
	return 4 * side;
}


