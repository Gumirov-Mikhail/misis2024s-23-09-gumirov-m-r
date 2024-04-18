#pragma once
#ifndef DYNARR_DYNARR_HPP_202404
#define DYNARR_DYNARR_HPP_202404

#include <cstddef>
#include <memory>

class DynArr {
public:
    DynArr() = default;

    DynArr(const DynArr& src);

    DynArr(DynArr&& src) noexcept;

    //! \param size - начальный размер, 0 < size
    DynArr(const std::ptrdiff_t size);

    ~DynArr() = default;

    DynArr& operator=(const DynArr& src);

    DynArr& operator=(DynArr&& src) noexcept;

    [[nodiscard]] std::ptrdiff_t Size() const noexcept { return size_; }

    //! \param size - новый размер, 0 < size
    void Resize(const std::ptrdiff_t size);

    [[nodiscard]] float& operator[](const std::ptrdiff_t idx);

    [[nodiscard]] const float& operator[](const std::ptrdiff_t idx) const;

private:
    std::ptrdiff_t capacity_ = 0;         //!< размер буфера
    std::ptrdiff_t size_ = 0;             //!< число элементов в массиве
    std::unique_ptr<float[]> data_ = nullptr;   //!< буфер
};

#endif