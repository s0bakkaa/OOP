#include "trapezoid.h"

Trapezoid::Trapezoid(std::istream& is) {
    std::cout << "Enter the trapezoid's vertexes:" << std::endl;
    is >> point_a;
    is >> point_b;
    is >> point_c;
    is >> point_d;
    std::cout << "The trapezoid is created" << std::endl;
}

void Trapezoid::Print(std::ostream& os) {
    std::cout << "Trapezoid: ";
    std::cout << point_a << ", ";
    std::cout << point_b << ", ";
    std::cout << point_c << ", ";
    std::cout << point_d << std::endl;
}

size_t Trapezoid::VertexesNumber() {
    size_t number = 4;
    return number;
}

double Trapezoid::Area() {
    try {
        double len_a = point_b.dist(point_a);
        double len_b = point_c.dist(point_b);
        double len_c = point_d.dist(point_c);
        double len_d = point_a.dist(point_d);
        if (len_a < 0 || len_b < 0 || len_c < 0 || len_d < 0) {
            throw "The length of the side is < 0";
        }
        double sum = point_a.x_ * point_b.y_ + point_b.x_ * point_c.y_ + point_c.x_ * point_d.y_ + point_d.x_ * point_a.y_;
        double diff = 0 - point_b.x_ * point_a.y_ - point_c.x_ * point_b.y_ - point_d.x_ * point_c.y_ - point_a.x_ * point_d.y_;
        return 0.5 * (sum + diff);
    }
    catch (const char* exception) {
        std::cerr << "Error: " << exception << std::endl;
    }
}

Trapezoid::~Trapezoid() {
    std::cout << "The trapezoid is deleted" << std::endl;
}