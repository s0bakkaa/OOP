#ifndef TQUEUE_H
#define TQUEUE_H

#include "tqueue_item.h"

class TQueue {
public:
    TQueue();
    TQueue(const TQueue& other);

    bool push(Square&& square);
    bool pop();
    bool empty();

    Square top();

    size_t size();

    friend std::ostream& operator<<(std::ostream& os, const TQueue& queue);

    ~TQueue();

private:
    TQueueItem* head;
    TQueueItem* tail;
    size_t numOfElems;
};

#endif // TQUEUE_H

