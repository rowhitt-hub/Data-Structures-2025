/*
Write a C++ menu-driven program to determine whether a number is a Palindrome, Armstrong, or Perfect
Number. Normal variable and array declarations are not allowed. Utilize dynamic memory allocation (DMA). Design
proper functions, maintain boundary conditions, and follow coding best practices.
The menu is as follows,
a. Palindrome
b. Armstrong Number
c. Perfect Number
d. Exit
*/
#include <iostream>
#include <cmath>
using namespace std;

// Function to check if number is a Palindrome
bool isPalindrome(int* num) {
    int original = *num;
    int reversed = 0;

    while (*num > 0) {
        int digit = *num % 10;
        reversed = reversed * 10 + digit;
        *num = *num / 10;
    }

    *num = original; // Restore original value
    return original == reversed;
}

// Function to check if number is an Armstrong number
bool isArmstrong(int* num) {
    int original = *num;
    int sum = 0;
    int digits = 0;

    int temp = *num;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    temp = *num;
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    return sum == original;
}

// Function to check if number is a Perfect number
bool isPerfect(int* num) {
    int sum = 0;
    for (int i = 1; i <= *num / 2; ++i) {
        if (*num % i == 0)
            sum += i;
    }
    return sum == *num;
}

// Read input using DMA
int* readNumber() {
    int* num = new int;
    cout << "Enter a positive integer: ";
    cin >> *num;

    while (*num <= 0) {
        cout << "Invalid input. Enter a positive integer: ";
        cin >> *num;
    }

    return num;
}

int main() {
    char choice;

    do {
        cout << "\nMenu:\n";
        cout << "a. Palindrome\n";
        cout << "b. Armstrong Number\n";
        cout << "c. Perfect Number\n";
        cout << "d. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        choice = tolower(choice);

        if (choice == 'a' || choice == 'b' || choice == 'c') {
            int* number = readNumber();

            switch (choice) {
                case 'a':
                    if (isPalindrome(number))
                        cout << *number << " is a Palindrome.\n";
                    else
                        cout << *number << " is not a Palindrome.\n";
                    break;

                case 'b':
                    if (isArmstrong(number))
                        cout << *number << " is an Armstrong Number.\n";
                    else
                        cout << *number << " is not an Armstrong Number.\n";
                    break;

                case 'c':
                    if (isPerfect(number))
                        cout << *number << " is a Perfect Number.\n";
                    else
                        cout << *number << " is not a Perfect Number.\n";
                    break;
            }

            delete number; // Free dynamically allocated memory
        } else if (choice != 'd') {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 'd');

    cout << "Program exited successfully.\n";
    return 0;
}
