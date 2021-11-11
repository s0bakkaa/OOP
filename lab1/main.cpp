#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"

int main(int argc, char** argv) {
	std::cout << "DEFAULT FIGURES" << std::endl;
	std::cout << std::endl;

	Square sq_default;
	sq_default.Print(std::cout);

	Rectangle re_default;
	re_default.Print(std::cout);

	Trapezoid tr_default;
	tr_default.Print(std::cout);

	std::cout << std::endl;
	std::cout << "SET VALUES FIGURES" << std::endl;
	std::cout << std::endl;

	Point a(2.0, 1.0);
	Point b(2.0, 3.0);
	Point c(4.0, 3.0);
	Point d(4.0, 1.0);
	Point e(5.0, 3.0);
	Point f(5.0, 1.0);

	Square sq_values(a, b, c, d);
	std::cout << "Number of square's vertexes: " << sq_values.VertexesNumber() << std::endl;
	std::cout << "Square's area: " << sq_values.Area() << std::endl;
	sq_values.Print(std::cout);

	Rectangle re_values(a, b, e, f);
	std::cout << "Number of rectangle's vertexes: " << re_values.VertexesNumber() << std::endl;
	std::cout << "Rectangle's area: " << re_values.Area() << std::endl;
	re_values.Print(std::cout);

	Trapezoid tr_values(a, c, e, f);
	std::cout << "Number of trapezoid's vertexes: " << tr_values.VertexesNumber() << std::endl;
	std::cout << "Trapezoid's square: " << tr_values.Area() << std::endl;
	tr_values.Print(std::cout);

	std::cout << std::endl;
	std::cout << "CIN FIGURES" << std::endl;
	std::cout << std::endl;

	Square sq_cin(std::cin);
	std::cout << "Number of square's vertexes: " << sq_cin.VertexesNumber() << std::endl;
	std::cout << "Square's area: " << sq_cin.Area() << std::endl;
	sq_cin.Print(std::cout);

	Rectangle re_cin(std::cin);
	std::cout << "Number of rectangle's vertexes: " << re_cin.VertexesNumber() << std::endl;
	std::cout << "Rectangle's area: " << re_cin.Area() << std::endl;
	re_cin.Print(std::cout);

	Trapezoid tr_cin(std::cin);
	std::cout << "Number of trapezoid's vertexes: " << tr_cin.VertexesNumber() << std::endl;
	std::cout << "Trapezoid's square: " << tr_cin.Area() << std::endl;
	tr_cin.Print(std::cout);

	std::cout << std::endl;
	std::cout << "COPIED FIGURES" << std::endl;
	std::cout << std::endl;

	Square sq_copy = sq_values;
	sq_copy.Print(std::cout);

	Rectangle re_copy = re_values;
	re_copy.Print(std::cout);

	Trapezoid tr_copy = tr_values;
	tr_copy.Print(std::cout);

	std::cout << std::endl;
	std::cout << "POINTER FIGURES" << std::endl;
	std::cout << std::endl;

	Figure* sq_ptr = new Square(sq_cin);
	sq_ptr->Print(std::cout);
	std::cout << "Square's area: " << sq_ptr->Area() << std::endl;

	Figure* re_ptr = new Rectangle(re_cin);
	re_ptr->Print(std::cout);
	std::cout << "Rectangle's area: " << re_ptr->Area() << std::endl;

	Figure* tr_ptr = new Trapezoid(tr_cin);
	tr_ptr->Print(std::cout);
	std::cout << "Trapezoid's area: " << tr_ptr->Area() << std::endl;

	delete sq_ptr;
	delete re_ptr;
	delete tr_ptr;

	return 0;
}
