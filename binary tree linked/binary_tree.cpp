#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* left;
    Node* right;

public:
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
    int getData() {
        return data;
    }
    void setLeft(Node* node) {
        left = node;
    }
    void setRight(Node* node) {
        right = node;
    }
    Node* getLeft() {
        return left;
    }
    Node* getRight() {
        return right;
    }
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() {
        root = nullptr;
    }
    void insertNode(int data) {
        Node* newNode = new Node(data);
        if (root == nullptr) {
            root = newNode;
        } else {
            insertNode(root, newNode);
        }
    }
    void insertNode(Node* current, Node* newNode) {
        if (newNode->getData() <= current->getData()) {
            if (current->getLeft() == nullptr) {
                current->setLeft(newNode);
            } else {
                insertNode(current->getLeft(), newNode);
            }
        } else {
            if (current->getRight() == nullptr) {
                current->setRight(newNode);
            } else {
                insertNode(current->getRight(), newNode);
            }
        }
    }
    void inorderTraversal(Node* current) {
        if (current != nullptr) {
            inorderTraversal(current->getLeft());
            cout << current->getData() << " ";
            inorderTraversal(current->getRight());
        }
    }
    void preorderTraversal(Node* current) {
        if (current != nullptr) {
            cout << current->getData() << " ";
            preorderTraversal(current->getLeft());
            preorderTraversal(current->getRight());
        }
    }
    void postorderTraversal(Node* current) {
        if (current != nullptr) {
            postorderTraversal(current->getLeft());
            postorderTraversal(current->getRight());
            cout << current->getData() << " ";
        }
    }
    void performTraversals() {
        cout << "Inorder Traversal: ";
        inorderTraversal(root);
        cout << endl;

        cout << "Preorder Traversal: ";
        preorderTraversal(root);
        cout << endl;

        cout << "Postorder Traversal: ";
        postorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;

    tree.insertNode(5);
    tree.insertNode(3);
    tree.insertNode(7);
    tree.insertNode(2);
    tree.insertNode(4);
    tree.insertNode(6);
    tree.insertNode(8);
    tree.performTraversals();

    return 0;
}