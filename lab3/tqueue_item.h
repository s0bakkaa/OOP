#ifndef TQUEUE_ITEM_H
#define TQUEUE_ITEM_H

#include <memory>
#include "square.h"

class TQueueItem {
public:
    TQueueItem(const std::shared_ptr<Square>& square);
    TQueueItem(const std::shared_ptr<TQueueItem>& other);

    std::shared_ptr<TQueueItem> SetNext(std::shared_ptr<TQueueItem> &next);
    std::shared_ptr<TQueueItem> GetNext();

    std::shared_ptr<Square> GetSquare() const;

    friend std::ostream& operator<<(std::ostream& os, const TQueueItem& obj);

    virtual ~TQueueItem();

private:
    std::shared_ptr<Square> square;
    std::shared_ptr<TQueueItem> next;
};

#endif // TQUEUE_ITEM_H
