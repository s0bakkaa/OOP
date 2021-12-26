#include "tallocation_block.h"
#include "tqueue.h"

void _Queue() {
    TQueue<Square> queue;
    std::vector<Point> vect;
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
    queue.Push(std::shared_ptr<Square>(new Square(a_1, b_1, c_1, d_1)));
    queue.Push(std::shared_ptr<Square>(new Square(a_2, b_2, c_2, c_2)));
    queue.Push(std::shared_ptr<Square>(new Square(a_3, b_3, c_3, d_3)));

    for (auto i : queue) {
        std::cout << *i << std::endl;
    }

    while (!queue.Empty()) {
        std::cout << *queue.Top() << std::endl;
        queue.Pop();
    }
}

void _AllocationBlock() {
    TAllocationBlock allocator(sizeof(int), 10);
    int* alloc1 = nullptr;
    int* alloc2 = nullptr;
    int* alloc3 = nullptr;
    int* alloc4 = nullptr;
    int* alloc5 = nullptr;


    alloc1 = (int*)allocator.allocate();
    *alloc1 = 1;
    std::cout << "a1 pointer value:" << *alloc1 << std::endl;

    alloc2 = (int*)allocator.allocate();
    *alloc2 = 2;
    std::cout << "a2 pointer value:" << *alloc2 << std::endl;

    alloc3 = (int*)allocator.allocate();
    *alloc3 = 3;
    std::cout << "a3 pointer value:" << *alloc3 << std::endl;

    allocator.deallocate(alloc1);
    allocator.deallocate(alloc3);

    alloc4 = (int*)allocator.allocate();
    *alloc4 = 4;
    std::cout << "a4 pointer value:" << *alloc4 << std::endl;

    alloc4 = (int*)allocator.allocate();
    *alloc4 = 5;
    std::cout << "a5 pointer value:" << *alloc4 << std::endl;

    std::cout << "a1 pointer value:" << *alloc1 << std::endl;
    std::cout << "a2 pointer value:" << *alloc2 << std::endl;
    std::cout << "a3 pointer value:" << *alloc3 << std::endl;

    allocator.deallocate(alloc2);
    allocator.deallocate(alloc4);
    allocator.deallocate(alloc5);
}

int main(int argc, char** argv) {
    _AllocationBlock();
    _Queue();
    return 0;
}