#include "tqueue_item.h"

TQueueItem::TQueueItem(const std::shared_ptr<Square>& square) {
    this->square = square;
    this->next = nullptr;
    std::cout << "Queue item is created" << std::endl;
}

TQueueItem::TQueueItem(const std::shared_ptr<TQueueItem>& other) {
    this->square = other->square;
    this->next = other->next;
    std::cout << "Queue item is copied" << std::endl;
}

std::shared_ptr<TQueueItem> TQueueItem::SetNext(std::shared_ptr<TQueueItem> &next) {
    std::shared_ptr<TQueueItem> prev = this->next;
    this->next = next;
    return prev;
}

std::shared_ptr<TQueueItem> TQueueItem::GetNext() {
    return this->next;
}

std::shared_ptr<Square> TQueueItem::GetSquare() const {
    return this->square;
}

std::ostream& operator<<(std::ostream& os, const TQueueItem& obj) {
    os << "Item: " << *obj.square << std::endl;
    return os;
}

TQueueItem::~TQueueItem() {
    std::cout << "The queue item is deleted" << std::endl;
}
