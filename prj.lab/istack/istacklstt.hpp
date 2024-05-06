#pragma once
#ifndef ISTACKLSTT_ISTACKLSTT_HPP_202404
#define ISTACKLSTT_ISTACKLSTT_HPP_202404

#include <istack/istackbase.hpp>

template <typename T>
class StackLstT : public IStackBase<T> {
public:
    StackLstT() {
        head_ = nullptr;
    }

    ~StackLstT() override {
        Node* temp = head_;
        while (temp != nullptr) {
            head_ = head_->next;
            delete temp;
            temp = head_;
        }
    }

    StackLstT(const StackLstT<T>& other) {
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
        else {
            head_ = nullptr;
        }
    }

    StackLstT(StackLstT<T>&& other) noexcept {
        this->swap(other);
    }

    StackLstT(const std::initializer_list<T>& list) {
        T* mas = new T [list.size()];
        std::reverse_copy(list.begin(), list.end(), mas);
        Node* temp = new Node {mas[0], nullptr};
        head_ = temp;
        Node* p_cur = temp;
        for (int i = 1; i < list.size(); i++) {
            Node* temp = new Node {mas[i], nullptr};
            p_cur->next = temp;
            p_cur = temp;
        }
    }

    void push(const T& value) override {
        Node* temp = new Node {value, head_};
        head_ = temp;
    }

    void pop() override {
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

    T& top() const override {
        if (empty()) {
            throw std::logic_error("StackLstT - try get top from empty stack.");
        }
        return head_->value;
    }

    void swap(StackLstT<T>& other) {
        std::swap(head_, other.head_);
    }

    void merge(StackLstT<T>& other) {
        if (empty()) {
            this->swap(other);
        }
        else if (!other.empty()) {
            Node* temp = other.head_;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = head_;
            head_ = other.head_;
            other.head_ = nullptr;
        }
    }

    [[nodiscard]] bool empty() const override {
        if (head_ == nullptr) {
            return true;
        }
        return false;
    }

    [[nodiscard]] std::ptrdiff_t size() const override {
        Node* temp = head_;
        std::ptrdiff_t counter = 0;
        while (temp != nullptr) {
            temp = temp->next;
            counter++;
        }
        return counter;
    }

    bool operator==(const StackLstT<T>& rhs) const {
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

    bool operator!=(const StackLstT<T>& rhs) const {
        return !operator==(rhs);
    }

    StackLstT<T>& operator=(const StackLstT<T>& rhs) noexcept {
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
            else {
                head_ = nullptr;
            }
        }
        return *this;
    }

    StackLstT<T>& operator=(StackLstT<T>&& other) noexcept {
        if (this != &other) {
            this->swap(other);
        }
        return *this;
    }

    void printToStream(std::ostream &os) const override {
        os << '[';
        Node* temp = head_;
        bool flag = false;
        while (temp != nullptr) {
            if (flag) {
                os << ", ";
            }
            os << temp->value;
            temp = temp->next;
            flag = true;
        }
        os << ']';
    }

private:
    struct Node {
        T value;
        Node* next = nullptr;
    };

    Node* head_ = nullptr;
};

template<typename T>
inline std::ostream& operator<<(std::ostream& os, StackLstT<T> &rhs) noexcept {
    rhs.printToStream(os);
    return os;
}

#endif
