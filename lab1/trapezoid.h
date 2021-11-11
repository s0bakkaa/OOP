#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include <iostream>

#include "figure.h"

class Trapezoid : public Figure {
public:
	Trapezoid();
	Trapezoid(Point a, Point b, Point c, Point d);
	Trapezoid(std::istream& is);
	Trapezoid(const Trapezoid& other);

	size_t VertexesNumber();
	double Area(); // площадь
	void Print(std::ostream& os);

	virtual ~Trapezoid();

private:
	Point point_a; // lower left corner, then clockwise
	Point point_b;
	Point point_c;
	Point point_d;
};

#endif // TRAPEZOID_H
