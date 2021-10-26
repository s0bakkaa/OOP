#include "square.h"

double Square::Area() {
    try {
        double len_a = b.dist(a);
        if (len_a < 0) {
            throw "The length of the side is < 0";
        }
        return pow(len_a, 2);
    }
    catch (const char* exception) {
        std::cerr << "Error: " << exception << std::endl;
    }
}

Square::Square()
    :a(0.0, 0.0), b(0.0, 0.0), c(0.0, 0.0), d(0.0, 0.0) {
    std::cout << "Default square is created" << std::endl;
}

Square::Square(const Square& other) {
    a = other.a;
    b = other.b;
    c = other.c;
    d = other.d;
    std::cout << "Square's copy is created" << std::endl;
}

Square::Square(std::vector<Point> vect)
    : a(vect[0]), b(vect[1]), c(vect[2]), d(vect[3]) {
    std::cout << "Square is created with vertexes: " << a << ", " << b << ", " << c << ", " << d << std::endl;
}

std::istream& operator>>(std::istream& is, Square& obj) {
    std::cout << "Enter cords: " << std::endl;
    is >> obj.a >> obj.b >> obj.c >> obj.d;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Square& obj) {
    os << "Point a = " << obj.a << ", ";
    os << "Point b = " << obj.b << ", ";
    os << "Point c = " << obj.c << ", ";
    os << "Point d = " << obj.d << std::endl;

    return os;
}

Square& Square::operator++() {
    ++this->a;
    ++this->b;
    ++this->c;
    ++this->d;
    return *this;
}

Square operator+(const Square& left, const Square& right) {
    std::vector<Point> v{ left.a + right.a, left.b + right.b, left.c + right.c, left.d + right.d };
    return Square(v);
}

Square& Square::operator=(const Square& other) {
    if (this == &other) {
        return *this;
    }

    this->a = other.a;
    this->b = other.b;
    this->c = other.c;
    this->d = other.d;

    std::cout << "Square is copied" << std::endl;
    return *this;
}



Square::~Square() {
    std::cout << "Square is deleted" << std::endl;
}

size_t Square::VertexesNumber() {
    return 4;
}