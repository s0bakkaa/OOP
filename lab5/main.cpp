#include <iostream>
#include "square.h"
#include "tqueue.h"

int main() {
    std::vector<Point> v{ Point(0, 0), Point(0, 1), Point(1, 1), Point(1, 0) };
    TQueue<Square> queue;
    queue.push(std::shared_ptr<Square>(new Square(v)));
    queue.push(std::shared_ptr<Square>(new Square()));
    std::cout << queue;
    std::shared_ptr<Square> s;
    s = queue.pop();
    std::cout << *s << std::endl;
    s = queue.pop();
    std::cout << *s << std::endl;
    return 0;
}