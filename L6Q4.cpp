/*
Write a C++ menu-driven program to get a string of '(' and ')' parenthesis from the user and
check whether they are balanced. IdenƟfy the opƟmal ADT and data structure to solve the
menƟoned problem. You can consider all previous header files for the
soluƟon's implementaƟon. Maintain proper boundary condiƟons and follow good coding
pracƟces. The program has the following operaƟons,

1. Check Balance
2. Exit

The Check Balance operaƟons get a string of open and closed parentheses. AddiƟonally, it
displays whether the parenthesis is balanced or not. 
*/
#include <iostream>
#include <string>
#include "Stack.h" // Include your custom stack header file
using namespace std;

// Function to check if parentheses are balanced using the custom stack
bool isBalancedStack(const string& str) {
    stack s; // Create an instance of the custom stack

    // Traverse the input string
    for (char ch : str) {
        if (ch == '(') {
            // Push '(' onto the stack
            s.push(ch);
        } else if (ch == ')') {
            // If stack is empty or top element is not '(', parentheses are not balanced
            if (s.isEmpty() || s.peek() != '(') {
                return false;
            }
            // Pop the top element from the stack
            s.pop();
        }
    }

    // If the stack is empty, parentheses are balanced
    return s.isEmpty();
}

int main() {
    int choice;
    string input;

    while (true) {
        // Display menu
        cout << "Menu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Create a new scope for case 1
                cout << "Enter a string of parentheses: ";
                cin >> input;

                // Validate input (optional)
                bool isValid = true;
                for (char ch : input) {
                    if (ch != '(' && ch != ')') {
                        isValid = false;
                        break;
                    }
                }

                if (!isValid) {
                    cout << "Invalid input! Only '(' and ')' are allowed.\n";
                    break;
                }

                // Check balance using the stack-based approach
                if (isBalancedStack(input)) {
                    cout << "The parentheses are balanced.\n";
                } else {
                    cout << "The parentheses are not balanced.\n";
                }
                break;
            }

            case 2:
                cout << "Exiting the program.\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
