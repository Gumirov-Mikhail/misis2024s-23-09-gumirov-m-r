#include <binarysearchtree/binarysearchtree.hpp>

#include <stdexcept>

BinarySearchTree::BinarySearchTree() {
    root_ = nullptr;
}

void BinarySearchTree::clear(TreeNode* val) {
    if (val != nullptr) {
        if (val->left != nullptr) {
            clear(val->left);
        }
        if (val->right != nullptr) {
            clear(val->right);
        }
        if (val->left == nullptr && val->right == nullptr) {
            delete val;
            val = nullptr;
        }
    }
}

BinarySearchTree::~BinarySearchTree() {
    clear(root_);
}

TreeNode* BinarySearchTree::root() {
    return root_;
}

void BinarySearchTree::add(int data) {
    if (root_ != nullptr) {
        TreeNode* temp = root_;
        while (temp->right != nullptr || temp->left != nullptr) {
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
                throw std::logic_error("BinarySearchTree - try add an existing element");
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
        while (temp->left != nullptr || temp->right != nullptr) {
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
        while (temp->left != nullptr || temp->right != nullptr) {
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
                return temp;
            }
        }
        if (data == temp->data) {
            return temp;
        }
    }
    throw std::logic_error("BinarySearchTree - try find an not existing element");
}

void BinarySearchTree::remove(int data) {
    if (root_ != nullptr) {
        TreeNode* temp = root_;
        TreeNode* p_cur = temp;
        while (temp->left != nullptr || temp->right != nullptr) {
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
        if (data == temp->data) {
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
                TreeNode* del = temp->right;
                while (del->left != nullptr) {
                    del = del->left;
                }
                TreeNode* dop = del;
                while (dop->right != nullptr) {
                    dop = dop->right;
                }
                if (p_cur->left == temp) {
                    p_cur->left = del;
                }
                else {
                    p_cur->right = del;
                }
                del->left = temp->left;
                dop->right = temp->right;
            }
            delete temp;
            temp = nullptr;
        }
    }
    //throw or nothing
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