#pragma once
#ifndef MATHVECTOR_MATHVECTOR_HPP_202404
#define MATHVECTOR_MATHVECTOR_HPP_202404

#include <algorithm>
#include <stdexcept>
#include <cstddef>
#include <initializer_list>

template <int capacity>
class MathVector {
public:
    MathVector();
    MathVector(const MathVector &rhs);
    MathVector(MathVector &&rhs) noexcept;
    MathVector(const std::initializer_list<int> &list);
    ~MathVector();

    void push_back(const int &value);
    [[nodiscard]] int at(const int &index) const;
    void replace_at(const int &index, const int &value);
    void swap(MathVector &rhs);

    [[nodiscard]] int getSize() const noexcept;
    [[nodiscard]] int getFront() const;
    [[nodiscard]] int getBack() const;
    [[nodiscard]] bool empty() const noexcept;
    void Clear() noexcept;

    MathVector& operator=(const MathVector &rhs);
    MathVector& operator=(MathVector &&rhs) noexcept;

    bool operator==(const MathVector &other) noexcept; //сравниваем равно ли количество их заполненных элементов, затем сравниваем каждый элемент
    bool operator!=(const MathVector &other) noexcept; //реализация через ==

private:
    int* begin = nullptr; //указатель на первый элемент массива
    int size = 0; //кол-во заполненных элементов
};

template <int capacity>
MathVector<capacity>::MathVector() {
    begin = new int [capacity];
}

template<int capacity>
MathVector<capacity>::MathVector(const MathVector &rhs) {
    if (!rhs.empty()) {
        size = rhs.size;
        begin = new int [capacity];
        std::copy(rhs.begin, rhs.begin + size, begin);
    }
    else {
        begin = nullptr;
    }
}

template<int capacity>
MathVector<capacity>::MathVector(MathVector &&rhs) noexcept {
    this->swap(rhs);
}

template<int capacity>
MathVector<capacity>::MathVector(const std::initializer_list<int> &list) { //исправить и убрать ошибку
    size = list.size();
    begin = new int [capacity];
    if (size > capacity) {
        throw std::logic_error("MathVector - try initializer for full vector.");
    }
    else {
        std::copy(list.begin(), list.end(), begin);
    }
}

template <int capacity>
MathVector<capacity>::~MathVector() {
    size = 0;
    delete [] begin;
    begin = nullptr;
}

template <int capacity>
void MathVector<capacity>::push_back(const int &value) {
    if (size < capacity) {
        int* temp = new int[capacity];
        for (int i = 0; i < size; i++) {
            temp[i] = begin[i];
        }
        temp[size] = value;
        size++;
        delete[] begin;
        begin = temp;
    }
    else {
        throw std::logic_error("MathVector - try push for full vector.");
    }
}

template <int capacity>
int MathVector<capacity>::at(const int &index) const {
    if (empty()) {
        throw std::logic_error("MathVector - try get at from empty vector.");
    }
    if (index >= size) {
        throw std::logic_error("MathVector - try get at from outside the vector.");
    }
    return begin[index];
}

template <int capacity>
void MathVector<capacity>::replace_at(const int &index, const int &value) {
    if (empty()) {
        throw std::logic_error("MathVector - try replace_at from empty vector.");
    }
    else if (index >= size) {
        throw std::logic_error("MathVector - try replace_at from outside the vector.");
    }
    else {
        int *temp = new int[capacity];
        for (int i = 0; i < size; i++) {
            if (i == index) {
                temp[i] = value;
            }
            else {
                temp[i] = begin[i];
            }
        }
        delete[] begin;
        begin = temp;
    }
}


template<int capacity>
void MathVector<capacity>::swap(MathVector &rhs) {
    std::swap(size, rhs.size);
    std::swap(begin, rhs.begin);
}

template <int capacity>
int MathVector<capacity>::getSize() const noexcept {
    return size;
}

template <int capacity>
int MathVector<capacity>::getFront() const {
    if (empty()) {
        throw std::logic_error("MathVector - try get at from empty vector.");
    }
    else {
        return *begin;
    }
}

template <int capacity>
int MathVector<capacity>::getBack() const {
    if (empty()) {
        throw std::logic_error("MathVector - try get at from empty vector.");
    }
    else {
        return begin[size-1];
    }
}

template <int capacity>
bool MathVector<capacity>::empty() const noexcept {
    if (size == 0) {
        return true;
    }
    return false;
};

template<int capacity>
void MathVector<capacity>::Clear() noexcept {
    size = 0;
    delete [] begin;
    begin = new int [capacity];
}

template<int capacity>
MathVector<capacity>& MathVector<capacity>::operator=(const MathVector &rhs) {
    if (this != &rhs) {
        size = rhs.size;
        delete [] begin;
        if (!rhs.empty()) {
            begin = new int [capacity];
            std::copy(rhs.begin, rhs.begin + size, begin);
        }
        else {
            begin = nullptr;
        }
    }
    return *this;
}

template<int capacity>
MathVector<capacity>& MathVector<capacity>::operator=(MathVector &&rhs) noexcept {
    this->swap( rhs);
    return *this;
}

template <int capacity>
bool MathVector<capacity>::operator==(const MathVector &other) noexcept {
    if (size == other.size) {
        for (int i = 0; i < size; i++) {
            if (begin[i] != other.begin[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

template <int capacity>
bool MathVector<capacity>::operator!=(const MathVector &other) noexcept {
    return !(operator==(other));
}

#endif
