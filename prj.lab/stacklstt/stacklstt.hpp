#pragma once
#ifndef STACKLSTT_STACKLSTT_HPP_202404
#define STACKLSTT_STACKLSTT_HPP_202404

#include <algorithm>
#include <stdexcept>
#include <cstddef>
#include <initializer_list>

template <typename T>
class StackLstT {
public:
    StackLstT();
    ~StackLstT();
    StackLstT(const StackLstT<T>& other);
    StackLstT(StackLstT<T>&& other);
    StackLstT(const std::initializer_list<T>& list);

    void push(const T& value);
    void pop();
    T& top() const;
    void swap(StackLstT<T>& other);
    void merge(StackLstT<T>& other);

    bool empty() const;
    std::ptrdiff_t size() const;

    bool operator==(const StackLstT<T>& rhs) const;
    bool operator!=(const StackLstT<T>& rhs) const;

    StackLstT<T>& operator=(const StackLstT<T>& rhs) noexcept;
    StackLstT<T>& operator=(StackLstT<T>&& other);

private:
    struct Node {
        T value;
        Node* next = nullptr;
    };

    Node* head_ = nullptr;
};

template<typename T>
StackLstT<T>::StackLstT() = default;

template<typename T>
StackLstT<T>::~StackLstT() {
    Node* temp = head_;
    while (temp != nullptr) {
        head_ = head_->next;
        delete temp;
        temp = head_;
    }
}

template<typename T>
StackLstT<T>::StackLstT(const StackLstT<T> &other) {
    if (!other.empty()) {
        Node* temp = new Node {other.head_->value, nullptr};
        head_ = temp;
        Node* p_src = other.head_->next;
        Node* p_cur = temp;
        while (p_src != nullptr) {
            temp = new Node {p_src->value, nullptr};
            p_cur->next = temp;
            p_src = p_src->next;
            p_cur = temp;
        }
    }
}

template<typename T>
StackLstT<T>::StackLstT(StackLstT<T> &&other) {
    this->swap(other);
}

template<typename T>
StackLstT<T>::StackLstT(const std::initializer_list<T> &list) {
    T* mas = new T [list.size()];
    std::copy(list.end(), list.begin(), mas);
    Node* temp = new Node {mas[0], nullptr};
    head_ = temp;
    Node* p_cur = temp;
    for (int i = 1; i < list.size(); i++) {
        Node* temp = new Node {mas[i], nullptr};
        p_cur->next = temp;
        p_cur = temp;
    }
}

template<typename T>
void StackLstT<T>::push(const T &value) {
    Node* temp = new Node {value, head_};
    head_ = temp;
}

template<typename T>
void StackLstT<T>::pop() {
    if (empty()) {
        throw std::logic_error("StackLstT - try pop from empty stack.");
    }
    else {
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
        temp = nullptr;
    }
}

template<typename T>
T &StackLstT<T>::top() const {
    if (empty()) {
        throw std::logic_error("StackLstT - try get top from empty stack.");
    }
    return head_->value;
}

template<typename T>
void StackLstT<T>::swap(StackLstT<T> &other) {
    std::swap(head_, other.head_);
}

template<typename T>
void StackLstT<T>::merge(StackLstT<T> &other) {
    if (other.empty()) {
        this->swap(other);
    }
    else {
        Node* temp = head_;
        while (temp->next != nullptr) {
            head_ = head_->next;
        }
        temp->next = other.head_;
    }
}

template<typename T>
bool StackLstT<T>::empty() const {
    if (head_ == nullptr) {
        return true;
    }
    return false;
}

template<typename T>
std::ptrdiff_t StackLstT<T>::size() const {
    Node* temp = head_;
    std::ptrdiff_t counter = 0;
    while (temp != nullptr) {
        temp = temp->next;
        counter++;
    }
    return counter;
}

template<typename T>
bool StackLstT<T>::operator==(const StackLstT<T> &rhs) const {
    Node* temp1 = head_;
    Node* temp2 = rhs.head_;
    if (size() == rhs.size()) {
        while (temp2 != nullptr) {
            if (temp1->value != temp2->value) {
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
    return false;
}

template<typename T>
bool StackLstT<T>::operator!=(const StackLstT<T> &rhs) const {
    return !operator==(rhs);
}

template<typename T>
StackLstT<T> &StackLstT<T>::operator=(const StackLstT<T> &rhs) noexcept {
    if (this != &rhs) {
        if (!rhs.empty()) {
            Node* temp = new Node {rhs.head_->value, nullptr};
            head_ = temp;
            Node* p_src = rhs.head_->next;
            Node* p_cur = temp;
            while (p_src != nullptr) {
                temp = new Node {p_src->value, nullptr};
                p_cur->next = temp;
                p_src = p_src->next;
                p_cur = temp;
            }
        }
    }
}

template<typename T>
StackLstT<T> &StackLstT<T>::operator=(StackLstT<T> &&other) {
    this->swap(other);
    return *this;
}

#endif