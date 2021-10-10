#include "tqueue.h"

int main() {
    TQueue queue;
    std::vector<Point> vect{ Point(0, 0), Point(0, 1), Point(1, 1), Point(1, 0) };
    queue.push(std::make_shared<Square>(Square(vect)));
    queue.push(std::make_shared<Square>(Square()));
    std::cout << queue << std::endl;
    return 0;
}