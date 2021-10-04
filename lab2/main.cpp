#include "tqueue.h"

int main() {
    TQueue* queue = new TQueue;
    std::vector<Point> vect{ Point(0, 0), Point(0, 1), Point(1, 1), Point(1, 0) };
    queue->push(Square(vect));
    queue->push(Square());
    std::cout << *queue << std::endl;
    delete queue;
    return 0;
}