#include <queuearr/queuearr.hpp>

#include <algorithm>
#include <stdexcept>

QueueArr::QueueArr(const QueueArr& src) {

}

QueueArr::QueueArr(QueueArr&& src) noexcept { //swaps
    std::swap(size_, src.size_);
    std::swap(data_, src.data_);
    std::swap(head_, src.head_);
    std::swap(tail_, src.tail_);
}

QueueArr::~QueueArr() {

}

QueueArr& QueueArr::operator=(const QueueArr& src) {

}

QueueArr& QueueArr::operator=(QueueArr&& src) noexcept {
    if (this != &src) {
        std::swap(size_, src.size_);
        std::swap(data_, src.data_);
        std::swap(head_, src.head_);
        std::swap(tail_, src.tail_);
    }
    return *this;
}

bool QueueArr::IsEmpty() const noexcept {
    return head_ == -1;
}

void QueueArr::Pop() noexcept {

}

void QueueArr::Push(const Complex& val) {
    if (size_ == 0) {
        size_ = 8;
        data_ = new Complex* [size_];
        head_++;
    }
    else if (tail_ + 1 == size_) {
        Complex* temp = nullptr;
        for (int i = 0; i < size_; i++) {
            temp[i] = data_[i];
        }
    }
    tail_++;
    data_[tail_] = val;
}

Complex& QueueArr::Top() {
    if (IsEmpty()) {
        throw std::logic_error("QueueArr - try get top from empty queue");
    }
    return data_[head_];
}

const Complex& QueueArr::Top() const {
    if (IsEmpty()) {
        throw std::logic_error("QueueArr - try get top from empty queue");
    }
    return data_[head_];
}

void QueueArr::Clear() noexcept {
    head_ == -1;
}

std::ptrdiff_t QueueArr::Count() const {
    return size_;
}