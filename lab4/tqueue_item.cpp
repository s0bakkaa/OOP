#include "tqueue_item.h"

template <class T>
TQueueItem<T>::TQueueItem(const std::shared_ptr<T>& square) {
    this->square = square;
    this->next = nullptr;
    std::cout << "Queue item is created" << std::endl;
}

template <class T>
TQueueItem<T>::TQueueItem(const std::shared_ptr<TQueueItem<T>>& other) {
    this->square = other->square;
    this->next = other->next;
    std::cout << "Queue item is copied" << std::endl;
}

template <class T>
std::shared_ptr<TQueueItem<T>> TQueueItem<T>::SetNext(std::shared_ptr<TQueueItem<T>> &next) {
    std::shared_ptr<TQueueItem<T>> prev = this->next;
    this->next = next;
    return prev;
}

template <class T>
std::shared_ptr<TQueueItem<T>> TQueueItem<T>::GetNext() {
    return this->next;
}

template <class T>
std::shared_ptr<T> TQueueItem<T>::GetSquare() const {
    return this->square;
}

template <class A>
std::ostream& operator<<(std::ostream& os, const TQueueItem<A>& obj) {
    os << "Item: " << *obj.square << std::endl;
    return os;
}

template <class T>
TQueueItem<T>::~TQueueItem() {
    std::cout << "The queue item is deleted" << std::endl;
}

#include "square.h"
template class TQueueItem<Square>;
template std::ostream& operator<<(std::ostream& os, const TQueueItem<Square>& obj);
