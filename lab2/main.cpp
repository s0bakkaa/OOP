#include "tqueue.h"

int main(int argc, char** argv) {
    TQueue queue;
    Point a_1(1.0, 1.0);
    Point b_1(1.0, 2.0);
    Point c_1(2.0, 2.0);
    Point d_1(2.0, 1.0);
    Point a_2(3.0, 1.0);
    Point b_2(3.0, 3.0);
    Point c_2(5.0, 3.0);
    Point d_2(5.0, 1.0);
    Point a_3(0.0, 0.0);
    Point b_3(0.0, 4.0);
    Point c_3(4.0, 4.0);
    Point d_3(4.0, 0.0);
    queue.Push(Square(a_1, b_1, c_1, d_1));
    queue.Push(Square(a_2, b_2, c_2, c_2));
    queue.Push(Square(a_3, b_3, c_3, d_3));
    std::cout << queue;

    Square square;
    square = queue.Pop();
    std::cout << square;
    square = queue.Pop();
    std::cout << square;
    square = queue.Pop();
    std::cout << square;

    return 0;
}
