#ifndef TQUEUE_ITEM_H
#define TQUEUE_ITEM_H

#include <memory>
#include "square.h"

template<typename T> class TQueueItem {
public:
    TQueueItem() = default;
    TQueueItem(const std::shared_ptr<T>& item);
    TQueueItem(const std::shared_ptr<TQueueItem<T>>& other);

    std::shared_ptr<TQueueItem<T>> SetNext(std::shared_ptr<TQueueItem<T>>& next_);
    std::shared_ptr<TQueueItem<T>> GetNext();

    std::shared_ptr<T> GetItem();

    template<typename A> friend std::ostream& operator<<(std::ostream& os, const TQueueItem<A>& obg);

    ~TQueueItem() = default;

private:
    std::shared_ptr<T> item;
    std::shared_ptr<TQueueItem<T>> next;
};

#endif // TQUEUE_ITEM_H
