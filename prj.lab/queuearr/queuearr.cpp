#include <queuearr/queuearr.hpp>

#include <algorithm>
#include <stdexcept>

QueueArr::QueueArr(const QueueArr& rhs)
    : size_(rhs.size_), head_(rhs.head_), tail_(rhs.tail_) {
    if (!rhs.IsEmpty()) {
        data_ = new Complex [size_];
        std::copy(rhs.data_, rhs.data_ + tail_ + 1, data_);
    }
    else {
        data_ = nullptr;
    }
}

QueueArr::QueueArr(QueueArr&& rhs) noexcept {
    std::swap(size_, rhs.size_);
    std::swap(data_, rhs.data_);
    std::swap(head_, rhs.head_);
    std::swap(tail_, rhs.tail_);
}

QueueArr::~QueueArr() {
    delete[] data_;
    data_ = nullptr;
    head_ = -1;
    tail_ = -1;
    size_ = 0;
}

QueueArr& QueueArr::operator=(const QueueArr& rhs) {
    if (this != &rhs) {
        delete [] data_;
        size_ = rhs.size_;
        head_ = rhs.head_;
        tail_ = rhs.tail_;
        if (!rhs.IsEmpty()) {
            data_ = new Complex [size_];
            std::copy(rhs.data_, rhs.data_ + tail_ + 1, data_);
        }
        else {
            data_ = nullptr;
        }
    }
    return *this;
}

QueueArr& QueueArr::operator=(QueueArr&& rhs) noexcept {
    if (this != &rhs) {
        std::swap(size_, rhs.size_);
        std::swap(data_, rhs.data_);
        std::swap(head_, rhs.head_);
        std::swap(tail_, rhs.tail_);
    }
    return *this;
}

bool QueueArr::IsEmpty() const noexcept {
    return head_ == -1;
}

void QueueArr::Pop() noexcept {
    if (!IsEmpty()) {
        if (head_ != tail_) {
            head_++;
        }
        else {
            head_ = -1;
        }
    }
}

void QueueArr::Push(const Complex& val) {
    if (data_ == nullptr) {
        size_ = 8;
        data_ = new Complex [size_];
    }
    if (IsEmpty()) {
        head_++;
        tail_++;
    }

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
    head_ = -1;
}

std::ptrdiff_t QueueArr::Count() const {
    return tail_ + 1;
}