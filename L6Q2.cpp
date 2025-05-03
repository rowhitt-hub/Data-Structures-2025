/*
Write a separate C++ menu-driven program to implement stack ADT using a character singly
linked list. Maintain proper boundary condiƟons and follow good coding pracƟces. Stack ADT
has the following operaƟons,

1. Push
2. Pop
3. Peek
4. Exit
  */
#include <iostream>
using namespace std;

class stack {

private: 
    struct node {
        char data;
        node *next;
    };
    node *head;
public: 
    stack();
    void push(char letter);
    char peek();
    char pop();
};

stack::stack() {
    head=nullptr;
}

int main() {
    int ch;
    stack s1;
    while (1) {
        cout <<"Enter your choice: ";
        cin>>ch;
        switch(ch) {
            case 1:
                char letter;
                cout <<"Enter a character: ";
                cin>>letter;
                s1.push(letter);
                break;
            case 2: {
                char del=s1.pop();
                cout <<"Deleted element: "<<del<<endl;
                break; }
            case 3: {
                char z=s1.peek();
                cout <<"First of the stack: " <<z<<endl;
                break; }
            case 4:
                cout << "Exiting..."<<endl;
                return 0;
            default:
                cout <<"Invalid input"<<endl;
                break;
        }
    }
}

void stack::push(char letter) {
    node *newnode=new node;
    newnode->data=letter;
    newnode->next=head;
    head=newnode;
}

char stack::peek() {
    if (head==nullptr) {
        cout <<"Stack underflow"<<endl;
        return '-';
    }
    return head->data;
}

char stack::pop() {
    if (head==nullptr) {
        cout <<"Stack underflow"<<endl;
        return '-';
    }
    char val=head->data;
    node *temp=head;
    head=head->next;
    delete temp;
    return val;
}
