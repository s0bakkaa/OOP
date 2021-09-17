#ifndef FIGURE_H
#define FIGURE_H

#include "point.h"

class Figure { 
public:
    virtual size_t VertexesNumber() = 0; //возвращает кол-во вершин фигуры
    virtual double Area() = 0; //метод расчета площади фигуры
    virtual void Print(std::ostream& os) = 0;
    virtual ~Figure() {};

};

#endif // FIGURE_H