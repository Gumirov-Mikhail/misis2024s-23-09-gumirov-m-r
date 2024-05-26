#pragma once
#ifndef HASHTABLE_HASHTABLE_HPP_202405
#define HASHTABLE_HASHTABLE_HPP_202405

#include <vector>
#include <cstddef>
#include <stdexcept>

template<typename KeyType, typename ValueType>
class hashTable {
private:
    struct Node {
        KeyType key;
        ValueType value;
        Node* next;

        Node(const KeyType &k, const ValueType &v) : key(k), value(v), next(nullptr) {}
    };

    std::vector<Node*> table;
    std::hash<KeyType> hash_function;
    size_t size_;

public:
    hashTable();
    explicit hashTable(size_t size);
    ~hashTable();

    void insert(const KeyType &key, const ValueType &value);

    bool contains(const KeyType &key) const;

    ValueType &operator[](const KeyType &key);

    class Iterator {
    private:
        size_t index;
        Node* current;
        const std::vector<Node*>& table;

    public:
        Iterator(size_t i, Node *node, const std::vector<Node*> &tbl)
            : index(i), current(node), table(tbl) {}

        Iterator &operator++() {
            if (current == nullptr || current->next == nullptr) {
                index++;
                current = table[index];
                while (current == nullptr && index < table.size()) {
                    index++;
                    current = table[index];
                }
            }
            else {
                current = current->next;
            }
            return *this;
        }

        bool operator!=(const Iterator &other) const {
            if (index != other.index || current != other.current) {
                return true;
            }
            return false;
        }

        std::pair<const KeyType &, ValueType &> operator*() const {
            if (current != nullptr) {
                return std::pair<const KeyType &, ValueType &>(current->key, current->value);
            }
            return std::pair<const KeyType &, ValueType &>(current->key, current->value);
        }

    };

    Iterator begin() const {
        if (table[0] != nullptr) {
            return Iterator(0, table[0], table);
        }
        return ++Iterator(0, table[0], table);
    }

    Iterator end() const {
        return Iterator(table.size(), nullptr, table);
    }
};

template<typename KeyType, typename ValueType>
hashTable<KeyType, ValueType>::hashTable() {
    size_ = 10;
    table = std::vector<Node*> (size_);
}

template<typename KeyType, typename ValueType>
hashTable<KeyType, ValueType>::hashTable(size_t size) : size_(size) {
    table = std::vector<Node*> (size_);
}

template<typename KeyType, typename ValueType>
hashTable<KeyType, ValueType>::~hashTable() {
    for (Node* node : table) {
        Node* current = node;
        Node* temp = nullptr;
        while (current != nullptr) {
            temp = current;
            current = current->next;
            delete temp;
        }
    }
}

template<typename KeyType, typename ValueType>
void hashTable<KeyType, ValueType>::insert(const KeyType &key, const ValueType &value) {
    size_t hash = hash_function(key) % size_;
    if (table[hash] == nullptr) {
        table[hash] = new Node(key, value);
    }
    else {
        Node* current = table[hash];
        while (current->next != nullptr && current->key != key) {
            current = current->next;
        }
        if (current->key == key) {
            throw std::logic_error("HashTable - try insert an existing key");
        }
        current->next = new Node(key, value);
    }
}

template<typename KeyType, typename ValueType>
bool hashTable<KeyType, ValueType>::contains(const KeyType &key) const {
    size_t hash = hash_function(key) % size_;
    if (table[hash] == nullptr) {
        return false;
    }
    Node* current = table[hash];
    while (current->next != nullptr && current->key != key) {
        current = current->next;
    }
    if (current->key == key) {
        return true;
    }
    return false;
}

template<typename KeyType, typename ValueType>
ValueType &hashTable<KeyType, ValueType>::operator[](const KeyType &key) {
    size_t hash = hash_function(key) % size_;
    Node*& current = table[hash];
    while (current != nullptr && current->key != key) {
        current = current->next;
    }
    if (current == nullptr) {
        current = new Node(key, ValueType());
    }
    return current->value;
}

#endif