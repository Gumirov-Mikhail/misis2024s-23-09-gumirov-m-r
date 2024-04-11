#pragma once
#ifndef STACKLSTT_STACKLSTT_HPP_202404
#define STACKLSTT_STACKLSTT_HPP_202404

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
    StackArrT(StackArrT<T>&& other);
    StackArrT(const std::initializer_list<T>& list); //??

    void push(const T& value);
    void pop();
    T& top() const;
    void swap(StackArrT<T>& other);
    void merge(StackArrT<T>& other); //??

    bool empty() const;
    std::ptrdiff_t size() const;

    bool operator==(const StackArrT<T>& rhs) const;
    bool operator!=(const StackArrT<T>& rhs) const;

    StackArrT<T>& operator=(const StackArrT<T>& rhs) noexcept;
    StackArrT<T>& operator=(StackArrT<T>&& other);
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
        delete [] data_;
        data_ = new T [size_];
        std::copy(other.data_, other.data_ + i_top_, data_);
    }
}

template <typename T>
StackArrT<T>::StackArrT(StackArrT<T>&& other) {
    swap(other);
}

template <typename T>
StackArrT<T>::StackArrT(const std::initializer_list<T>& list) {

}

template <typename T>
void StackArrT<T>::push(const T& value) {
    if (size_ == 0) {
        size_ = 8;
        data_ = new T [size_];
    }
    else if (i_top_ + 1 >= size_) {
        T* newdata_ = new T [size_ * 2];
        std::copy(data_, data_ + i_top_, newdata_);
        delete [] data_;
        data_ = newdata_;
        size_ *= 2;
    }
    i_top_++;
    data_[i_top_] = value;
}

template <typename T>
void StackArrT<T>::pop() {
    i_top_--;
}

template <typename T>
T& StackArrT<T>::top() const {
    if (empty()) {
        throw std::logic_error("Stack is empty");
    }
    return *(data_ + i_top_);
}

template <typename T>
void StackArrT<T>::swap(StackArrT<T>& other) {
    T* newdata_ = other.data_;
    std::ptrdiff_t newsize_ = other.size_;
    std::ptrdiff_t newi_top_ = other.i_top_;

    other.data_ = data_;
    other.i_top_ = i_top_;
    other.size_ = size_;

    data_ = newdata_;
    size_ = newsize_;
    i_top_ = newi_top_;
}

template <typename T>
void StackArrT<T>::merge(StackArrT<T>& other) {

}

template <typename T>
bool StackArrT<T>::empty() const {
    return (i_top_ == -1);
}

template <typename T>
std::ptrdiff_t StackArrT<T>::size() const {
    return size_;
}

template <typename T>
bool StackArrT<T>::operator==(const StackArrT<T>& rhs) const {
    if (i_top_ == rhs.i_top_) {
        while (data_ != nullptr) {
            if (*data_ != *rhs.data_) {
                return false;
            }
            data_++;
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
StackArrT<T>& StackArrT<T>::operator=(const StackArrT<T>& rhs) noexcept {
    if (this != &rhs) {
        if (!rhs.empty()) {
            size_ = rhs.size_;
            i_top_ = rhs.i_top_;
            T* newdata_ = new T [size_];
            std::copy(rhs.data_, rhs.data_ + i_top_, newdata_);
            delete [] data_;
            data_ = newdata_;
        }
    }
    return *this;
}

template <typename T>
StackArrT<T>& StackArrT<T>::operator=(StackArrT<T>&& other) {
    swap(other);
    return *this;
}

#endif