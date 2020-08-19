//
// Created by General on 17.08.2020.
//


#include <iostream>
#include <vector>
#include <exception>

using namespace std;

template <typename T>
class Deque {
private:
    vector<T> head_;
    vector<T> tail_;

    T& AtImpl(size_t i) {
        return i < head_.size() ? head_[head_.size() - i - 1] : tail_[i - head_.size()];
    }

    void CheckIndex(size_t i) const {
        if (i >= Size())
            throw out_of_range("Index is out of range");
    }

public:
    Deque() : head_({}), tail_({}) {};

    bool Empty() const {
        return head_.empty() && tail_.empty();
    }

    size_t Size() const {
        return (head_.size() + tail_.size());
    }

    T &operator[](size_t index) {
        return AtImpl(index);
    }

    const T &operator[](size_t index) const {
        return AtImpl(index);
    }

    T &At(size_t index) {
        CheckIndex(index);
        return AtImpl(index);
    }

    const T &At(size_t index) const {
        CheckIndex(index);
        return AtImpl(index);
    }

    T &Front() {
        return head_.empty() ? tail_.front() : head_.back();
    }

    const T &Front() const {
        return head_.empty() ? tail_.front() : head_.back();
    }

    T &Back() {
        return tail_.empty() ? head_.front() : tail_.back();
    }

    const T &Back() const {
        return tail_.empty() ? head_.front() : tail_.back();
    }

    void PushFront(const T &item) {
        head_.push_back(item);
    }

    void PushBack(const T &item) {
        tail_.push_back(item);
    }

};


int main() {
    Deque<int> deque;
    deque.PushBack(4);
    deque.PushFront(5);
    cout << deque[1] << endl;
    return 0;
}