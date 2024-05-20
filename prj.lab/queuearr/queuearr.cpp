#include <queuearr/queuearr.hpp>

#include <algorithm>
#include <stdexcept>

QueueArr::QueueArr(const QueueArr& rhs) {
    if (rhs.head_ != -1) {
        data_ = std::make_unique<Complex[]>(rhs.capacity_);
        capacity_ = rhs.capacity_;
        head_ = 0;
        if (rhs.tail_ > rhs.head_) {
            std::copy(rhs.data_.get() + rhs.head_, rhs.data_.get() + rhs.tail_, data_.get());
            tail_ = rhs.tail_ - rhs.head_;
        }
        else {
            std::copy(rhs.data_.get() + rhs.head_, rhs.data_.get() + rhs.capacity_, data_.get());
            std::copy(rhs.data_.get(), rhs.data_.get() + rhs.tail_, data_.get() + (rhs.capacity_ - rhs.head_));
            tail_ = rhs.capacity_ - rhs.head_ + rhs.tail_;
        }
    }
}

QueueArr::QueueArr(QueueArr&& rhs) noexcept {
    std::swap(capacity_, rhs.capacity_);
    std::swap(head_, rhs.head_);
    std::swap(tail_, rhs.tail_);
    std::swap(data_, rhs.data_);
}

QueueArr& QueueArr::operator=(QueueArr&& rhs) noexcept {
    if (this != &rhs) {
        std::swap(capacity_, rhs.capacity_);
        std::swap(head_, rhs.head_);
        std::swap(tail_, rhs.tail_);
        std::swap(data_, rhs.data_);
    }
    return *this;
}

QueueArr& QueueArr::operator=(const QueueArr& rhs) {
    if (this != &rhs) {
        if (capacity_ < rhs.capacity_) {
            data_ = std::make_unique<Complex[]>(rhs.capacity_);
            capacity_ = rhs.capacity_;
        }
        head_ = 0;
        if (rhs.tail_ > rhs.head_) {
            std::copy(rhs.data_.get() + rhs.head_, rhs.data_.get() + rhs.tail_, data_.get());
            tail_ = rhs.tail_ - rhs.head_;
        }
        else {
            std::copy(rhs.data_.get() + rhs.head_, rhs.data_.get() + rhs.capacity_, data_.get());
            std::copy(rhs.data_.get(), rhs.data_.get() + rhs.tail_, data_.get() + (rhs.capacity_ - rhs.head_));
            tail_ = rhs.capacity_ - rhs.head_ + rhs.tail_;
        }
    }
    return *this;
}

void QueueArr::Push(const Complex& c) {
    if (head_ == -1) {
        capacity_ = 8;
        data_ = std::make_unique<Complex[]>(capacity_);
        head_ = 0;
        tail_ = 0;
    }
    data_[tail_] = c;
    if (head_ == (tail_ + 1) % capacity_) {
        std::unique_ptr<Complex[]> newData = std::make_unique<Complex[]>(capacity_ * 2);
        std::copy(data_.get() + head_, data_.get() + capacity_, newData.get());
        if (tail_ < head_) {
            std::copy(data_.get(), data_.get() + tail_, newData.get() + (capacity_ - head_));
        }
        std::swap(data_, newData);
        capacity_ *= 2;
        head_ = 0;
        tail_ = capacity_ / 2;
    }
    else {
        tail_ = (tail_ + 1) % capacity_;
    }
}

void QueueArr::Pop() noexcept {
    if (head_ != -1) {
        if (head_ != tail_) {
            head_ = (head_ + 1) % capacity_;
        }
        if (head_ == tail_) {
            head_ = -1;
        }

    }
}

Complex& QueueArr::Top() {
    if (head_ < 0) {
        throw std::logic_error("QueueArr - try get top from empty queue");
    }
    else {
        return data_[head_];
    }
}

const Complex& QueueArr::Top() const {
    if (head_ < 0) {
        throw std::logic_error("QueueArr - try get top from empty queue");
    }
    else {
        return data_[head_];
    }
}

bool QueueArr::IsEmpty() const noexcept {
    return head_ < 0;
}

std::ptrdiff_t QueueArr::Count() const {
    return (head_ == -1) ? 0 : (tail_ + capacity_ - head_) % capacity_;
}

void QueueArr::Clear() noexcept {
    head_ = -1;
}