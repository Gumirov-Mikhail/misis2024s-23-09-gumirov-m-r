#include <customcontainer/customcontainer.hpp>

CustomContainer::CustomContainer() {
    head = nullptr;
    tail = nullptr;
    nodeCapacity = 3;
}

CustomContainer::CustomContainer(const int &capacity) {
    head = nullptr;
    tail = nullptr;
    nodeCapacity = capacity;
}

CustomContainer::~CustomContainer() {
    Node* temp = head;
    Node* current = nullptr;
    while (temp != nullptr) {
        current = temp;
        delete [] temp->data;
        delete temp;
        temp = current->next;
    }
}

void CustomContainer::add(const int &value) {
    if (head == nullptr) {
        head = new Node;
        head->data = new int [nodeCapacity];
        head->data[0] = value;
        head->size++;
        tail = head;
    }
    else {
        if (tail->data == nullptr) {
            tail->data = new int [head->size];
            tail->data[0] = value;
            tail->size++;
        }
        else {
            if (tail->size < nodeCapacity) {
                tail->data[tail->size] = value;
                tail->size++;
            }
            else {
                Node* temp = new Node;
                temp->data = new int [nodeCapacity];
                temp->data[0] = value;
                temp->size++;
                tail->next = temp;
                tail = temp;
            }
        }
    }
}

void CustomContainer::remove(int &value) {

}

bool CustomContainer::contains(const int &value) {
    Node* temp = head;
    while (temp != nullptr) {
        for (int i = 0; i < temp->size; i++) {
            if (temp->data[i] == value) {
                return true;
            }
        }
        temp = temp->next;
    }
    return false;
}

bool CustomContainer::operator==(const CustomContainer &rhs) {
    Node* temp = head;
    Node* temp_rhs = rhs.head;
    if (nodeCapacity == rhs.nodeCapacity) {
        while (temp != nullptr || temp_rhs != nullptr) {
            for (int i = 0; i < temp->size; i++) {
                if (temp->data[i] != temp_rhs->data[i]) {
                    return false;
                }
            }
            temp = temp->next;
            temp_rhs = temp_rhs->next;
        }
        if (temp == nullptr && temp_rhs == nullptr) {
            return true;
        }
    }
    else {
        return false;
    }
    return true;
}

bool CustomContainer::operator!=(const CustomContainer &rhs) {
    return !(operator==(rhs));
}


