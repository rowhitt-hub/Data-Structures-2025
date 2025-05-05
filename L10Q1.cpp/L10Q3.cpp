/*
Write a separate C++ menu-driven program to implement Priority Queue ADT using a max heap. Maintain proper boundary conditions and follow good coding practices. 
The Priority Queue ADT has the following operations, 
 
1. Insert 
2. Delete 
3. Display 
4. Search 
5. Sort (Heap Sort)  
6. Exit 
*/
//Program to perform the standard operations of a heap

#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int heap[100];  // Max heap array
    int size;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    PriorityQueue();
    void insert(int value);
    int deleteMax();
    void display() const;
    bool search(int value) const;
    void heapSort();
};

PriorityQueue::PriorityQueue() {
    size = 0;
}

//Inserting into the heap
void PriorityQueue::insert(int value) {
    if (size >= 100) {
        cout << "Heap overflow!" << endl;
        return;
    }
    heap[size] = value;
    heapifyUp(size);
    size++;
}

//To retain heap properties after insertion
void PriorityQueue::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

//Deleting the element with the highest value
int PriorityQueue::deleteMax() {
    if (size == 0) {
        cout << "Heap underflow!" << endl;
        return -1;
    }
    int maxVal = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return maxVal;
}

//To retain the heap properties after deletion
void PriorityQueue::heapifyDown(int index) {
    int leftChild, rightChild, largest;
    while (true) {
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        largest = index;
        
        if (leftChild < size && heap[leftChild] > heap[largest])
            largest = leftChild;
        
        if (rightChild < size && heap[rightChild] > heap[largest])
            largest = rightChild;
        
        if (largest != index) {
            swap(heap[index], heap[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

//To display the contents of the heap
void PriorityQueue::display() const {
    if (size == 0) {
        cout << "Heap is empty." << endl;
        return;
    }
    for (int i = 0; i < size; i++)
        cout << heap[i] << " ";
    cout << endl;
}

//Search for a value in the heap
bool PriorityQueue::search(int value) const {
    for (int i = 0; i < size; i++) {
        if (heap[i] == value) {
            return true;
        }
    }
    return false;
}

//Sorting the values in the heap
void PriorityQueue::heapSort() {
    int tempSize = size;
    for (int i = tempSize - 1; i > 0; i--) {
        swap(heap[0], heap[i]);
        size--;
        heapifyDown(0);
    }
    size = tempSize;  // Restore original size
    cout << "Sorted elements: ";
    display();
}

int main() {
    PriorityQueue pq;
    int choice, value;
    while (true) {
        cout << "\nPriority Queue Operations:\n";
        cout << "1. Insert\n2. Delete Max\n3. Display\n4. Search\n5. Sort (Heap Sort)\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                pq.insert(value);
                break;
            case 2:
                cout << "Deleted max element: " << pq.deleteMax() << endl;
                break;
            case 3:
                pq.display();
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                if (pq.search(value))
                    cout << "Value found in the priority queue." << endl;
                else
                    cout << "Value not found." << endl;
                break;
            case 5:
                pq.heapSort();
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}

