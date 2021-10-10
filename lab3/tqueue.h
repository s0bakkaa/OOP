#ifndef TQUEUE_H
#define TQUEUE_H

#include "tqueue_item.h"

class TQueue {
public:
    TQueue();
    TQueue(const TQueue& other);

    bool push(std::shared_ptr<Square>&& square);
    bool pop();
    bool empty();

    std::shared_ptr<Square> top();

    size_t size();

    friend std::ostream& operator<<(std::ostream& os, const TQueue& queue);

    ~TQueue();

private:
    std::shared_ptr <TQueueItem> head;
    std::shared_ptr <TQueueItem> tail;
    size_t numOfElems;
};

#endif // TQUEUE_H

