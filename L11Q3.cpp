/*
Write a separate C++ menu-driven program to implement Hash ADT with Separate Chaining. Maintain proper boundary conditions and follow good coding 
practices. The Hash ADT has the following operations,

1. Insert
2. Delete
3. Search
4. Exit
*/
#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<vector<int>> table;
    int size;

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
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Exit\nEnter choice: ";
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
    table.resize(size);
}

int HashTable::hashFunction(int key) {
    return key % size;
}

void HashTable::insert(int key) {
    int index = hashFunction(key);
    table[index].push_back(key);
    cout << "Inserted key " << key << " at index " << index << endl;
}

void HashTable::remove(int key) {
    int index = hashFunction(key);
    vector<int>& chain = table[index];

    for (int i = 0; i < chain.size(); i++) {
        if (chain[i] == key) {
            chain.erase(chain.begin() + i);
            cout << "Deleted key " << key << " from index " << index << endl;
            return;
        }
    }

    cout << "Key not found.\n";
}

void HashTable::search(int key) {
    int index = hashFunction(key);
    vector<int>& chain = table[index];

    for (int i = 0; i < chain.size(); i++) {
        if (chain[i] == key) {
            cout << "Found key " << key << " at index " << index << endl;
            return;
        }
    }

    cout << "Key not found.\n";
}

void HashTable::display() {
    cout << "Hash Table:\n";
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "]: ";
        for (int val : table[i]) {
            cout << val << " -> ";
        }
        cout << "NULL\n";
    }
}

