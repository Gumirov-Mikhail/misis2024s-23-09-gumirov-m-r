#include <stacklst/stacklst.hpp>

#include <algorithm>
#include <stdexcept>
StackLst::StackLst(const StackLst& src) {
    if (!src.IsEmpty()) {
        Node* temp = new Node {src.head_->val, nullptr};
        head_ = temp;
        Node* p_src = src.head_->next;
        Node* p_cur = temp;
        while (p_src != nullptr) {
            Node* temp = new Node {p_src->val, nullptr};
            p_cur->next = temp;
            p_src = p_src->next;
            p_cur = temp;
        }
    }
    else {
        head_ = nullptr;
    }
}

StackLst::StackLst(StackLst&& src) noexcept {
    std::swap(head_, src.head_);
}

StackLst& StackLst::operator=(const StackLst& src) {
    if (this != &src) {
        Node* temp = head_;
        while (temp != nullptr) {
            head_ = head_->next;
            delete temp;
            temp = head_;
        }
        if (!src.IsEmpty()) {
            Node* temp = new Node {src.head_->val, nullptr};
            head_ = temp;
            Node* p_src = src.head_->next;
            Node* p_cur = temp;
            while (p_src != nullptr) {
                Node* temp = new Node {p_src->val, nullptr};
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

StackLst& StackLst::operator=(StackLst&& src) noexcept {
    if (this != &src) {
        std::swap(head_, src.head_);
    }
    return *this;
}

[[nodiscard]] bool StackLst::IsEmpty() const noexcept {
    if (head_ == nullptr) {
        return true;
    }
    return false;
}

void StackLst::Pop() noexcept {
    if (head_ != nullptr) {
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
        temp = nullptr;
    }
}

void StackLst::Push(const Complex& val) {
    Node* temp = new Node {val, head_};
    head_ = temp;
}

[[nodiscard]] Complex& StackLst::Top() & {
    if (IsEmpty()) {
        throw std::logic_error("StackLst - try get top from empty stack.");
    }
    return head_->val;
}

[[nodiscard]] const Complex& StackLst::Top() const & {
    if (IsEmpty()) {
        throw std::logic_error("StackLst - try get top from empty stack.");
    }
    return head_->val;
}

void StackLst::Clear() noexcept {
    while (!IsEmpty()) {
        Pop();
    }
}