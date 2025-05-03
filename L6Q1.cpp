/*
Write a separate C++ menu-driven program to implement stack ADT using a character
array of size 5. Maintain proper boundary condiƟons and follow good coding pracƟces. Stack
ADT has the following operaƟons,

1. Push
2. Pop
3. Peek
4. Exit 
*/
#include <iostream>
using namespace std;

class stack {
private:
    char arr[5];
    int top;
public:
    stack();
    void push(char letter);
    char peek();
    char pop();

};

stack::stack() {
    top=-1;
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
    if (top==4) {
    cout<<"Stack overflow"<<endl;
    return;
    }
    top=top+1;
    arr[top]=letter;
}

char stack::peek() {
    if (top==-1) {
        cout <<"Stack is empty"<<endl;
        return '-';
    }
    return arr[top];

}

char stack::pop() {
    if (top==-1) {
        cout <<"Stack is empty" <<endl;
        return '-';
    }
    char val=arr[top];
    top=top-1;
    return val;

}

