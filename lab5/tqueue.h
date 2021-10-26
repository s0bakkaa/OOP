#ifndef TQUEUE_H
#define TQUEUE_H

#include <memory>
#include "square.h"
#include "tqueue_item.h"

template <class T> class TQueue {
public:
    TQueue();
    TQueue(const TQueue<T>& other);

    ~TQueue() = default;

    template <class A> 
    friend std::ostream& operator<<(std::ostream& os, const TQueue<A>& queue);

    void push(std::shared_ptr<T>&& item);
    std::shared_ptr<T> pop();
    std::shared_ptr<T> top();
    bool empty();
    size_t size();

private:
    std::shared_ptr<TQueueItem<T>> first, last;
    size_t n;
};

#endif // TQUEUE_H
