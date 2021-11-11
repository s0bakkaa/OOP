#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

#include "figure.h"

class Rectangle : public Figure {
public:
	Rectangle();
	Rectangle(Point a, Point b, Point c, Point d);
	Rectangle(std::istream& is);
	Rectangle(const Rectangle& other);

	size_t VertexesNumber();
	double Area();
	void Print(std::ostream& os);

	virtual ~Rectangle();

private:
	Point point_a; // lower left corner, then clockwise
	Point point_b;
	Point point_c;
	Point point_d;
};

#endif // RECTANGLE_H
