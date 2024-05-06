#include <binarysearchtree/binarysearchtree.hpp>

#include <stack>
#include <stdexcept>

BinarySearchTree::BinarySearchTree() {
    root_ = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
    std::stack<TreeNode*> st;
    TreeNode* current = root_;
    TreeNode* lastVisited = nullptr;

    while (current != nullptr || !st.empty()) {
        if (current != nullptr) {
            st.push(current);
            current = current->left;
        }
        else {
            TreeNode *topNode = st.top();

            if (topNode->right && topNode->right != lastVisited) {
                current = topNode->right;
            }
            else {
                lastVisited = topNode;
                st.pop();
                delete topNode;
            }
        }
    }
}

TreeNode* BinarySearchTree::root() {
    if (root_ == nullptr) {
        throw std::logic_error("BinarySearchTree - try get root from empty tree");
    }
    return root_;
}

void BinarySearchTree::add(int data) {
    if (root_ != nullptr) {
        TreeNode* temp = root_;
        while (temp != nullptr || data != temp->data) {
            if (data < temp->data) {
                if (temp->left == nullptr) {
                    break;
                }
                temp = temp->left;
            }
            else if (data > temp->data) {
                if (temp->right == nullptr) {
                    break;
                }
                temp = temp->right;
            }
            else {
                break;
            }
        }
        if (data < temp->data) {
            TreeNode* p_cur = new TreeNode (data);
            temp->left = p_cur;
        }
        else if (data > temp->data) {
            TreeNode* p_cur = new TreeNode (data);
            temp->right = p_cur;
        }
        else {
            throw std::logic_error("BinarySearchTree - try add an existing element");
        }
    }
    else {
        root_ = new TreeNode (data);
    }
}

bool BinarySearchTree::has(int data) {
    if (root_ != nullptr) {
        TreeNode* temp = root_;
        while (temp != nullptr || data != temp->data) {
            if (data < temp->data) {
                if (temp->left == nullptr) {
                    break;
                }
                temp = temp->left;
            }
            else if (data > temp->data) {
                if (temp->right == nullptr) {
                    break;
                }
                temp = temp->right;
            }
            else {
                break;
            }
        }
        if (data == temp->data) {
            return true;
        }
    }
    return false;
}

TreeNode* BinarySearchTree::find(int data) {
    if (root_ != nullptr) {
        TreeNode* temp = root_;
        while (temp != nullptr || data != temp->data) {
            if (data < temp->data) {
                if (temp->left == nullptr) {
                    break;
                }
                else {
                    temp = temp->left;
                }
            }
            else if (data > temp->data) {
                if (temp->right == nullptr) {
                    break;
                }
                else {
                    temp = temp->right;
                }
            }
            else {
                break;
            }
        }
        if (data == temp->data) {
            return temp;
        }
        else {
            throw std::logic_error("BinarySearchTree - try find an not existing element");
        }
    }
    else {
        throw std::logic_error("BinarySearchTree - try find an not existing element");
    }
}


int BinarySearchTree::min() {
    if (root_ == nullptr) {
        throw std::logic_error("BinarySearchTree - try get min from empty tree");
    }
    else {
        TreeNode* temp = root_;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        return temp->data;
    }
}

int BinarySearchTree::max() {
    if (root_ == nullptr) {
        throw std::logic_error("BinarySearchTree - try get max from empty tree");
    }
    else {
        TreeNode* temp = root_;
        while (temp->right != nullptr) {
            temp = temp->right;
        }
        return temp->data;
    }
}

void BinarySearchTree::remove(int data) {
    if (root_ != nullptr) {
        TreeNode* temp = root_;
        TreeNode* p_cur = temp;
        while (temp != nullptr || data != temp->data) { // find existing element for remove
            if (data < temp->data) {
                if (temp->left == nullptr) {
                    break;
                }
                p_cur = temp;
                temp = temp->left;
            }
            else if (data > temp->data) {
                if (temp->right == nullptr) {
                    break;
                }
                p_cur = temp;
                temp = temp->right;
            }
            else {
                break;
            }
        }
        if (data == temp->data) { // if find existing element
            if (root_ == temp) { // if existing element is root_ (расписываем все 4 случая)
                if (temp->left == nullptr && temp->right == nullptr) {
                    root_ = nullptr;
                }
                else if (temp->left == nullptr) {
                    root_ = temp->right;
                }
                else if (temp->right == nullptr) {
                    root_ = temp->left;
                }
                else {
                    TreeNode* rhs = temp->right;
                    while (rhs->left != nullptr) {
                        rhs = rhs->left;
                    }
                    TreeNode* dop = rhs;
                    while (dop->right != nullptr) {
                        dop = dop->right;
                    }
                    if (rhs != temp->right) {
                        dop->right = temp->right;
                    }
                    root_ = rhs;
                }
                delete temp;
            }
            else { // if existing element isn't root_ (расписываем все 4 случая)
                if (temp->left == nullptr && temp->right == nullptr) {
                    if (p_cur->left == temp) {
                        p_cur->left = nullptr;
                    }
                    else {
                        p_cur->right = nullptr;
                    }
                }
                else if (temp->left == nullptr) {
                    if (p_cur->left == temp) {
                        p_cur->left = temp->right;
                    }
                    else {
                        p_cur->right = temp->right;
                    }
                }
                else if (temp->right == nullptr) {
                    if (p_cur->left == temp) {
                        p_cur->left = temp->left;
                    }
                    else {
                        p_cur->right = temp->left;
                    }
                }
                else {
                    TreeNode* rhs = temp->right;
                    TreeNode* trash = temp;
                    while (rhs->left != nullptr) {
                        trash = rhs;
                        rhs = rhs->left;
                    }
                    TreeNode* dop = rhs;
                    while (dop->right != nullptr) {
                        dop = dop->right;
                    }
                    if (p_cur->left == temp) {
                        p_cur->left = rhs;
                        rhs->left = temp->left;
                        if (rhs != temp->right) {
                            dop->right = temp->right;
                        }
                        trash->left = nullptr;
                    }
                    else {
                        p_cur->right = rhs;
                        rhs->left = temp->left;
                        if (rhs != temp->right) {
                            dop->right = temp->right;
                        }
                        trash->left = nullptr;
                    }
                }
                delete temp;
            }
        }
        else {
            throw std::logic_error("BinarySearchTree - try remove an not existing element");
        }
    }
    else {
        throw std::logic_error("BinarySearchTree - try remove from empty tree");
    }
}