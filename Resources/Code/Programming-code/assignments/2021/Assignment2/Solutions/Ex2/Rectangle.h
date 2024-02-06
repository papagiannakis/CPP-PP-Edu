#include "../std_lib_facilities.h"

class Rectangle
{
private:
	double length;
	double width;

public:
	Rectangle();
	Rectangle(double length, double width);
	double perimeter();
	double area();
	double getLength();
	double getWidth();
	void setLength(double len);
	void setWidth(double wid);
};
