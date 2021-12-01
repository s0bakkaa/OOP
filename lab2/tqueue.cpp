#include "tqueue.h"

TQueue::TQueue() : head(nullptr), tail(nullptr), num_of_elem(0) {

}

TQueue::TQueue(const TQueue& other) {
    head = other.head;
}

std::ostream& operator<<(std::ostream& os, const TQueue& queue) {
    TQueueItem* item = queue.head;

    while (item != nullptr) {
        os << *item << " => ";
        item = item->GetNext();
    }
    return os;
}

void TQueue::Push(Square&& square) {
    auto* item = new TQueueItem(square);
    if (item != nullptr) {
        if (this->Empty()) {
            this->head = this->tail = item;
        }
        else if (num_of_elem == 1) {
            tail = item;
            head->SetNext(item);
        }
        else {
            this->tail->SetNext(item);
            tail = item;
        }
        num_of_elem++;
    }
}

Square TQueue::Pop() {
    Square result;
    if (head != nullptr) {
        TQueueItem* item = head;
        head = head->GetNext();
        result = item->GetSquare();
        item->SetNext(nullptr);
        delete item;
    }
    return result;
}

const Square& TQueue::Top() {
    if (head) {
        return head->GetSquare();
    }
}

bool TQueue::Empty() {
    return head == nullptr;
}

size_t TQueue::Length() {
    return num_of_elem;
}

void TQueue::Clear() {
    delete head;
    head = tail = nullptr;
    num_of_elem = 0;
}

TQueue::~TQueue() {
    delete head;
}
