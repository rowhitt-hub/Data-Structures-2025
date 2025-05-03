/*
A. Write a C++ menu-driven program to implement List ADT using a singly linked list. Maintain proper
boundary condiƟons and follow good coding pracƟces. The List ADT has the following operaƟons,
1. Insert Beginning
2. Insert End
3. Insert PosiƟon
4. Delete Beginning
5. Delete End
6. Delete PosiƟon
7. Search
8. Display
9. Display Reverse
10. Reverse Link
11. Exit 
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

    void displayReverseHelper(Node* node);
    
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
    void displayReverse();
    void reverseLinks();
};

// Constructor
ListADT::ListADT() {
    head = nullptr;
}

// Destructor
ListADT::~ListADT() {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

// Insert at beginning
void ListADT::insertBeginning(int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
    cout << "Inserted at beginning.\n";
}

// Insert at end
void ListADT::insertEnd(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
    cout << "Inserted at end.\n";
}

// Insert at position (1-based)
void ListADT::insertPosition(int value, int pos) {
    if (pos < 1) {
        cout << "Invalid position.\n";
        return;
    }
    if (pos == 1) {
        insertBeginning(value);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp; ++i)
        temp = temp->next;

    if (!temp) {
        cout << "Position out of bounds.\n";
        return;
    }

    Node* newNode = new Node{value, temp->next};
    temp->next = newNode;
    cout << "Inserted at position " << pos << ".\n";
}

// Delete from beginning
void ListADT::deleteBeginning() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    cout << "Deleted from beginning.\n";
}

// Delete from end
void ListADT::deleteEnd() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (!head->next) {
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }
    cout << "Deleted from end.\n";
}

// Delete from position
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
    for (int i = 1; i < pos - 1 && temp; ++i)
        temp = temp->next;

    if (!temp || !temp->next) {
        cout << "Position out of bounds.\n";
        return;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    cout << "Deleted from position " << pos << ".\n";
}

// Search for value
void ListADT::search(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == value) {
            cout << "Element found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Element not found.\n";
}

// Display the list
void ListADT::display() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    cout << "List elements: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Display the list in reverse (using recursion)
void ListADT::displayReverseHelper(Node* node) {
    if (!node) return;
    displayReverseHelper(node->next);
    cout << node->data << " ";
}

void ListADT::displayReverse() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    cout << "List in reverse: ";
    displayReverseHelper(head);
    cout << endl;
}

// Reverse the entire linked list
void ListADT::reverseLinks() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    cout << "List links reversed.\n";
}

int main() {
    ListADT list;
    int choice, value, pos;

    do {
        cout << "\n--- Singly Linked List ADT Menu ---\n";
        cout << "1. Insert Beginning\n2. Insert End\n3. Insert Position\n";
        cout << "4. Delete Beginning\n5. Delete End\n6. Delete Position\n";
        cout << "7. Search\n8. Display\n9. Display Reverse\n";
        cout << "10. Reverse Link\n11. Exit\n";
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
                list.displayReverse();
                break;
            case 10:
                list.reverseLinks();
                break;
            case 11:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 11);

    return 0;
}
