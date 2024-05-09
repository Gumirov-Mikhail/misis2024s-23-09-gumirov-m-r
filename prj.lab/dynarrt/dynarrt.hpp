#pragma once
#ifndef DYNARRT_DYNARRT_HPP_202405
#define DYNARRT_DYNARRT_HPP_202405

#include <cstddef>
#include <memory>
#include <algorithm>
#include <stdexcept>

template<typename T>
class DynArrT {
public:
    DynArrT() = default;
    DynArrT(const DynArrT<T>& src);
    DynArrT(DynArrT<T>&& src) noexcept;
    DynArrT(const std::ptrdiff_t size);

    ~DynArrT() = default;

    DynArrT<T>& operator=(const DynArrT<T>& src);
    DynArrT<T>& operator=(DynArrT<T>&& src) noexcept;

    [[nodiscard]] std::ptrdiff_t Size() const noexcept { return size_; }
    void Resize(const std::ptrdiff_t size);

    [[nodiscard]] T& operator[](const std::ptrdiff_t idx);
    [[nodiscard]] const T& operator[](const std::ptrdiff_t idx) const;

private:
    std::ptrdiff_t capacity_ = 0;
    std::ptrdiff_t size_ = 0;
    std::unique_ptr<T[]> data_ = nullptr;
};

template<typename T>
DynArrT<T>::DynArrT(const DynArrT<T> &src) : capacity_(src.capacity_), size_(src.size_) {
    data_ = std::make_unique<T[]> (capacity_);
    std::copy(src.data_.get(), src.data_.get() + size_, data_.get());
}

template<typename T>
DynArrT<T>::DynArrT(DynArrT<T> &&src) noexcept {
    std::swap(size_, src.size_);
    std::swap(capacity_, src.capacity_);
    std::swap(data_, src.data_);
}

template<typename T>
DynArrT<T>::DynArrT(const std::ptrdiff_t size) : capacity_(size), size_(size) {
    if (size < 0) {
        throw std::invalid_argument("DynArrT - try make DynArrT with negative size");
    }
    else if (size == 0) {
        throw std::invalid_argument("DynArrT - try make DynArrT of zero size");
    }
    data_ = std::make_unique<T[]>(capacity_);
}

template<typename T>
DynArrT<T> &DynArrT<T>::operator=(const DynArrT<T> &src) {
    if (this != &src) {
        size_ = src.size_;
        if (capacity_ < size_) {
            capacity_ = src.capacity_;
            data_ = std::make_unique<T[]> (capacity_);
        }
        std::copy(src.data_.get(), src.data_.get() + size_, data_.get());
    }
    return *this;
}

template<typename T>
DynArrT<T> &DynArrT<T>::operator=(DynArrT<T> &&src) noexcept {
    if (this != &src) {
        std::swap(size_, src.size_);
        std::swap(capacity_, src.capacity_);
        std::swap(data_, src.data_);
    }
    return *this;
}

template<typename T>
void DynArrT<T>::Resize(const std::ptrdiff_t size) {
    if (size < 0) {
        throw std::invalid_argument("DynArrT - try Resize DynArrT with negative size");
    }
    else if (size == 0) {
        throw std::invalid_argument("DynArrT - try Resize DynArrT of zero size");
    }
    else {
        if (size_ > size) {
            size_ = size;
        }
        else {
            capacity_ = size;
            std::unique_ptr<T[]> temp_data = std::make_unique<T[]>(capacity_);
            std::copy(data_.get(), data_.get() + size_, temp_data.get());
            size_ = size;
            data_ = std::move(temp_data);
        }
    }
}

template<typename T>
T &DynArrT<T>::operator[](const std::ptrdiff_t idx) {
    if (idx >= size_) {
        throw std::out_of_range("DynArrT - try get element with invalid index");
    }
    else if (idx < 0) {
        throw std::invalid_argument("DynArrT - try get element with negative index");
    }
    else {
        return data_[idx];
    }
}

template<typename T>
const T &DynArrT<T>::operator[](const std::ptrdiff_t idx) const {
    if (idx >= size_) {
        throw std::out_of_range("DynArrT - try get element with invalid index");
    }
    else if (idx < 0) {
        throw std::invalid_argument("DynArrT - try get element with negative index");
    }
    else {
        return data_[idx];
    }
}

#endif