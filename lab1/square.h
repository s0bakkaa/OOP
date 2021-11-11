#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>

#include "figure.h"

class Square : public Figure {
public:
	Square();
	Square(Point a, Point b, Point c, Point d);
	Square(std::istream& is);
	Square(const Square& other);

	size_t VertexesNumber();
	double Area(); // площадь
	void Print(std::ostream& os);

	virtual ~Square();

private:
	Point point_a; // lower left corner, then clockwise
	Point point_b;
	Point point_c;
	Point point_d;
};

#endif // SQUARE_H
