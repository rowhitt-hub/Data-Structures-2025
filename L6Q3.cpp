/*
Write a C++ menu-driven program to implement infix to posƞix and posƞix evaluaƟon. Use
the singly linked list (SLL) to implement the stack ADT as a header file. Maintain proper
boundary condiƟons and follow good coding pracƟces. The program has the following
operaƟons,
 1. Get Infix 
2. Convert Infix
3. Evaluate Postfix 
4. Exit
 The Get Infix opƟon gets a valid infix expression and stores it efficiently. The Convert Infix opƟon converts the stored infix expression into a posƞix expression. It
prints the posƞix expression at the end aŌer conversion. The Evaluate Posƞix expression calculates and prints the output of the converted infix
expression
*/
#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '=') return 0;
    return -1;
}

string infixToPostfix(string infix) {
    stack s;
    string postfix = "";
    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop();
        } else {
            while (!s.isEmpty() && precedence(c) <= precedence(s.peek())) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        postfix += s.pop();
    }
    return postfix;
}

int evaluatePostfix(string postfix) {
    stack s;
    for (char c : postfix) {
        if (isalnum(c)) {
            s.push(c - '0');
        } else {
            int val1 = s.pop();
            int val2 = s.pop();
            switch (c) {
                case '+':
                    s.push(val2 + val1); 
                    break;
                case '-': 
                    s.push(val2 - val1);
                    break;
                case '*': 
                    s.push(val2 * val1); 
                    break;
                case '/': 
                    s.push(val2 / val1); 
                    break;
            }
        }
    }
    return s.pop();
}

int main() {
    string infix = "";
    string postfix = "";
    int choice;
    do {
        cout << "1. Get Infix\n2. Convert Infix\n3. Evaluate Postfix\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the infix expression: ";
                cin >> infix;
                break;
            case 2:
                postfix = infixToPostfix(infix);
                cout << "Postfix expression: " << postfix << endl;
                break;
            case 3:
                if (postfix.empty()) {
                    cout << "No postfix expression available. Convert infix first." << endl;
                } else {
                    int result = evaluatePostfix(postfix);
                    cout << "Result of postfix evaluation: " << result << endl;
                }
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
