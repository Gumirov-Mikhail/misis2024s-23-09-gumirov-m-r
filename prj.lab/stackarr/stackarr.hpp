#pragma once
#ifndef STACKARR_STACKARR_HPP_202404
#define STACKARR_STACKARR_HPP_202404

#include <complex/complex.hpp>

#include <cstddef>

class StackArr final {
public:
    StackArr() = default;

    StackArr(const StackArr& src) : size_(src.size_), i_top_(src.i_top_), data_(src.data_) {};

    StackArr(StackArr&& src) noexcept;

    ~StackArr();

    StackArr& operator=(const StackArr& src);

    StackArr& operator=(StackArr&& src) noexcept;

    [[nodiscard]] bool IsEmpty() const noexcept;

    void Pop() noexcept;

    void Push(const Complex& val);

    [[nodiscard]] Complex& Top() &;

    [[nodiscard]] const Complex& Top() const &;

    void Clear() noexcept;

private:
    std::ptrdiff_t size_ = 0;   //!< число элементов в буфере
    std::ptrdiff_t i_top_ = -1; //!< индекс top элемента
    Complex* data_ = nullptr;   //!< элементы стека
};

#endif