#pragma once
#ifndef QUEUEARR_QUEUEARR_HPP_202404
#define QUEUEARR_QUEUEARR_HPP_202404

#include <complex/complex.hpp>
#include <memory>
#include <cstddef>

class QueueArr final {
public:
    QueueArr() = default;

    QueueArr(const QueueArr& rhs);

    QueueArr(QueueArr&& rhs) noexcept;

    ~QueueArr() = default;

    QueueArr& operator=(const QueueArr& rhs);

    QueueArr& operator=(QueueArr&& rhs) noexcept ;

    [[nodiscard]] bool IsEmpty() const noexcept;

    void Pop() noexcept;

    void Push(const Complex& val);

    [[nodiscard]] Complex& Top();

    [[nodiscard]] const Complex& Top() const;

    void Clear() noexcept;

private:
    std::ptrdiff_t capacity_ = 0;
    std::ptrdiff_t head_ = -1;
    std::ptrdiff_t tail_ = -1;
    std::unique_ptr<Complex[]> data_ = std::make_unique<Complex[]>(capacity_);
private:
    std::ptrdiff_t Count() const;
};

#endif
