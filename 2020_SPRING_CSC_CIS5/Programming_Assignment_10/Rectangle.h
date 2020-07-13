#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle
{
private:
	double length, width;
public:
	Rectangle(double = 0, double = 0);
	double getLength();
	double getWidth();
	void setLength(double l);
	void setWidth(double w);
	double getArea();
	double getPerimeter();
};


#endif
