/*
Write a separate C++ menu-driven program to implement Graph ADT with the implementation for Prim’s algorithm, Kruskal’s algorithm, and Dijkstra’s algorithm. Maintain proper boundary 
conditions and follow good coding practices
*/
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

class Edge {
public:
    int src, dest, weight;
    Edge(int s, int d, int w): src(s), dest(d), weight(w) {}
};

class Graph {
private:
    int V;
    vector<list<pair<int, int>>> adjList;
    vector<Edge> edgeList;

public:
    Graph(int vertices): V(vertices) {
        adjList.resize(V);
    }

    void addEdge(int u, int v, int w) {
        if (u >= V || v >= V || u < 0 || v < 0) {
            cout << "Invalid vertex number.\n";
            return;
        }
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w}); // For undirected graph
        edgeList.push_back(Edge(u, v, w));
        cout << "Edge added between " << u << " and " << v << " with weight " << w << ".\n";
    }

    void displayGraph() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < V; ++i) {
            cout << i << " -> ";
            for (auto& neighbor : adjList[i]) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }

    void primMST() {
        vector<int> key(V, INF);
        vector<bool> inMST(V, false);
        vector<int> parent(V, -1);
        key[0] = 0;

        for (int count = 0; count < V - 1; ++count) {
            int u = -1;
            int minKey = INF;
            for (int v = 0; v < V; ++v) {
                if (!inMST[v] && key[v] < minKey) {
                    minKey = key[v];
                    u = v;
                }
            }

            if (u == -1) break;

            inMST[u] = true;

            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                }
            }
        }

        cout << "Prim's MST:\n";
        for (int i = 1; i < V; ++i) {
            if (parent[i] != -1)
                cout << parent[i] << " - " << i << endl;
        }
    }

    int findParent(int u, vector<int>& parent) {
        if (parent[u] != u)
            parent[u] = findParent(parent[u], parent);
        return parent[u];
    }

    void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
        int uRoot = findParent(u, parent);
        int vRoot = findParent(v, parent);
        if (rank[uRoot] < rank[vRoot]) {
            parent[uRoot] = vRoot;
        } else if (rank[uRoot] > rank[vRoot]) {
            parent[vRoot] = uRoot;
        } else {
            parent[vRoot] = uRoot;
            rank[uRoot]++;
        }
    }

    void kruskalMST() {
        vector<Edge> result;
        vector<int> parent(V);
        vector<int> rank(V, 0);

        for (int i = 0; i < V; ++i)
            parent[i] = i;

        sort(edgeList.begin(), edgeList.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        for (auto& edge : edgeList) {
            int uRoot = findParent(edge.src, parent);
            int vRoot = findParent(edge.dest, parent);
            if (uRoot != vRoot) {
                result.push_back(edge);
                unionSets(uRoot, vRoot, parent, rank);
            }
        }

        cout << "Kruskal's MST:\n";
        for (auto& edge : result) {
            cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
        }
    }

    void dijkstra(int src) {
        vector<int> dist(V, INF);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Dijkstra's shortest paths from vertex " << src << ":\n";
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << " : Distance = ";
            if (dist[i] == INF)
                cout << "INF";
            else
                cout << dist[i];
            cout << endl;
        }
    }
};

int main() {
    int vertices;
    cout << "Enter the number of vertices in the graph: ";
    cin >> vertices;
    Graph g(vertices);

    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Edge\n";
        cout << "2. Display Graph\n";
        cout << "3. Prim's MST\n";
        cout << "4. Kruskal's MST\n";
        cout << "5. Dijkstra's Shortest Path\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int u, v, w;
            cout << "Enter source vertex, destination vertex, and weight: ";
            cin >> u >> v >> w;
            g.addEdge(u, v, w);
        } else if (choice == 2) {
            g.displayGraph();
        } else if (choice == 3) {
            g.primMST();
        } else if (choice == 4) {
            g.kruskalMST();
        } else if (choice == 5) {
            int src;
            cout << "Enter source vertex: ";
            cin >> src;
            g.dijkstra(src);
        } else if (choice == 6) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
