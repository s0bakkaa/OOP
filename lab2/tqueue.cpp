#include "tqueue.h"

TQueue::TQueue() : head(nullptr), tail(nullptr), numOfElems(0) {}

TQueue::TQueue(const TQueue& other) : head(other.head), tail(other.tail), numOfElems(other.numOfElems) {}

std::ostream& operator<<(std::ostream& os, const TQueue& que) {
    TQueueItem* queueItem = que.head;

    while (queueItem != nullptr) {
        os << *queueItem;
        queueItem = queueItem->GetNext();
    }

    return os;
}

bool TQueue::push(Square&& square) {
    TQueueItem* other = new TQueueItem(square);

    if (other == nullptr) {
        return false;
    }

    if (this->empty()) {
        this->head = this->tail = other;
    }
    else if (numOfElems == 1) {
        tail = other;
        head->SetNext(tail);
    }
    else {
        this->tail->SetNext(other);
        tail = other;
    }

    numOfElems++;

    return true;
}

bool TQueue::pop() {
    if (head) {
        head = head->GetNext();

        return true;
    }
    return false;
}

Square TQueue::top() {
    if (head) {
        return head->GetSquare();
    }
}

size_t TQueue::size() {
    return numOfElems;
}

bool TQueue::empty() {
    return head == nullptr;
}

TQueue::~TQueue() {
    delete head;
}