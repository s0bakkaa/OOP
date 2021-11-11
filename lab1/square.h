#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>

#include "figure.h"

class Square : public Figure {
public:
	Square(); // конструктор по умолчанию
	Square(Point a, Point b, Point c, Point d); // конструктор, принимающий координаты вершин
	Square(std::istream& is); // конструктор, принимающий координаты вершин из стандартного потока ввода
	Square(const Square& other); // создание копии объекта

	size_t VertexesNumber(); // число вершин
	double Area(); // площадь
	void Print(std::ostream& os); // печать типа фигуры и координат вершин

	virtual ~Square();

private:
	Point point_a; // левый нижний угол, далее - по часовой стрелке
	Point point_b;
	Point point_c;
	Point point_d;
};

#endif // SQUARE_H
