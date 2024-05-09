#pragma once
#ifndef QUEUELSTPRT_QUEUELSTPRT_HPP_202405
#define QUEUELSTPRT_QUEUELSTPRT_HPP_202405

#include <cstddef>
#include <algorithm>
#include <stdexcept>

template<typename T>
class QueueLstPrT {
public:
    QueueLstPrT() = default;

    QueueLstPrT(const QueueLstPrT<T>& rhs);
    QueueLstPrT(QueueLstPrT<T>&& rhs) noexcept;

    ~QueueLstPrT();

    QueueLstPrT<T>& operator=(const QueueLstPrT<T>& rhs);
    QueueLstPrT<T>& operator=(QueueLstPrT<T>&& rhs) noexcept;

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
};

template<typename T>
QueueLstPrT<T>::QueueLstPrT(const QueueLstPrT<T> &rhs) {
    if (!rhs.IsEmpty()) {
        Node* temp = new Node {rhs.head_->val, nullptr};
        head_ = temp;
        Node* p_src = rhs.head_->next;
        Node* p_cur = temp;
        while (p_src != nullptr) {
            temp = new Node {p_src->val, nullptr};
            p_cur->next = temp;
            p_src = p_src->next;
            p_cur = p_cur->next;
        }
    }
}

template<typename T>
QueueLstPrT<T>::QueueLstPrT(QueueLstPrT<T> &&rhs) noexcept {
    std::swap(head_, rhs.head_);
}

template<typename T>
QueueLstPrT<T>::~QueueLstPrT() {
    this->Clear();
}

template<typename T>
QueueLstPrT<T> &QueueLstPrT<T>::operator=(const QueueLstPrT<T> &rhs) {
    if (this != &rhs) {
        this->Clear();
        if (!rhs.IsEmpty()) {
            Node* temp = new Node {rhs.head_->val, nullptr};
            head_ = temp;
            Node* p_src = rhs.head_->next;
            Node* p_cur = temp;
            while (p_src != nullptr) {
                temp = new Node {p_src->val, nullptr};
                p_cur->next = temp;
                p_src = p_src->next;
                p_cur = p_cur->next;
            }
        }
    }
    return *this;
}

template<typename T>
QueueLstPrT<T> &QueueLstPrT<T>::operator=(QueueLstPrT<T> &&rhs) noexcept {
    if (this != &rhs) {
        std::swap(head_, rhs.head_);
    }
    return *this;
}

template<typename T>
bool QueueLstPrT<T>::IsEmpty() const noexcept {
    return head_ == nullptr;
}

template<typename T>
void QueueLstPrT<T>::Pop() noexcept {
    if (!IsEmpty()) {
        Node* temp = head_;
        temp = temp->next;
        delete head_;
        head_ = temp;
    }
}

template<typename T>
void QueueLstPrT<T>::Push(const T &val) {
    if (IsEmpty()) {
        head_ = new Node {val, nullptr};
    }
    else {
        Node* temp = head_->next;
        Node* extra = head_;
        bool flag = true;
        if (val < extra->val) {
            Node* cur = new Node {val, extra};
            head_ = cur;
        }
        else {
            while (temp != nullptr) {
                if (val > temp->val) {
                    extra = temp;
                    temp = temp->next;
                }
                else {
                    Node* cur = new Node {val, temp};
                    extra->next = cur;
                    flag = false;
                    break;
                }
            }
            if (flag) {
                Node* cur = new Node {val, nullptr};
                extra->next = cur;
            }
        }
    }
}

template<typename T>
T &QueueLstPrT<T>::Top() &{
    if (head_ == nullptr) {
        throw std::logic_error("QueueLstPrT - try get top from empty priority_queue");
    }
    return head_->val;
}

template<typename T>
const T &QueueLstPrT<T>::Top() const &{
    if (head_ == nullptr) {
        throw std::logic_error("QueueLstPrT - try get top from empty priority_queue");
    }
    return head_->val;
}

template<typename T>
void QueueLstPrT<T>::Clear() noexcept {
    while (!IsEmpty()) {
        Pop();
    }
}

#endif