#include "rectangle.h"

Rectangle::Rectangle() : point_a(0.0, 0.0), point_b(0.0, 0.0), point_c(0.0, 0.0), point_d(0.0, 0.0) {
	std::cout << "Default rectangle is created" << std::endl;
}

Rectangle::Rectangle(Point a, Point b, Point c, Point d) : point_a(a), point_b(b), point_c(c), point_d(d) {
	std::cout << "Rectangle is created with vertices: ";
	std::cout << point_a << ", ";
	std::cout << point_b << ", ";
	std::cout << point_c << ", ";
	std::cout << point_d << std::endl;
}

Rectangle::Rectangle(std::istream& is) {
	is >> point_a >> point_b >> point_c >> point_d;
}

Rectangle::Rectangle(const Rectangle& other) : Rectangle(other.point_a, other.point_b, other.point_c, other.point_d) {
	std::cout << "Rectangle's copy is created" << std::endl;
}

size_t Rectangle::VertexesNumber() {
	int vert_num = 4;
	return vert_num;
}

double Rectangle::Area() {
	double side_a = 0.0;
	double side_b = 0.0;
	double fig_square = 0.0;
	side_a = point_b.dist(point_a);
	side_b = point_c.dist(point_b);
	fig_square = side_a * side_b;
	return fig_square;
}

void Rectangle::Print(std::ostream& os) {
	os << "Rectangle: ";
	os << point_a << " ";
	os << point_b << " ";
	os << point_c << " ";
	os << point_d << std::endl;
}

Rectangle::~Rectangle() {
	std::cout << "Rectangle is deleted" << std::endl;
}
