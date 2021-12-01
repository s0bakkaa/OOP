#include "tqueue.h"

TQueue::TQueue() : head(nullptr), tail(nullptr), num_of_elem(0) {

}

TQueue::TQueue(const TQueue& other) {
    head = other.head;
}

std::ostream& operator<<(std::ostream& os, const TQueue& queue) {
    std::shared_ptr<TQueueItem> item = queue.head;

    while (item != nullptr) {
        os << *item << " => ";
        item = item->GetNext();
    }
    return os;
}

void TQueue::Push(std::shared_ptr<Square> &&square) {
    std::shared_ptr<TQueueItem> item = std::make_shared<TQueueItem>(TQueueItem(square));
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

std::shared_ptr<Square> TQueue::Pop() {
    std::shared_ptr<Square> result;
    if (head != nullptr) {
        std::shared_ptr<TQueueItem> item = head;
        head = head->GetNext();
        result = item->GetSquare();
        //item->SetNext(nullptr);
        //delete item;
    }
    return result;
}

std::shared_ptr<Square> TQueue::Top() {
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

TQueue::~TQueue() {

}
