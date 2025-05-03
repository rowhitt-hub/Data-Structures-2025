/*
1. Write a C++ menu-driven program to sort a given array in ascending order. Design proper functions,
maintain boundary conditions and follow coding best practices. The menus are as follows,
a. Bubble Sort
b. Selection Sort
c. Insertion Sort
d. Exit
*/

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// Function to display the array
void displayArray(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Selection Sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Insertion Sort
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Function to read array from user
int readArray(int arr[]) {
    int n;
    cout << "Enter number of elements (1 to 100): ";
    cin >> n;

    while (n <= 0 || n > MAX_SIZE) {
        cout << "Invalid size. Enter between 1 and 100: ";
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
    char choice;
    int arr[MAX_SIZE];
    int size;

    do {
        cout << "\nMenu:\n";
        cout << "a. Bubble Sort\n";
        cout << "b. Selection Sort\n";
        cout << "c. Insertion Sort\n";
        cout << "d. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        choice = tolower(choice);

        if (choice == 'a' || choice == 'b' || choice == 'c') {
            size = readArray(arr);

            switch (choice) {
                case 'a':
                    bubbleSort(arr, size);
                    cout << "Array sorted using Bubble Sort.\n";
                    break;
                case 'b':
                    selectionSort(arr, size);
                    cout << "Array sorted using Selection Sort.\n";
                    break;
                case 'c':
                    insertionSort(arr, size);
                    cout << "Array sorted using Insertion Sort.\n";
                    break;
            }

            displayArray(arr, size);
        } else if (choice != 'd') {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 'd');

    cout << "Program exited successfully.\n";
    return 0;
}
