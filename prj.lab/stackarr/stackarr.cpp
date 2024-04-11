#include <stackarr/stackarr.hpp>

#include <stdexcept>

StackArr::StackArr(const StackArr& src)
    : i_top_(src.i_top_), size_(src.size_){
    if (!src.IsEmpty()) {
        delete [] data_;
        data_ = new Complex [size_];
        std::copy(src.data_, src.data_ + size_, data_);
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
        if (size_ < src.size_) {
            size_ = src.size_;
            delete [] data_;
            data_ = new Complex [size_];
        }
        i_top_ = src.i_top_;
        std::copy(src.data_, src.data_ + size_, data_);
    }
    return *this;
}

StackArr& StackArr::operator=(StackArr&& src) noexcept {
    std::swap(size_, src.size_);
    std::swap(i_top_, src.i_top_);
    std::swap(data_, src.data_);
    return *this;
}

[[nodiscard]] bool StackArr::IsEmpty() const noexcept {
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

void StackArr::Push(const Complex& val) noexcept {
    if (size_ == 0) {
        size_ = 8;
        data_ = new Complex[size_];
    }
    else if (i_top_ + 1 >= size_) {
        Complex* Newdata = new Complex[size_ * 2];
        std::copy(data_, data_ + size_, Newdata);
        delete [] data_;
        data_ = Newdata;
        size_ *= 2;
    }
    i_top_++;
    data_[i_top_] = val;
}

[[nodiscard]] Complex& StackArr::Top() & {
    if (IsEmpty()) {
        throw std::logic_error("Stack is empty");
    }
    return data_[i_top_];
}

[[nodiscard]] const Complex& StackArr::Top() const & {
    if (IsEmpty()) {
        throw std::logic_error("Stack is empty");
    }
    return data_[i_top_];
}

void StackArr::Clear() noexcept {
    i_top_ = -1;
}
