/*
Add a "construct expression tree" method to the binary tree data structure from the previous lab code—import stack
from the standard template library (STL) to construct the expression tree. Import the Tree ADT program into another program that gets a valid postfix expression, constructs, and prints the expression tree. It consists of the following operations. 
 
1. Postfix Expression 
2. Construct Expression Tree 
3. Preorder 
4. Inorder 
5. Postorder 
6. Exit 

  */

//Program to show construction and traversal in an expression tree

#include <iostream>
#include <stack>
using namespace std;

class Tree {
private:
    struct Node {
        char data;
        Node *left, *right;
    };
    Node *root;

    void preorderTraversal(Node* node);
    void inorderTraversal(Node* node);
    void postorderTraversal(Node* node);

public:
    Tree();
    void constructExpressionTree(string postfix);
    void preorder();
    void inorder();
    void postorder();
};

Tree::Tree() {
    root = nullptr;
}

// Construct expression tree from postfix expression
void Tree::constructExpressionTree(string postfix) {
    stack<Node*> st;
    for (char ch : postfix) {
        Node* newNode = new Node{ch, nullptr, nullptr};
        if (isalnum(ch)) {
            st.push(newNode);
        } else {
            Node* right = st.top(); st.pop();
            Node* left = st.top(); st.pop();
            newNode->left = left;
            newNode->right = right;
            st.push(newNode);
        }
    }
    root = st.top();
}

// Preorder Traversal
void Tree::preorderTraversal(Node* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// Inorder Traversal
void Tree::inorderTraversal(Node* node) {
    if (node == nullptr) return;
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

// Postorder Traversal
void Tree::postorderTraversal(Node* node) {
    if (node == nullptr) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";
}

void Tree::preorder() {
    preorderTraversal(root);
    cout << endl;
}

void Tree::inorder() {
    inorderTraversal(root);
    cout << endl;
}

void Tree::postorder() {
    postorderTraversal(root);
    cout << endl;
}

int main() {
    Tree t;
    int ch;
    string postfix;
    
    while (true) {
        cout << "\n1. Enter Postfix Expression\n2. Construct Expression Tree\n3. Preorder Traversal\n4. Inorder Traversal\n5. Postorder Traversal\n6. Exit\nEnter your choice: ";
        cin >> ch;
        
        switch (ch) {
            case 1:
                cout << "Enter postfix expression: ";
                cin >> postfix;
                break;
            case 2:
                t.constructExpressionTree(postfix);
                cout << "Expression tree constructed.\n";
                break;
            case 3:
                cout << "Preorder Traversal: ";
                t.preorder();
                break;
            case 4:
                cout << "Inorder Traversal: ";
                t.inorder();
                break;
            case 5:
                cout << "Postorder Traversal: ";
                t.postorder();
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
 
