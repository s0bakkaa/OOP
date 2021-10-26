#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <vector>
#include "point.h"

class Square {
public:
    Square();
    Square(std::vector<Point>);
    Square(const Square& other);

    friend std::istream& operator>>(std::istream& is, Square& obj);
    friend std::ostream& operator<<(std::ostream& os, const Square& obj);

    Square& operator++();
    friend Square operator+(const Square& left, const Square& right);
    Square& operator=(const Square& right);

    size_t VertexesNumber();
    double Area();

    virtual ~Square();

private:
    Point a, b, c, d;
};

#endif // SQUARE_H