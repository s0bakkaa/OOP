#include "tqueue_item.h"

TQueueItem::TQueueItem(const Square& square) {
    this->square = square;
    this->next = nullptr;
    std::cout << "Queue item is created" << std::endl;
}

TQueueItem::TQueueItem(const TQueueItem& other) {
    this->square = other.square;
    this->next = other.next;
    std::cout << "Queue item is copied" << std::endl;
}

TQueueItem* TQueueItem::SetNext(TQueueItem* next) {
    TQueueItem* prev = this->next;
    this->next = next;
    return prev;
}

TQueueItem* TQueueItem::GetNext() {
    return this->next;
}

Square TQueueItem::GetSquare() const {
    return this->square;
}

std::ostream& operator<<(std::ostream& os, const TQueueItem& obj) {
    os << "Item: " << obj.square << std::endl;
    return os;
}

TQueueItem::~TQueueItem() {
    delete next;
    std::cout << "The queue item is deleted" << std::endl;
}
