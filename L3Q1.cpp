/*
Write a C++ menu-driven program to implement List ADT using an array of size 5. Maintain proper boundary
conditions and follow good coding practices. The List ADT has the following operations,
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Rotate
10. Exit
The rotate option takes an input 'k' which rotates the entire array to the right by k times. Think of at least 3 solutions.
Think of a solution that rotates using O(1) extra space.
*/
#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

class ListADT {
private:
    int arr[MAX_SIZE];
    int size;
    void reverse(int start, int end); // helper for rotate

public:
    ListADT();
    void insertBeginning(int value);
    void insertEnd(int value);
    void insertPosition(int value, int pos);
    void deleteBeginning();
    void deleteEnd();
    void deletePosition(int pos);
    void search(int value);
    void display();
    void rotateRight(int k);
};

// Constructor
ListADT::ListADT() {
    size = 0;
}

// Insert at beginning
void ListADT::insertBeginning(int value) {
    if (size == MAX_SIZE) {
        cout << "List is full.\n";
        return;
    }
    for (int i = size; i > 0; --i)
        arr[i] = arr[i - 1];
    arr[0] = value;
    size++;
    cout << "Inserted at beginning.\n";
}

// Insert at end
void ListADT::insertEnd(int value) {
    if (size == MAX_SIZE) {
        cout << "List is full.\n";
        return;
    }
    arr[size++] = value;
    cout << "Inserted at end.\n";
}

// Insert at position (1-based)
void ListADT::insertPosition(int value, int pos) {
    if (size == MAX_SIZE || pos < 1 || pos > size + 1) {
        cout << "Invalid position or list full.\n";
        return;
    }
    for (int i = size; i >= pos; --i)
        arr[i] = arr[i - 1];
    arr[pos - 1] = value;
    size++;
    cout << "Inserted at position " << pos << ".\n";
}

// Delete from beginning
void ListADT::deleteBeginning() {
    if (size == 0) {
        cout << "List is empty.\n";
        return;
    }
    for (int i = 0; i < size - 1; ++i)
        arr[i] = arr[i + 1];
    size--;
    cout << "Deleted from beginning.\n";
}

// Delete from end
void ListADT::deleteEnd() {
    if (size == 0) {
        cout << "List is empty.\n";
        return;
    }
    size--;
    cout << "Deleted from end.\n";
}

// Delete from position
void ListADT::deletePosition(int pos) {
    if (size == 0 || pos < 1 || pos > size) {
        cout << "Invalid position or list is empty.\n";
        return;
    }
    for (int i = pos - 1; i < size - 1; ++i)
        arr[i] = arr[i + 1];
    size--;
    cout << "Deleted from position " << pos << ".\n";
}

// Search for value
void ListADT::search(int value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            cout << "Element found at position " << i + 1 << ".\n";
            return;
        }
    }
    cout << "Element not found.\n";
}

// Display the list
void ListADT::display() {
    if (size == 0) {
        cout << "List is empty.\n";
        return;
    }
    cout << "List elements: ";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Reverse part of the array
void ListADT::reverse(int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Rotate right by k
void ListADT::rotateRight(int k) {
    if (size == 0 || k <= 0) {
        cout << "Nothing to rotate.\n";
        return;
    }
    k %= size;
    reverse(0, size - 1);
    reverse(0, k - 1);
    reverse(k, size - 1);
    cout << "Rotated right by " << k << " positions.\n";
}
