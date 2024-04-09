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


#endif
