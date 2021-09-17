#include <iostream>
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"

int main()
{
    Square square(std::cin);
    std::cout << "The number of square's vertexes: " << square.VertexesNumber() << std::endl;
    square.Print(std::cout);
    std::cout << "The area of the square: " << square.Area() << std::endl;
    std::cout << std::endl;

    Rectangle rectangle(std::cin);
    std::cout << "The number of rectangle's vertexes: " << rectangle.VertexesNumber() << std::endl;
    rectangle.Print(std::cout);
    std::cout << "The area of the rectangle: " << rectangle.Area() << std::endl;
    std::cout << std::endl;

    Trapezoid trapezoid(std::cin);
    std::cout << "The number of trapezoid's vertexes: " << trapezoid.VertexesNumber() << std::endl;
    trapezoid.Print(std::cout);
    std::cout << "The area of the trapezoid: " << trapezoid.Area() << std::endl;

    return 0;
}