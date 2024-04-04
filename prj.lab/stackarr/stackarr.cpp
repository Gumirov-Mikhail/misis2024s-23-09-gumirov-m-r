#include <stackarr/stackarr.hpp>

StackArr::StackArr(StackArr&& src) noexcept {

};

StackArr::~StackArr() {
    size_ = 0;
    i_top_ = -1;
    delete[] ;
    data_ = nullptr;
};

StackArr& operator=(const StackArr& src);

StackArr& operator=(StackArr&& src) noexcept;

[[nodiscard]] bool IsEmpty() const noexcept;

void Pop() noexcept;

void Push(const Complex& val);

[[nodiscard]] Complex& Top() &;

[[nodiscard]] const Complex& Top() const &;

void Clear() noexcept;
