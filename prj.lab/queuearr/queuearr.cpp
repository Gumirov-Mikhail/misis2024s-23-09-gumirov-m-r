#include <queuearr/queuearr.hpp>

#include <algorithm>
#include <stdexcept>

QueueArr::QueueArr(const QueueArr& src) {

}

QueueArr::QueueArr(QueueArr&& src) noexcept {
    std::swap(size_, src.size_);
    std::swap(data_, src.data_);
    std::swap(head_, src.head_);
    std::swap(tail_, src.tail_);
}

QueueArr::~QueueArr() {
    delete[] data_;
    data_ = nullptr;
    head_ = -1;
    tail_ = -1;
    size_ = 0;
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
    return tail_ + 1;
}