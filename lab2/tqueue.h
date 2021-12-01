#ifndef TQUEUE_H
#define TQUEUE_H

#include "tqueue_item.h"

class TQueue {
public:
    TQueue();
    TQueue(const TQueue& other);

    void Push(Square&& square);
    Square Pop();

    const Square& Top();

    bool Empty();

    size_t Length();

    friend std::ostream& operator<<(std::ostream& os, const TQueue& queue);

    void Clear();

    virtual ~TQueue();

private:
    TQueueItem* head;
    TQueueItem* tail;
    size_t num_of_elem;
};

#endif // TQUEUE_H
