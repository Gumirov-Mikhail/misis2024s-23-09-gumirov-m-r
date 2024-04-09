#include <stackarr/stackarr.hpp>

//#include <algorithm>
#include <stdexcept>

StackArr::StackArr(const StackArr& src) {
    size_ = src.size_;
    data_ = new Complex [size_];
    for (int i = 0; i < size_; i++) {
        data_[i] = src.data_[i];
        i_top_++;
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
    StackArr Stack(src);
    return Stack;
}

StackArr& StackArr::operator=(StackArr&& src) noexcept {
    StackArr Stack(src);
    return Stack;
}

[[nodiscard]] bool StackArr::IsEmpty() const noexcept {
    if (size_ == 0) {
        return true;
    }
    return false;
}

void StackArr::Pop() noexcept {

}

void StackArr::Push(const Complex& val) {

}

[[nodiscard]] Complex& StackArr::Top() & {
    return data_[i_top_];
}

[[nodiscard]] const Complex& StackArr::Top() const & {
    return data_[i_top_];
}

void StackArr::Clear() noexcept {
    i_top_ = -1;
}
