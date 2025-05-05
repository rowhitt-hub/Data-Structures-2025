/*
Write a separate C++ menu-driven program to implement Hash ADT with Linear Probing. Maintain proper boundary conditions and follow good coding practices. 
The Hash ADT has the following operations,

1. Insert
2. Delete
3. Search
4. Display
5. Exit
*/
#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<int> table;
    int size;
    const int EMPTY = -1;
    const int DELETED = -2;

    int hashFunction(int key);

public:
    HashTable(int s);

    void insert(int key);
    void remove(int key);
    void search(int key);
    void display();
};

int main() {
    int size, choice, key;
    cout << "Enter size of the hash table: ";
    cin >> size;

    HashTable ht(size);

    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insert(key);
        } else if (choice == 2) {
            cout << "Enter key to delete: ";
            cin >> key;
            ht.remove(key);
        } else if (choice == 3) {
            cout << "Enter key to search: ";
            cin >> key;
            ht.search(key);
        } else if (choice == 4) {
            ht.display();
        } else if (choice == 5) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}



HashTable::HashTable(int s) {
    size = s;
    table.resize(size, EMPTY);
}

int HashTable::hashFunction(int key) {
    return key % size;
}

void HashTable::insert(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < size) {
        int probe = (index + i) % size;
        if (table[probe] == EMPTY || table[probe] == DELETED) {
            table[probe] = key;
            cout << "Inserted at index " << probe << endl;
            return;
        }
        i++;
    }

    cout << "Hash table is full. Cannot insert.\n";
}

void HashTable::remove(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < size) {
        int probe = (index + i) % size;
        if (table[probe] == key) {
            table[probe] = DELETED;
            cout << "Deleted key from index " << probe << endl;
            return;
        } else if (table[probe] == EMPTY) {
            break;
        }
        i++;
    }

    cout << "Key not found.\n";
}

void HashTable::search(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < size) {
        int probe = (index + i) % size;
        if (table[probe] == key) {
            cout << "Found key at index " << probe << endl;
            return;
        } else if (table[probe] == EMPTY) {
            break;
        }
        i++;
    }

    cout << "Key not found.\n";
}

void HashTable::display() {
    cout << "Hash Table:\n";
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "] : ";
        if (table[i] == EMPTY)
            cout << "EMPTY\n";
        else if (table[i] == DELETED)
            cout << "DELETED\n";
        else
            cout << table[i] << "\n";
    }
}
