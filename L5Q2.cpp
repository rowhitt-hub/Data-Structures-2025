/*
Write a C++ menu-driven program to implement List ADT using a circular linked list. Maintain
proper boundary condiƟons and follow good coding practices. The List ADT has the following
operations,
 1. Insert Beginning
 2. Insert End
 3. Insert Position
 4. Delete Beginning 
 5. Delete End 
 6. Delete Position 
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
    };
    Node* head;

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

// Constructor to initialize an empty circular linked list
ListADT::ListADT() {
    head = nullptr;
}

// Destructor to delete the list and free memory
ListADT::~ListADT() {
    if (head) {
        Node* temp = head;
        do {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != head);
    }
}

// Insert at the beginning of the list
void ListADT::insertBeginning(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        head->next = head; // Point to itself
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    cout << "Inserted " << value << " at the beginning.\n";
}

// Insert at the end of the list
void ListADT::insertEnd(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        head->next = head; // Point to itself
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    cout << "Inserted " << value << " at the end.\n";
}

// Insert at a specific position (1-based index)
void ListADT::insertPosition(int value, int pos) {
    if (pos < 1) {
        cout << "Invalid position.\n";
        return;
    }
    Node* newNode = new Node{value, nullptr};
    if (pos == 1) {
        insertBeginning(value);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; ++i) {
        temp = temp->next;
    }
    if (temp->next == head) {
        cout << "Position out of bounds.\n";
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Inserted " << value << " at position " << pos << ".\n";
}

// Delete the first element
void ListADT::deleteBeginning() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == head) { // Only one node in the list
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = head->next;
        head = head->next;
        delete temp;
    }
    cout << "Deleted the first element.\n";
}

// Delete the last element
void ListADT::deleteEnd() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == head) { // Only one node in the list
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        Node* lastNode = temp->next;
        temp->next = head;
        delete lastNode;
    }
    cout << "Deleted the last element.\n";
}

// Delete a node at a specific position (1-based index)
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
    for (int i = 1; i < pos - 1 && temp->next != head; ++i) {
        temp = temp->next;
    }
    if (temp->next == head) {
        cout << "Position out of bounds.\n";
        return;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    cout << "Deleted element at position " << pos << ".\n";
}

// Search for an element in the list
void ListADT::search(int value) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == value) {
            cout << "Element " << value << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        ++pos;
    } while (temp != head);
    cout << "Element " << value << " not found.\n";
}

// Display all elements in the list
void ListADT::display() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "List elements: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
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
