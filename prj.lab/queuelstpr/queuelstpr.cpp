#include <queuelstpr/queuelstpr.hpp>

#include <algorithm>
#include <stdexcept>

QueueLstPr::QueueLstPr(const QueueLstPr & rhs) {
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

QueueLstPr::QueueLstPr(QueueLstPr && rhs) noexcept {
    std::swap(head_, rhs.head_);
}

QueueLstPr::~QueueLstPr() {
    this->Clear();
}

QueueLstPr& QueueLstPr::operator=(const QueueLstPr &rhs) {
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

QueueLstPr& QueueLstPr::operator=(QueueLstPr &&rhs) noexcept {
    if (this != &rhs) {
        std::swap(head_, rhs.head_);
    }
    return *this;
}

bool QueueLstPr::IsEmpty() const noexcept {
    return head_ == nullptr;
}

void QueueLstPr::Pop() noexcept {
    if (!IsEmpty()) {
        Node* temp = head_;
        temp = temp->next;
        delete head_;
        head_ = temp;
    }
}

void QueueLstPr::Push(const float &val) {
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

float& QueueLstPr::Top() &{
    if (head_ == nullptr) {
        throw std::logic_error("QueueLstPr - try get top from empty priority_queue");
    }
    return head_->val;
}

const float& QueueLstPr::Top() const &{
    if (head_ == nullptr) {
        throw std::logic_error("QueueLstPr - try get top from empty priority_queue");
    }
    return head_->val;
}

void QueueLstPr::Clear() noexcept {
    while (!IsEmpty()) {
        Pop();
    }
}

