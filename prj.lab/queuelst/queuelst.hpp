#pragma once
#ifndef QUEUELST_QUEUELST_HPP_202404
#define QUEUELST_QUEUELST_HPP_202404

#include <complex/complex.hpp>

#include <cstddef>

class QueueLst final {
public:
    QueueLst() = default;

    QueueLst(const QueueLst& src);

    QueueLst(QueueLst&& src) noexcept;

    ~QueueLst();

    QueueLst& operator=(const QueueLst& src);

    QueueLst& operator=(QueueLst&& src) noexcept;

    [[nodiscard]] bool IsEmpty() const noexcept;

    void Pop() noexcept;

    void Push(const Complex& val);

    [[nodiscard]] Complex& Top() &;

    [[nodiscard]] const Complex& Top() const &;

    void Clear() noexcept;

private:
    struct Node {
        Complex val;
        Node* next = nullptr;
    };

    Node* head_ = nullptr;   //!<
    Node* tail_ = nullptr;   //!<
};

#endif
