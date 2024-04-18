#include <dynarr/dynarr.hpp>

#include <algorithm>
#include <stdexcept>

DynArr::DynArr(const DynArr& src)
    : capacity_(src.capacity_), size_(src.size_) {
    data_ = std::make_unique<float []> (capacity_);
    std::copy(src.data_.get(), src.data_.get() + size_, data_.get());
}

DynArr::DynArr(DynArr&& src) noexcept {
    std::swap(size_, src.size_);
    std::swap(capacity_, src.capacity_);
    std::swap(data_, src.data_);
}

DynArr::DynArr(const std::ptrdiff_t size)
    : capacity_(size), size_(size) {
    if (size < 0) {
        throw std::invalid_argument("DynArr - try make DynArr with negative size");
    }
    else if (size == 0) {
        throw std::invalid_argument("DynArr - try make DynArr of zero size");
    }
    data_ = std::make_unique<float[]>(capacity_);
}

DynArr& DynArr::operator=(const DynArr& src) {
    if (this != &src) {
        size_ = src.size_;
        if (capacity_ < size_) {
            capacity_ = src.capacity_;
            data_ = std::make_unique<float []> (capacity_);
        }
        std::copy(src.data_.get(), src.data_.get() + size_, data_.get());
    }
    return *this;
}

DynArr& DynArr::operator=(DynArr&& src) noexcept {
    if (this != &src) {
        std::swap(size_, src.size_);
        std::swap(capacity_, src.capacity_);
        std::swap(data_, src.data_);
    }
    return *this;
}

void DynArr::Resize(const std::ptrdiff_t size) {
    if (size < 0) {
        throw std::invalid_argument("DynArr - try Resize DynArr with negative size");
    }
    else if (size == 0) {
        throw std::invalid_argument("DynArr - try Resize DynArr of zero size");
    }
    else {
        if (size_ > size) {
            size_ = size;
        }
        else {
            capacity_ = size;
            std::unique_ptr<float[]> temp_data = std::make_unique<float[]>(capacity_);
            std::copy(data_.get(), data_.get() + size_, temp_data.get());
            size_ = size;
            data_ = std::move(temp_data);
        }
    }
}

float& DynArr::operator[](const std::ptrdiff_t idx) {
    if (idx >= size_) {
        throw std::out_of_range("DynArr - try get element with invalid index");
    }
    else if (idx < 0) {
        throw std::invalid_argument("DynArr - try get element with negative index");
    }
    else {
        return data_[idx];
    }
}

const float& DynArr::operator[](const std::ptrdiff_t idx) const {
    if (idx >= size_) {
        throw std::out_of_range("DynArr - try get element with invalid index");
    }
    else if (idx < 0) {
        throw std::invalid_argument("DynArr - try get element with negative index");
    }
    else {
        return data_[idx];
    }
}