#include<iostream>
#include "tqueue.h"

template <class T>
TQueue<T>::TQueue() : first(nullptr), last(nullptr), n(0) {}

template <class T>
TQueue<T>::TQueue(const TQueue<T>& other) {
    first = other.first;
    last = other.last;
    n = other.n;
    std::cout << "Queue is copied" << std::endl;
}

template <class T>
void TQueue<T>::push(std::shared_ptr<T>&& item) {
    std::shared_ptr<TQueueItem<T>> tail =
        std::make_shared<TQueueItem<T>>(TQueueItem<T>(item));
    if (this->empty()) {
        this->first = this->last = tail;
    }
    else if (n == 1) {
        last = tail;
        first->SetNext(tail);
    }
    else {
        this->last->SetNext(tail);
        last = tail;
    }
    n++;
}

template <class T>
std::shared_ptr<T> TQueue<T>::pop() {
    std::shared_ptr<T> result;
    if (first) {
        result = first->GetItem();
        first = first->GetNext();;
    }
    return result;
}

template <class T> 
std::shared_ptr<T> TQueue<T>::top() {
    if (first) {
        return first->GetItem();
    }
}

template <class T> 
size_t TQueue<T>::size() { 
    return n; 
}

template <class T> bool TQueue<T>::empty() { 
    return first == nullptr; 
}

template <class T> std::ostream& operator<<(std::ostream& os, const TQueue<T>& q) {
    std::shared_ptr<TQueueItem<T>> item = q.first;
    while (item) {
        os << *item;
        item = item->GetNext();
    }
    return os;
}