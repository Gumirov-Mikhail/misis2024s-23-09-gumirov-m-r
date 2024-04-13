#ifndef GUMIROV_M_R_23_09_MATHVECTOR_HPP
#define GUMIROV_M_R_23_09_MATHVECTOR_HPP

#include <stdexcept>

template <int capacity>
class MathVector {
public:
    MathVector();

    void push_back(const int &value);

    int at(const int &index);

    void replace_at(const int &index, const int &value);

    int getSize();

    int getFront();

    int getBack();

    bool operator==(const MathVector &other); //сравниваем равно ли количество их заполненных элементов, затем сравниваем каждый элемент
    bool operator!=(const MathVector &other); //реализация через ==

    bool empty();

    ~MathVector();
private:
    int* begin = nullptr;
    int size = 0;
};

#include <mathvector/mathvector.hpp>

template <int capacity>
MathVector<capacity>::MathVector() {
    begin = new int [capacity];
}

template <int capacity>
void MathVector<capacity>::push_back(const int &value) {
    if (size < capacity) {
        int *Newvector = new int[capacity];
        for (int i = 0; i < size; i++) {
            Newvector[i] = *(begin + i);
        }
        Newvector[size] = value;
        size++;
        delete[] begin;
        begin = Newvector;
    }
    else {
        throw std::invalid_argument("Vector is full");
    }
}

template <int capacity>
bool MathVector<capacity>::empty() {
    if (size == 0) {
        return true;
    }
    return false;
};

template <int capacity>
int MathVector<capacity>::at(const int &index) {
    if (empty()) {
        throw std::invalid_argument("Vector is empty");
    }
    if (index > size) {
        throw std::invalid_argument("Obrashchenie k pustomy elementy");
    }
    return *(begin + index);
}

template <int capacity>
void MathVector<capacity>::replace_at(const int &index, const int &value) {
    if (empty()) {
        throw std::invalid_argument("Vector is empty");
    }
    else {
        int *Newvector = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            if (i == index) {
                Newvector[i] = value;
            }
            else {
                Newvector[i] = *(begin + i);
            }
        }
        delete[] begin;
        begin = Newvector;
    }
}

template <int capacity>
int MathVector<capacity>::getSize(){
    return size;
}

template <int capacity>
int MathVector<capacity>::getFront() {
    if (empty()) {
        throw std::invalid_argument("Vector is empty");
    }
    else {
        return *(begin);
    }
}

template <int capacity>
int MathVector<capacity>::getBack() {
    if (empty()) {
        throw std::invalid_argument("Vector is empty");
    }
    else {
        return *(begin+size-1);
    }
}

template <int capacity>
bool MathVector<capacity>::operator==(const MathVector &other) {
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
bool MathVector<capacity>::operator!=(const MathVector &other) {
    return !(operator==(other));
}

template <int capacity>
MathVector<capacity>::~MathVector() {
    delete [] begin;
    begin = nullptr;
}
#endif
