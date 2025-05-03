/*
Write a C++ menu-driven program to implement List ADT using a singly linked list. You have a
gethead() private member funcƟon that returns the address of the head value of a list. Maintain
proper boundary condiƟons and follow good coding pracƟces. The List ADT has the following
operaƟons,
1. Insert Ascending
2. Merge
3. Display
4. Exit
OpƟon 1 inserts a node so the list is always in ascending order. OpƟon 2 takes two lists as input, and
merges two lists into a third list. The third list should also be in ascending order. Convert the file into
a header file and include it in a C++ file. The second C++ consists of 3 lists and has the following
operaƟons,
1. Insert List1
2. Insert List2
3. Merge into List3
4. Display
5. Exit 
*/
// ListADT.cpp
#include "ListADT.h"
#include <iostream>
using namespace std;

ListADT::ListADT() {
    head = nullptr;
}

ListADT::~ListADT() {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

// Private method to return the address of the head node
ListADT::Node* ListADT::getHead() {
    return head;
}

// Insert value into the list while keeping the list in ascending order
void ListADT::insertAscending(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head || head->data > value) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next && temp->next->data <= value) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    cout << "Inserted " << value << " into the list in ascending order.\n";
}

// Merge two lists into a third list, keeping the result in ascending order
void ListADT::merge(ListADT& list2, ListADT& list3) {
    Node* ptr1 = head;
    Node* ptr2 = list2.getHead();
    Node* mergedList = nullptr;
    Node* mergedTail = nullptr;

    while (ptr1 && ptr2) {
        Node* newNode;
        if (ptr1->data <= ptr2->data) {
            newNode = new Node{ptr1->data, nullptr};
            ptr1 = ptr1->next;
        } else {
            newNode = new Node{ptr2->data, nullptr};
            ptr2 = ptr2->next;
        }

        if (!mergedList) {
            mergedList = newNode;
            mergedTail = mergedList;
        } else {
            mergedTail->next = newNode;
            mergedTail = newNode;
        }
    }

    while (ptr1) {
        Node* newNode = new Node{ptr1->data, nullptr};
        mergedTail->next = newNode;
        mergedTail = newNode;
        ptr1 = ptr1->next;
    }

    while (ptr2) {
        Node* newNode = new Node{ptr2->data, nullptr};
        mergedTail->next = newNode;
        mergedTail = newNode;
        ptr2 = ptr2->next;
    }

    list3.head = mergedList;
    cout << "Lists merged into list3 in ascending order.\n";
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
