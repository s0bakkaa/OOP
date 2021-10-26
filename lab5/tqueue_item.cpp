#include <iostream>
#include "tqueue_item.h"

template <class T>
TQueueItem<T>::TQueueItem(const std::shared_ptr<T>& square) {
    this->item = square;
    this->next = nullptr;
    std::cout << "Queue item is created" << std::endl;
}

template <class T>
TQueueItem<T>::TQueueItem(const std::shared_ptr<TQueueItem<T>>& other) {
    this->item = other->item;
    this->next = other->next;
    std::cout << "Queue item: copied" << std::endl;
}

template <class T>
std::shared_ptr<TQueueItem<T>> TQueueItem<T>::SetNext(std::shared_ptr<TQueueItem<T>>& next_) {
    std::shared_ptr<TQueueItem<T>> prev = this->next;
    this->next = next_;
    return prev;
}

template <class T>
std::shared_ptr<T> TQueueItem<T>::GetItem() {
    return this->item;
}

template <class T>
std::shared_ptr<TQueueItem<T>> TQueueItem<T>::GetNext() {
    return this->next;
}

template <class A>
std::ostream& operator<<(std::ostream& os, const TQueueItem<A>& obj) {
    if (obj.item) {
        os << "{";
        os << *(obj.item);
        os << "}" << std::endl;
    }
    return os;
}