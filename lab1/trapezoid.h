#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "figure.h"

class Trapezoid : public Figure{
public:
    Trapezoid(std::istream& is);

    size_t VertexesNumber();
    double Area();
    void Print(std::ostream& os);
    virtual ~Trapezoid();

private:
    Point point_a, point_b, point_c, point_d; //первая вершина - левая нижняя, далее - по часовой стрелке
};

#endif // TRAPEZOID_H