#include "trapezoid.h"

Trapezoid::Trapezoid() : point_a(0.0, 0.0), point_b(0.0, 0.0), point_c(0.0, 0.0), point_d(0.0, 0.0) {
	std::cout << "Default trapezoid is created" << std::endl;
}

Trapezoid::Trapezoid(Point a, Point b, Point c, Point d) : point_a(a), point_b(b), point_c(c), point_d(d) {
	std::cout << "Trapezoid is created with vertices: ";
	std::cout << point_a << ", ";
	std::cout << point_b << ", ";
	std::cout << point_c << ", ";
	std::cout << point_d << std::endl;
}

Trapezoid::Trapezoid(std::istream& is) {
	is >> point_a >> point_b >> point_c >> point_d;
}

Trapezoid::Trapezoid(const Trapezoid& other) : Trapezoid(other.point_a, other.point_b, other.point_c, other.point_d) {
	std::cout << "Trapezoid's copy is created" << std::endl;
}

size_t Trapezoid::VertexesNumber() {
	int vert_num = 4;
	return vert_num;
}

double Trapezoid::Area() {
	double fig_square = 0.0;
	double side_a = 0.0;
	double side_b = 0.0;
	double height = 0.0;
	if (point_a.y_ == point_d.y_ && point_b.y_ == point_c.y_) {
		side_a = point_d.dist(point_a);
		side_b = point_c.dist(point_b);
		height = point_b.y_ - point_a.y_;
	}
	else {
		side_a = point_b.dist(point_a);
		side_b = point_c.dist(point_d);
		height = point_c.x_ - point_b.x_;
	}
	fig_square = 0.5 * (side_a + side_b) * height;
	return fig_square;
}

void Trapezoid::Print(std::ostream& os) {
	os << "Trapezoid: ";
	os << point_a << " ";
	os << point_b << " ";
	os << point_c << " ";
	os << point_d << std::endl;
}

Trapezoid::~Trapezoid() {
	std::cout << "Trapezoid is deleted" << std::endl;
}
