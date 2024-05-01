#pragma once
#ifndef QUEUELSTPR_QUEUELSTPR_HPP_202405
#define QUEUELSTPR_QUEUELSTPR_HPP_202405

#include <cstddef>

class QueueLstPr {
public:
    QueueLstPr() = default;

    QueueLstPr(const QueueLstPr& rhs);
    QueueLstPr(QueueLstPr&& rhs) noexcept;

    ~QueueLstPr();

    QueueLstPr& operator=(const QueueLstPr& rhs);
    QueueLstPr& operator=(QueueLstPr&& rhs) noexcept;

    [[nodiscard]] bool IsEmpty() const noexcept;

    void Pop() noexcept;

    void Push(const float& val);

    [[nodiscard]] float& Top() &;

    [[nodiscard]] const float& Top() const &;

    void Clear() noexcept;

private:
    struct Node {
        float val;
        Node* next = nullptr;
    };

    Node* head_ = nullptr;   //!<
};

#endif