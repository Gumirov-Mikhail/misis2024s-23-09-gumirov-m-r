#ifndef CUSTOMCONTAINER_HPP
#define CUSTOMCONTAINER_HPP

#include <cstddef>
#include <stdexcept>

class IContainerBase {
public:
    virtual void add(const int& value) = 0;

    virtual void remove(int& value) = 0;

    virtual bool contains(const int& value) = 0;

    virtual ~IContainerBase() = default;
};

class CustomContainer : public IContainerBase {
private:
    struct Node {
        int* data; //— массив
        size_t size; //— Текущий размер массива
        Node* next; //— Указатель на следующий узел
        Node* prev; //— Указатель на предыдущий узел
    };

    Node* head; //— Указатель на первый узел списка.
    Node* tail; //— Указатель на последний узел списка.
    size_t nodeCapacity; //— Вместимость массива в каждой ноде.```

public:
    CustomContainer();
    CustomContainer(const int& capacity);
    ~CustomContainer() override;

    void add(const int& value) override;

    void remove(int& value) override;

    bool contains(const int& value) override;

    bool operator==(const CustomContainer& rhs); //сравниваем каждый элемент с каждым, если один дошел до конца, а другой нет, то выкинем false
    bool operator!=(const CustomContainer& rhs); //реализация через ==
};

#endif
