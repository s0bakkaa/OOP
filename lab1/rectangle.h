#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle : public Figure {
public:
    Rectangle(std::istream& is);

    size_t VertexesNumber();
    double Area();
    void Print(std::ostream& os);
    virtual ~Rectangle();

private:
    Point point_a, point_b, point_c, point_d; //  a - low left
};

#endif // RECTANGLE_H
