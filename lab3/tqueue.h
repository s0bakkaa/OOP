#ifndef TQUEUE_H
#define TQUEUE_H

#include "tqueue_item.h"

class TQueue {
public:
    TQueue();
    TQueue(const TQueue& other);

    void Push(std::shared_ptr<Square> &&square);
    std::shared_ptr<Square> Pop();

    std::shared_ptr<Square> Top();

    bool Empty();

    size_t Length();

    friend std::ostream& operator<<(std::ostream& os, const TQueue& queue);

    virtual ~TQueue();

private:
    std::shared_ptr<TQueueItem> head;
    std::shared_ptr<TQueueItem> tail;
    size_t num_of_elem;
};

#endif // TQUEUE_H
