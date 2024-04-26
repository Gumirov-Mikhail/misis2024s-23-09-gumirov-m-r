#include <queuelst/queuelst.hpp>

#include <algorithm>
#include <stdexcept>

QueueLst::QueueLst(const QueueLst& src) {
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

QueueLst::QueueLst(QueueLst&& src) noexcept {
    std::swap(head_, src.head_);
    std::swap(tail_, src.tail_);
}

QueueLst::~QueueLst() {
    while (head_ != nullptr) {
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
        temp = nullptr;
    }
}

QueueLst& QueueLst::operator=(const QueueLst& src) {
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

QueueLst& QueueLst::operator=(QueueLst&& src) noexcept {
    if (this != &src) {
        std::swap(head_, src.head_);
        std::swap(tail_, src.tail_);
    }
    return *this;
}

bool QueueLst::IsEmpty() const noexcept {
    return head_ == nullptr;
}

void QueueLst::Pop() noexcept {
    if (!IsEmpty()) {
        Node* p_cur = head_;
        p_cur = p_cur->next;
        delete head_;
        head_ = p_cur;
    }
}

void QueueLst::Push(const Complex& val) {
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

[[nodiscard]] Complex& QueueLst::Top() & {
    if (IsEmpty()) {
        throw std::logic_error("QueueLst - try get top from empty queue");
    }
    return head_->val;
}

const Complex& QueueLst::Top() const & {
    if (IsEmpty()) {
        throw std::logic_error("QueueLst - try get top from empty queue");
    }
    return head_->val;
}

void QueueLst::Clear() noexcept {
    while (!IsEmpty()) {
        Pop();
    }
}