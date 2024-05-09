#pragma once
#ifndef QUEUEARRT_QUEUEARRT_HPP_202405
#define QUEUEARRT_QUEUEARRT_HPP_202405

#include <complex/complex.hpp>
#include <memory>
#include <cstddef>
#include <algorithm>
#include <stdexcept>

template<typename T>
class QueueArrT final {
public:
    QueueArrT() = default;

    QueueArrT(const QueueArrT<T>& rhs);

    QueueArrT(QueueArrT<T>&& rhs) noexcept;

    ~QueueArrT() = default;

    QueueArrT<T>& operator=(const QueueArrT<T>& rhs);

    QueueArrT<T>& operator=(QueueArrT<T>&& rhs) noexcept ;

    [[nodiscard]] bool IsEmpty() const noexcept;

    void Pop() noexcept;

    void Push(const T& val);

    [[nodiscard]] T& Top();

    [[nodiscard]] const T& Top() const;

    void Clear() noexcept;

private:
    std::ptrdiff_t capacity_ = 0;
    std::ptrdiff_t head_ = -1;
    std::ptrdiff_t tail_ = -1;
    std::unique_ptr<T[]> data_ = std::make_unique<T[]>(capacity_);
private:
    std::ptrdiff_t Count() const;
};

#endif
