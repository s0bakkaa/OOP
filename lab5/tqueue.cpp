#include "tqueue.h"

template <class T>
TQueue<T>::TQueue() : head(nullptr), tail(nullptr), num_of_elem(0) {

}

template <class T>
TQueue<T>::TQueue(const TQueue<T>& other) {
    head = other.head;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const TQueue<T>& queue) {
    std::shared_ptr<TQueueItem<T>> item = queue.head;

    while (item != nullptr) {
        os << *item << " => ";
        item = item->GetNext();
    }
    return os;
}

template <class T>
void TQueue<T>::Push(std::shared_ptr<T> &&square) {
    std::shared_ptr<TQueueItem<T>> item = std::make_shared<TQueueItem<T>>(TQueueItem<T>(square));
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

template <class T>
std::shared_ptr<T> TQueue<T>::Pop() {
    std::shared_ptr<T> result;
    if (head != nullptr) {
        result = head->GetValue();
        head = head->GetNext();
        //item->SetNext(nullptr);
        //delete item;
    }
    return result;
}

template <class T>
std::shared_ptr<T> TQueue<T>::Top() {
    if (head) {
        return head->GetValue();
    }
}

template <class T>
bool TQueue<T>::Empty() {
    return head == nullptr;
}

template <class T>
size_t TQueue<T>::Length() {
    return num_of_elem;
}

template <class T>
TIterator<TQueueItem<T>, T> TQueue<T>::begin() {
    return TIterator<TQueueItem<T>, T>(head);
}

template <class T>
TIterator<TQueueItem<T>, T> TQueue<T>::end() {
    return TIterator<TQueueItem<T>, T>(nullptr);
}

template <class T>
TQueue<T>::~TQueue() {

}

#include "square.h"
template class TQueue<Square>;
template std::ostream& operator<<(std::ostream& os, const TQueue<Square>& queue);
