#ifndef CIRCLE_H
#define CIRCLE_H
class Circle
{
private:
	double radius;
public:
	Circle(double = 0);
	double getRadius();
	void setRadius(double r);
	double getArea(); //pi * r * r
	double getPerimeter(); //2 * pi * r
};


#endif

