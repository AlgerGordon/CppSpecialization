#pragma once

#include <cstdlib>

//
// Created by General on 29.08.2020.
//


#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
class SimpleVector {
public:
    SimpleVector() = default;

    explicit SimpleVector(size_t size) : size_(size), capacity_(size) {
        data_ = new T[size];
        end_ = data_ + size;
    }

    ~SimpleVector() {
        delete[] data_;
    }

    T& operator[](size_t index) {
        // it is the same with *(&data_ + index);
        return data_[index];
    }

    // we need "const T*" to prevent changes using smth like *i = 42 in loops
    const T* begin() const {
        return data_;
    }

    const T* end() const {
        return end_;
    }

    // we need this methods to perform sort() for example
    T* begin() {
        return data_;
    }

    T* end() {
        return end_;
    }

    size_t Size() const {
        return size_;
    }

    size_t Capacity() const {
        return capacity_;
    }

    void PushBack(const T &value) {
        if (size_ >= capacity_) {
            size_t new_cap = capacity_ == 0 ? 1 : 2 * capacity_;
            T* new_data = new T[new_cap];
            copy(begin(), end(), new_data);
            delete[] data_;
            data_ = new_data;
            capacity_ = new_cap;
            end_ = data_ + size_;
        }
        data_[size_++] = value;
        ++end_;
    }

private:
    T* data_ = nullptr;
    T* end_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;
};

template<typename T>
void Print(const SimpleVector<T> &v) {
    // It's important to mark begin() and end() as const
    // because here we work with CONSTANT SimpleVector reference
    //
    // for (const auto& x : v) equals to
    for (auto x = v.begin(); x != v.end(); ++x) {
        cout << *x << ' ';
    }
}