#pragma once
#ifndef STACKARRT_STACKARRT_HPP_202404
#define STACKARRT_STACKARRT_HPP_202404

#include <algorithm>
#include <stdexcept>
#include <cstddef>
#include <initializer_list>

template <typename T>
class StackArrT {
public:
    StackArrT();
    ~StackArrT();
    StackArrT(const StackArrT<T>& other);
    StackArrT(StackArrT<T>&& other) noexcept;
    StackArrT(const std::initializer_list<T>& list);

    void push(const T& value);
    void pop();
    T& top() const;
    void swap(StackArrT<T>& other);
    void merge(StackArrT<T>& other);

    [[nodiscard]] bool empty() const;
    [[nodiscard]] std::ptrdiff_t size() const;

    bool operator==(const StackArrT<T>& rhs) const;
    bool operator!=(const StackArrT<T>& rhs) const;

    StackArrT<T>& operator=(const StackArrT<T>& rhs);
    StackArrT<T>& operator=(StackArrT<T>&& other) noexcept;
private:
    std::ptrdiff_t size_ = 0;   //!< число элементов в буфере
    std::ptrdiff_t i_top_ = -1; //!< индекс top элемента
    T* data_ = nullptr;   //!< элементы стека
};

template <typename T>
StackArrT<T>::StackArrT() = default;

template <typename T>
StackArrT<T>::~StackArrT() {
    delete [] data_;
    data_ = nullptr;
}

template <typename T>
StackArrT<T>::StackArrT(const StackArrT<T>& other)
    : i_top_(other.i_top_), size_(other.size_) {
    if (!other.empty()) {
        data_ = new T [size_];
        std::copy(other.data_, other.data_ + i_top_ + 1, data_);
    }
}

template <typename T>
StackArrT<T>::StackArrT(StackArrT<T>&& other) noexcept {
    swap(other);
}

template <typename T>
StackArrT<T>::StackArrT(const std::initializer_list<T>& list) {
    size_ = list.size();
    i_top_ = size_ - 1;
    data_ = new T [size_];
    std::copy(list.begin(), list.end(), data_);
}

template <typename T>
void StackArrT<T>::push(const T& value) {
    if (size_ == 0) {
        size_ = 8;
        data_ = new T [size_];
    }
    else if (i_top_ + 1 >= size_) {
        T* temp = new T [size_ * 2];
        std::copy(data_, data_ + i_top_ + 1, temp);
        delete [] data_;
        data_ = temp;
        size_ *= 2;
    }
    i_top_++;
    data_[i_top_] = value;
}

template <typename T>
void StackArrT<T>::pop() {
    if (empty()) {
        throw std::logic_error("StackArrT - try pop from empty stack.");
    }
    i_top_--;
}

template <typename T>
T& StackArrT<T>::top() const {
    if (empty()) {
        throw std::logic_error("StackArrT - try get top from empty stack.");
    }
    return data_[i_top_];
}

template <typename T>
void StackArrT<T>::swap(StackArrT<T>& other) {
    T* temp_data_ = other.data_;
    std::ptrdiff_t temp_size_ = other.size_;
    std::ptrdiff_t temp_i_top_ = other.i_top_;

    other.data_ = data_;
    other.i_top_ = i_top_;
    other.size_ = size_;

    data_ = temp_data_;
    size_ = temp_size_;
    i_top_ = temp_i_top_;
}

template <typename T>
void StackArrT<T>::merge(StackArrT<T>& other) {
    if (empty()) {
        swap(other);
    }
    else {
        size_ += other.size_;
        T* temp = new T [size_];
        std::copy(data_, data_ + i_top_ + 1, temp);
        std::copy(other.data_, other.data_ + other.i_top_ + 1, temp + i_top_ + 1);
        i_top_ += other.i_top_ + 1;
        delete[] data_;
        data_ = temp;

        delete[] other.data_;
        other.size_ = 0;
        other.i_top_ = -1;
        other.data_ = nullptr;
    }
}

template <typename T>
bool StackArrT<T>::empty() const {
    return (i_top_ == -1);
}

template <typename T>
std::ptrdiff_t StackArrT<T>::size() const {
    return i_top_ + 1;
}

template <typename T>
bool StackArrT<T>::operator==(const StackArrT<T>& rhs) const {
    if (i_top_ == rhs.i_top_) {
        for (int i = 0; i < i_top_ + 1; i++) {
            if (data_[i] != rhs.data_[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

template <typename T>
bool StackArrT<T>::operator!=(const StackArrT<T>& rhs) const {
    return !(operator==(rhs));
}

template <typename T>
StackArrT<T>& StackArrT<T>::operator=(const StackArrT<T>& rhs) {
    if (this != &rhs) {
        size_ = rhs.size_;
        i_top_ = rhs.i_top_;
        delete [] data_;
        data_ = nullptr;
        if (!rhs.empty()) {
            T* temp = new T [size_];
            std::copy(rhs.data_, rhs.data_ + i_top_ + 1, temp);
            data_ = temp;
        }
    }
    return *this;
}

template <typename T>
StackArrT<T>& StackArrT<T>::operator=(StackArrT<T>&& other) noexcept {
    if (this != &other) {
        swap(other);
    }
    return *this;
}

#endif