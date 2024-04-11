#include <stacklst/stacklst.hpp>

#include <stdexcept>

StackLst::StackLst(const StackLst& src) {
    if (!src.IsEmpty()) {

    }
}

StackLst::StackLst(StackLst&& src) noexcept {
    std::swap(head_, src.head_);
}

StackLst::~StackLst() {
    while (head_ != nullptr) {
        Node* temp = head_;
        delete temp;
        head_ = head_->next;
        temp = nullptr;
    }
    delete head_;
    head_ = nullptr;
}

StackLst& StackLst::operator=(const StackLst& src) noexcept {
    if (this != &src) {

    }
    return *this;
}

StackLst& StackLst::operator=(StackLst&& src) noexcept {
    std::swap(head_, src.head_);
    return *this;
}

[[nodiscard]] bool StackLst::IsEmpty() const noexcept {
    if (head_ == nullptr) {
        return true;
    }
    return false;
}

void StackLst::Pop() noexcept {
    if (!IsEmpty()) {

    }

}

void StackLst::Push(const Complex& val) noexcept {
    Node* newnode = new Node(val);
    newnode->next = head_;
    head_ = newnode;
    newnode = nullptr;
    head_ = new Node{val, head_};
}

[[nodiscard]] Complex& StackLst::Top() & {
    if (IsEmpty()) {
        throw std::logic_error("StackLstT - try get top form empty stack.");
    }
    return head_->val;
}

[[nodiscard]] const Complex& StackLst::Top() const & {
    if (IsEmpty()) {
        throw std::logic_error("StackLstT - try get top form empty stack.");
    }
    return head_->val;
}

void StackLst::Clear() noexcept {
    while (!IsEmpty()) {
        Pop();
    }
}