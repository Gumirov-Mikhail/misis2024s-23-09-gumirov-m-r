#include <queuearr/queuearr.hpp>

#include <algorithm>
#include <stdexcept>

QueueArr::QueueArr(const QueueArr& src) {

}

QueueArr::QueueArr(QueueArr&& src) noexcept { //swaps
    std::swap(size_, src.size_);
}

QueueArr::~QueueArr() {

}

QueueArr& QueueArr::operator=(const QueueArr& src) {

}

QueueArr& QueueArr::operator=(QueueArr&& src) noexcept {

}

bool QueueArr::IsEmpty() const noexcept {
    if (tail_ == -1) {
        return true;
    }
    return false;
}

void QueueArr::Pop() noexcept {

}

void QueueArr::Push(const Complex& val) {

}

Complex& QueueArr::Top() {

}

const Complex& QueueArr::Top() const {

}

void QueueArr::Clear() noexcept {
    while(!IsEmpty()) {
        Pop();
    }
}

std::ptrdiff_t QueueArr::Count() const {

}