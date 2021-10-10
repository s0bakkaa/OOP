#include "square.h"

double Square::Area() {
    try {
        double len_a = point_b.dist(point_a);
        if (len_a < 0) {
            throw "The length of the side is < 0";
        }
        return pow(len_a, 2);
    }
    catch (const char* exception) {
        std::cerr << "Error: " << exception << std::endl;
    }
}

size_t Square::VertexesNumber() {
    return 4;
}

Square::Square()
    : point_a(0.0, 0.0), point_b(0.0, 0.0), point_c(0.0, 0.0), point_d(0.0, 0.0) {
    std::cout << "Default square is created" << std::endl;
}

Square::Square(const Square& other) {
    point_a = other.point_a;
    point_b = other.point_b;
    point_c = other.point_c;
    point_d = other.point_d;
    std::cout << "Square's copy is created" << std::endl;
}

Square::Square(std::vector<Point> vect)
    : point_a(vect[0]), point_b(vect[1]), point_c(vect[2]), point_d(vect[3]) {
    std::cout << "Square is created with vertexes: " << point_a << ", " << point_b << ", " << point_c << ", " << point_d << std::endl;
}

std::istream& operator>>(std::istream& is, Square& obj) {
    is >> obj.point_a >> obj.point_b >> obj.point_c >> obj.point_d;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Square& obj) {
    os << "Point a = " << obj.point_a << ", ";
    os << "Point b = " << obj.point_b << ", ";
    os << "Point c = " << obj.point_c << ", ";
    os << "Point d = " << obj.point_d << std::endl;

    return os;
}

Square& Square::operator=(const Square& other) {
    if (this == &other) {
        return *this;
    }

    this->point_a = other.point_a;
    this->point_b = other.point_b;
    this->point_c = other.point_c;
    this->point_d = other.point_d;

    std::cout << "Square is copied" << std::endl;
    return *this;
}

Square& Square::operator++() {
    ++this->point_a;
    ++this->point_b;
    ++this->point_c;
    ++this->point_d;
    
    return *this;
}

Square operator+(const Square& l, const Square& r) {
    std::vector<Point> vect{ l.point_a + r.point_a, l.point_b + r.point_b, l.point_c + r.point_c, l.point_d + r.point_d };
    return Square(vect);
}

Square::~Square() {
    std::cout << "Square is deleted" << std::endl;
}