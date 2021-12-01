#ifndef TQUEUE_ITEM_H
#define TQUEUE_ITEM_H

#include <memory>
#include "square.h"

template <class T> class TQueueItem {
public:
    TQueueItem(const std::shared_ptr<T>& square);
    TQueueItem(const std::shared_ptr<TQueueItem<T>>& other);

    std::shared_ptr<TQueueItem<T>> SetNext(std::shared_ptr<TQueueItem> &next);
    std::shared_ptr<TQueueItem<T>> GetNext();

    std::shared_ptr<T> GetValue() const;

    template<class A> friend std::ostream& operator<<(std::ostream& os, const TQueueItem<A>& obj);

    void* operator new(size_t size);
    void operator delete(void* p);

    virtual ~TQueueItem();

private:
    std::shared_ptr<T> item;
    std::shared_ptr<TQueueItem<T>> next;
};

#endif // TQUEUE_ITEM_H
