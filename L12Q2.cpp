/*
Write a separate C++ menu-driven program to implement Graph ADT with an adjacency list. Maintain proper boundary conditions and follow 
good coding practices. The Graph ADT has the following operations,

1. Insert
2. Delete
3. Search
4. Display
5. Exit
*/

// Program to implement Graph ADT using Adjacency Matrix
#include <iostream>
using namespace std;

#define MAX 10

class Graph {
private:
    int adj[MAX][MAX];
    int numVertices;
public:
    Graph();
    void insertEdge(int src, int dest);
    void deleteEdge(int src, int dest);
    bool searchEdge(int src, int dest);
    void displayGraph();
};

Graph::Graph() {
    numVertices = MAX;
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++)
            adj[i][j] = 0;
}

// Insert an edge from src to dest
void Graph::insertEdge(int src, int dest) {
    if (src >= numVertices || dest >= numVertices || src < 0 || dest < 0) {
        cout << "Invalid vertex number. Try again.\n";
        return;
    }
    adj[src][dest] = 1;
    adj[dest][src] = 1; // For undirected graph
    cout << "Edge inserted between " << src << " and " << dest << ".\n";
}

// Delete an edge between src and dest
void Graph::deleteEdge(int src, int dest) {
    if (src >= numVertices || dest >= numVertices || src < 0 || dest < 0) {
        cout << "Invalid vertex number. Try again.\n";
        return;
    }
    if (adj[src][dest] == 0) {
        cout << "No edge exists between " << src << " and " << dest << ".\n";
        return;
    }
    adj[src][dest] = 0;
    adj[dest][src] = 0; // For undirected graph
    cout << "Edge deleted between " << src << " and " << dest << ".\n";
}

// Search for an edge between src and dest
bool Graph::searchEdge(int src, int dest) {
    if (src >= numVertices || dest >= numVertices || src < 0 || dest < 0) {
        cout << "Invalid vertex number.\n";
        return false;
    }
    return adj[src][dest] == 1;
}

// Display the adjacency matrix
void Graph::displayGraph() {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Graph g;
    int choice, src, dest;

    while (1) {
        cout << "\n1. Insert Edge\n2. Delete Edge\n3. Search Edge\n4. Display Graph\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter source and destination vertices (0-9): ";
            cin >> src >> dest;
            g.insertEdge(src, dest);
            break;

        case 2:
            cout << "Enter source and destination vertices (0-9): ";
            cin >> src >> dest;
            g.deleteEdge(src, dest);
            break;

        case 3:
            cout << "Enter source and destination vertices (0-9): ";
            cin >> src >> dest;
            if (g.searchEdge(src, dest))
                cout << "Edge exists between " << src << " and " << dest << ".\n";
            else
                cout << "No edge exists between " << src << " and " << dest << ".\n";
            break;

        case 4:
            g.displayGraph();
            break;

        case 5:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}
