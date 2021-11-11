#ifndef FIGURE_H
#define FIGURE_H

#include <ostream>

#include "point.h"

class Figure {
public:
    virtual void Print(std::ostream& os) = 0;
    virtual double Area() = 0;
    virtual ~Figure() {};
};

#endif // FIGURE_H
