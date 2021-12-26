#ifndef TQUEUE_H
#define TQUEUE_H

#include "titerator.h"
#include "tqueue_item.h"

template <class T> 
class TQueue {
public:
    TQueue();
    TQueue(const TQueue<T>& other);

    void Push(std::shared_ptr<T> &&square);
    std::shared_ptr<T> Pop();

    std::shared_ptr<T> Top();

    bool Empty();

    size_t Length();

    template <class A>
    friend std::ostream& operator<<(std::ostream& os, const TQueue<A>& queue);

    TIterator<TQueueItem<T>, T> begin();
    TIterator<TQueueItem<T>, T> end();

    virtual ~TQueue();

private:
    std::shared_ptr<TQueueItem<T>> head;
    std::shared_ptr<TQueueItem<T>> tail;
    size_t num_of_elem;
};

#endif // TQUEUE_H