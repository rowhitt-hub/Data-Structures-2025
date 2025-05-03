/*
Write a C++ menu-driven program to implement List ADT using a doubly linked list with a
tail. Maintain proper boundary condiƟons and follow good coding pracƟces. The List ADT has the
following operaƟons,

1. Insert Beginning
2. Insert End
3. Insert PosiƟon
4. Delete Beginning
5. Delete End
6. Delete PosiƟon
7. Search
8. Display
9. Exit 
*/
#include <iostream>
using namespace std;

class ListADT {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* tail;

public:
    ListADT();
    ~ListADT();

    void insertBeginning(int value);
    void insertEnd(int value);
    void insertPosition(int value, int pos);
    void deleteBeginning();
    void deleteEnd();
    void deletePosition(int pos);
    void search(int value);
    void display();
};

// Constructor to initialize empty list
ListADT::ListADT() {
    head = nullptr;
    tail = nullptr;
}

// Destructor to delete the list and free memory
ListADT::~ListADT() {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

// Insert at the beginning
void ListADT::insertBeginning(int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (!head) { // If the list is empty
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    cout << "Inserted " << value << " at the beginning.\n";
}

// Insert at the end
void ListADT::insertEnd(int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (!tail) { // If the list is empty
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    cout << "Inserted " << value << " at the end.\n";
}

// Insert at a specific position (1-based index)
void ListADT::insertPosition(int value, int pos) {
    if (pos < 1) {
        cout << "Invalid position.\n";
        return;
    }
    Node* newNode = new Node{value, nullptr, nullptr};
    if (pos == 1) {
        insertBeginning(value);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp; ++i) {
        temp = temp->next;
    }

    if (!temp) {
        cout << "Position out of bounds.\n";
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    if (!newNode->next) {
        tail = newNode;
    }

    cout << "Inserted " << value << " at position " << pos << ".\n";
}

// Delete the first element
void ListADT::deleteBeginning() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    if (head == tail) { // Only one node in the list
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    cout << "Deleted the first element.\n";
}

// Delete the last element
void ListADT::deleteEnd() {
    if (!tail) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = tail;
    if (head == tail) { // Only one node in the list
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    cout << "Deleted the last element.\n";
}

// Delete at a specific position (1-based index)
void ListADT::deletePosition(int pos) {
    if (pos < 1 || !head) {
        cout << "Invalid position or list is empty.\n";
        return;
    }

    if (pos == 1) {
        deleteBeginning();
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos && temp; ++i) {
        temp = temp->next;
    }

    if (!temp) {
        cout << "Position out of bounds.\n";
        return;
    }

    if (temp->prev) {
        temp->prev->next = temp->next;
    }
    if (temp->next) {
        temp->next->prev = temp->prev;
    }

    if (temp == tail) {
        tail = temp->prev;
    }

    delete temp;
    cout << "Deleted element at position " << pos << ".\n";
}

// Search for a value in the list
void ListADT::search(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == value) {
            cout << "Element " << value << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Element " << value << " not found.\n";
}

// Display the list from beginning to end
void ListADT::display() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "List elements: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    ListADT list;
    int choice, value, pos;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert Beginning\n";
        cout << "2. Insert End\n";
        cout << "3. Insert Position\n";
        cout << "4. Delete Beginning\n";
        cout << "5. Delete End\n";
        cout << "6. Delete Position\n";
        cout << "7. Search\n";
        cout << "8. Display\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertEnd(value);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> value >> pos;
                list.insertPosition(value, pos);
                break;
            case 4:
                list.deleteBeginning();
                break;
            case 5:
                list.deleteEnd();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> pos;
                list.deletePosition(pos);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;
            case 8:
                list.display();
                break;
            case 9:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 9);

    return 0;
}
