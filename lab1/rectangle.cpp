#include "rectangle.h"

Rectangle::Rectangle(std::istream& is) {
    std::cout << "Enter the rectangle's vertexes:" << std::endl;
    is >> point_a;
    is >> point_b;
    is >> point_c;
    is >> point_d;
    std::cout << "The rectangle is created" << std::endl;
}

void Rectangle::Print(std::ostream& os) {
    std::cout << "Rectangle: ";
    std::cout << point_a << ", ";
    std::cout << point_b << ", ";
    std::cout << point_c << ", ";
    std::cout << point_d << std::endl;
}

size_t Rectangle::VertexesNumber() {
    size_t number = 4;
    return number;
}

double Rectangle::Area() {
    try {
        double len_a = point_b.dist(point_a);
        double len_b = point_c.dist(point_b);
        if (len_a < 0 || len_b < 0) {
            throw "The length of the side is < 0";
        }
        return len_a * len_b;
    }
    catch (const char* exception) {
        std::cerr << "Error: " << exception << std::endl;
    }

}

Rectangle::~Rectangle() {
    std::cout << "The rectangle is deleted" << std::endl;
}