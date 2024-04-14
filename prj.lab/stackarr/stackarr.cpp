#include <stackarr/stackarr.hpp>

#include <algorithm>
#include <stdexcept>

StackArr::StackArr(const StackArr& src)
    : i_top_(src.i_top_), size_(src.size_) {
    if (!src.IsEmpty()) {
        data_ = new Complex [size_];
        std::copy(src.data_, src.data_ + i_top_ + 1, data_);
    }
}

StackArr::StackArr(StackArr&& src) noexcept {
    std::swap(size_, src.size_);
    std::swap(i_top_, src.i_top_);
    std::swap(data_, src.data_);
}

StackArr::~StackArr() {
    delete[] data_;
    data_ = nullptr;
}

StackArr& StackArr::operator=(const StackArr& src) {
    if (this != &src) {
        i_top_ = src.i_top_;
        size_ = src.size_;
        delete [] data_;
        data_ = nullptr;
        if (!src.IsEmpty()) {
            data_ = new Complex [size_];
            std::copy(src.data_, src.data_ + i_top_ + 1, data_);
        }
    }
    return *this;
}

StackArr& StackArr::operator=(StackArr&& src) noexcept {
    if (this != &src) {
        std::swap(size_, src.size_);
        std::swap(i_top_, src.i_top_);
        std::swap(data_, src.data_);
    }
    return *this;
}

bool StackArr::IsEmpty() const noexcept {
    if (i_top_ == -1) {
        return true;
    }
    return false;
}

void StackArr::Pop() noexcept {
    if (!IsEmpty()) {
        i_top_--;
    }
}

void StackArr::Push(const Complex& val) {
    if (size_ == 0) {
        size_ = 8;
        data_ = new Complex[size_];
    }
    else if (i_top_ + 1 >= size_) {
        Complex* temp = new Complex[size_ * 2];
        std::copy(data_, data_ + i_top_ + 1, temp);
        delete [] data_;
        data_ = temp;
        size_ *= 2;
    }
    i_top_++;
    data_[i_top_] = val;
}

Complex& StackArr::Top() & {
    if (IsEmpty()) {
        throw std::logic_error("StackArr - try get top from empty stack.");
    }
    return data_[i_top_];
}

const Complex& StackArr::Top() const & {
    if (IsEmpty()) {
        throw std::logic_error("StackArr - try get top from empty stack.");
    }
    return data_[i_top_];
}

void StackArr::Clear() noexcept {
    i_top_ = -1;
}
