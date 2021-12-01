#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square : public Figure {
public:
	Square();
	Square(Point a, Point b, Point c, Point d);
	Square(const Square& other);

	double Area();

	friend std::istream& operator>>(std::istream& is, Square& obj);
	friend std::ostream& operator<<(std::ostream& os, const Square& obj);

	Square& operator++();
	friend Square operator+(const Square& left, const Square& right);

	Square& operator=(const Square& other);

	virtual ~Square();

private:
	Point point_a; // lower left corner, then clockwise
	Point point_b;
	Point point_c;
	Point point_d;
};

#endif // SQUARE_H
