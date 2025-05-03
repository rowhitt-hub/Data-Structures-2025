/*
) Convert the sorting program into a header file and include it into a new cpp file. Write a C++ menu- driven
program for linear and binary search in this new cpp file. Utilize any of the sorting functions in the included header
file to sort the input array before performing a binary search. Design proper functions, maintain boundary conditions
and follow coding best practices. The menu-driven program supports,
a. Linear Search
b. Binary Search
c. Exit
*/
#include <iostream>
#include "sorting.h"
using namespace std;

// Linear Search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; ++i)
        if (arr[i] == key)
            return i;
    return -1;
}

// Binary Search
int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Function to read array
int readArray(int arr[]) {
    int n;
    cout << "Enter number of elements (1 to " << MAX_SIZE << "): ";
    cin >> n;
    while (n <= 0 || n > MAX_SIZE) {
        cout << "Invalid size. Try again: ";
        cin >> n;
    }

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    return n;
}

int main() {
    int arr[MAX_SIZE], size;
    char choice;

    do {
        cout << "\nMenu:\n";
        cout << "a. Linear Search\n";
        cout << "b. Binary Search\n";
        cout << "c. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        choice = tolower(choice);

        if (choice == 'a' || choice == 'b') {
            size = readArray(arr);
            int key;
            cout << "Enter key to search: ";
            cin >> key;

            if (choice == 'a') {
                int index = linearSearch(arr, size, key);
                if (index != -1)
                    cout << "Element found at index " << index << ".\n";
                else
                    cout << "Element not found.\n";
            } else {
                insertionSort(arr, size);
                cout << "Array sorted for Binary Search: ";
                displayArray(arr, size);

                int index = binarySearch(arr, size, key);
                if (index != -1)
                    cout << "Element found at index " << index << ".\n";
                else
                    cout << "Element not found.\n";
            }
        } else if (choice != 'c') {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 'c');

    cout << "Program exited.\n";
    return 0;
}
