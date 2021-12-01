#include "square.h"

Square::Square() : point_a(0.0, 0.0), point_b(0.0, 0.0), point_c(0.0, 0.0), point_d(0.0, 0.0) {
	std::cout << "Default square is created" << std::endl;
}

Square::Square(Point a, Point b, Point c, Point d) : point_a(a), point_b(b), point_c(c), point_d(d) {
	std::cout << "Square is created with vertices: ";
	std::cout << point_a << ", ";
	std::cout << point_b << ", ";
	std::cout << point_c << ", ";
	std::cout << point_d << std::endl;
}

Square::Square(const Square& other) : Square(other.point_a, other.point_b, other.point_c, other.point_d) {
	std::cout << "Square's copy is created" << std::endl;
}

double Square::Area() {
	double side = 0.0;
	double fig_square = 0.0;
	side = point_b.dist(point_a);
	fig_square = side * side;
	return fig_square;
}

std::istream& operator>>(std::istream& is, Square& obj) {
	is >> obj.point_a >> obj.point_b >> obj.point_c >> obj.point_d;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Square& obj) {
	Point a(obj.point_a);
	Point b(obj.point_b);
	Point c(obj.point_c);
	Point d(obj.point_d);
	os << "Point_a: " << a << ", ";
	os << "Point_b: " << b << ", ";
	os << "Point_c: " << c << ", ";
	os << "Point_d: " << d << std::endl;
	return os;
}

Square& Square::operator++() {
	point_a.x_ += 1.0;
	point_a.y_ += 1.0;
	point_b.x_ += 1.0;
	point_b.y_ += 1.0;
	point_c.x_ += 1.0;
	point_c.y_ += 1.0;
	point_d.x_ += 1.0;
	point_d.y_ += 1.0;

	return *this;
}

Square operator+(const Square& left, const Square& right) {
	return Square(left.point_a + right.point_a, left.point_b + right.point_b, left.point_c + right.point_c, left.point_d + right.point_d);
}

Square& Square::operator=(const Square& other) {
	if (this == &other) {
		return *this;
	}
	else {
		point_a = other.point_a;
		point_b = other.point_b;
		point_c = other.point_c;
		point_d = other.point_d;
		std::cout << "Square is copied" << std::endl;
		return *this;
	}
}

Square::~Square() {
	std::cout << "Square is deleted" << std::endl;
}
