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

Square::Square(std::istream& is) {
	is >> point_a >> point_b >> point_c >> point_d;
}

Square::Square(const Square& other) : Square(other.point_a, other.point_b, other.point_c, other.point_d) {
	std::cout << "Square's copy is created" << std::endl;
}

size_t Square::VertexesNumber() {
	int vert_num = 4;
	return vert_num;
}

double Square::Area() {
	double side = 0.0;
	double fig_square = 0.0;
	side = point_b.dist(point_a);
	fig_square = side * side;
	return fig_square;
}

void Square::Print(std::ostream& os) {
	os << "Square: ";
	os << point_a << " ";
	os << point_b << " ";
	os << point_c << " ";
	os << point_d << std::endl;
}

Square::~Square() {
	std::cout << "Square is deleted" << std::endl;
}
