#pragma once
#ifndef QUEUELSTT_QUEUELSTT_HPP_202405
#define QUEUELSTT_QUEUELSTT_HPP_202405

#include <algorithm>
#include <stdexcept>
#include <cstddef>

template<typename T>
class QueueLstT final {
public:
    QueueLstT() = default;

    QueueLstT(const QueueLstT<T>& src);

    QueueLstT(QueueLstT<T>&& src) noexcept;

    ~QueueLstT();

    QueueLstT<T>& operator=(const QueueLstT<T>& src);

    QueueLstT<T>& operator=(QueueLstT<T>&& src) noexcept;

    [[nodiscard]] bool IsEmpty() const noexcept;

    void Pop() noexcept;

    void Push(const T& val);

    [[nodiscard]] T& Top() &;

    [[nodiscard]] const T& Top() const &;

    void Clear() noexcept;

private:
    struct Node {
        T val;
        Node* next = nullptr;
    };

    Node* head_ = nullptr;
    Node* tail_ = nullptr;
};

template<typename T>
QueueLstT<T>::QueueLstT(const QueueLstT<T> &src) {
    if (!src.IsEmpty()) {
        Node* temp = new Node {src.head_->val, nullptr};
        Node* p_src = src.head_->next;
        tail_ = temp;
        head_ = temp;
        while (p_src != nullptr) {
            temp = new Node {p_src->val, nullptr};
            tail_->next = temp;
            p_src = p_src->next;
            tail_ = tail_->next;
        }
    }
}

template<typename T>
QueueLstT<T>::QueueLstT(QueueLstT<T> &&src) noexcept {
    std::swap(head_, src.head_);
    std::swap(tail_, src.tail_);
}

template<typename T>
QueueLstT<T>::~QueueLstT() {
    while (head_ != nullptr) {
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
        temp = nullptr;
    }
}

template<typename T>
QueueLstT<T> &QueueLstT<T>::operator=(const QueueLstT<T> &src) {
    if (this != &src) {
        this->Clear();
        if (!src.IsEmpty()) {
            Node* temp = new Node {src.head_->val, nullptr};
            Node* p_src = src.head_->next;
            tail_ = temp;
            head_ = temp;
            while (p_src != nullptr) {
                temp = new Node {p_src->val, nullptr};
                tail_->next = temp;
                p_src = p_src->next;
                tail_ = tail_->next;
            }
        }
    }
    return *this;
}

template<typename T>
QueueLstT<T> &QueueLstT<T>::operator=(QueueLstT<T> &&src) noexcept {
    if (this != &src) {
        std::swap(head_, src.head_);
        std::swap(tail_, src.tail_);
    }
    return *this;
}

template<typename T>
bool QueueLstT<T>::IsEmpty() const noexcept {
    return head_ == nullptr;
}

template<typename T>
void QueueLstT<T>::Pop() noexcept {
    if (!IsEmpty()) {
        Node* p_cur = head_;
        p_cur = p_cur->next;
        delete head_;
        head_ = p_cur;
    }
}

template<typename T>
void QueueLstT<T>::Push(const T &val) {
    if (!IsEmpty()) {
        Node* temp = tail_;
        tail_ = new Node {val, nullptr};
        temp->next = tail_;
    }
    else {
        head_ = new Node {val, nullptr};
        tail_ = head_;
    }
}

template<typename T>
T &QueueLstT<T>::Top() &{
    if (IsEmpty()) {
        throw std::logic_error("QueueLstT - try get top from empty queue");
    }
    return head_->val;
}

template<typename T>
const T &QueueLstT<T>::Top() const &{
    if (IsEmpty()) {
        throw std::logic_error("QueueLstT - try get top from empty queue");
    }
    return head_->val;
}

template<typename T>
void QueueLstT<T>::Clear() noexcept {
    while (!IsEmpty()) {
        Pop();
    }
}

#endif
