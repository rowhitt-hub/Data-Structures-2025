/*
Write a separate C++ menu-driven program to implement Tree ADT using a binary search tree. Maintain proper boundary 
conditions and follow good coding practices. The Tree ADT has the following operations, 
 
1. Insert 
2. Preorder 
3. Inorder 
4. Postorder 
5. Search 
6. Exit 
*/
#include <iostream>
using namespace std;

// This program implements a Binary Search Tree (BST) with menu-driven operations.

class Tree {
private:
    struct Node {
        int data;
        Node *left, *right;
    };
    Node *root;

public:
    Tree(); // Constructor to initialize the tree.
    void insert(int value); // Inserts a value into the BST.
    bool search(int value); // Searches for a value in the BST.
    void preorder(Node *node); // Performs preorder traversal.
    void inorder(Node *node); // Performs inorder traversal.
    void postorder(Node *node); // Performs postorder traversal.
    void preorder(); // Wrapper function for preorder traversal.
    void inorder(); // Wrapper function for inorder traversal.
    void postorder(); // Wrapper function for postorder traversal.
};

Tree::Tree() {
    root = nullptr;
}

void Tree::insert(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (root == nullptr) {
        root = newNode;
        return;
    }

    Node *temp = root;
    while (true) {
        if (value < temp->data) {
            if (temp->left == nullptr) {
                temp->left = newNode;
                break;
            }
            temp = temp->left;
        } else {
            if (temp->right == nullptr) {
                temp->right = newNode;
                break;
            }
            temp = temp->right;
        }
    }
}

bool Tree::search(int value) {
    Node *temp = root;
    while (temp != nullptr) {
        if (temp->data == value) return true;
        temp = (value < temp->data) ? temp->left : temp->right;
    }
    return false;
}

void Tree::preorder(Node *node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void Tree::inorder(Node *node) {
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void Tree::postorder(Node *node) {
    if (node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

void Tree::preorder() { preorder(root); }
void Tree::inorder() { inorder(root); }
void Tree::postorder() { postorder(root); }

int main() {
    Tree tree;
    int ch, value;
    while (true) {
        cout << "Enter your choice\n";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "Preorder: ";
                tree.preorder();
                cout << endl;
                break;
            case 3:
                cout << "Inorder: ";
                tree.inorder();
                cout << endl;
                break;
            case 4:
                cout << "Postorder: ";
                tree.postorder();
                cout << endl;
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                if (tree.search(value))
                    cout << "Value found in tree\n";
                else
                    cout << "Value not found\n";
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid input.. try again!\n";
        }
    }
}
