#include <iostream>
using namespace std;

const int MAX = 100; // Maximum number of Vertices

// DFS function to mark visited nodes
void DFS(int v, int adj[MAX][MAX], bool Visited[], int Vertices) {
    Visited[v] = true;
    for (int i = 0; i < Vertices; i++) {
        if (adj[v][i] && !Visited[i]) {
            DFS(i, adj, Visited, Vertices);
        }
    }
}

// Function to check if the graph is connected
bool isConnected(int adj[MAX][MAX], int Vertices) {
    bool Visited[MAX] = { false };
    DFS(0, adj, Visited, Vertices); // Start DFS from node 0

    // If any node is unvisited, the graph is not connected
    for (int i = 0; i < Vertices; i++) {
        if (!Visited[i]) {
            return false;
        }
    }
    return true;
}

// Function to handle input validation
int getValidRelationInput(int i, int j) {
    int relation;
    while (true) {
        cout << "Enter relation B/W vertex " << i + 1 << " and vertex " << j + 1 << " : ";
        cin >> relation;
       
        if (relation == 0 || relation == 1) {
            return relation; // Valid input
        } else {
            cout << "Invalid input! Please enter 1 or 0 only.\n";
        }
    }
}

int main() {
    int Vertices; // Number of Vertices
    int adj[MAX][MAX] = { 0 }; // Adjacency matrix

    cout << "Enter number of Vertices: ";
    cin >> Vertices;

    cout << "Enter 1 if these vertices are connected, if not then enter 0" << endl;
   
    // Input the adjacency matrix
    for (int i = 0; i < Vertices; i++) {
        for (int j = i + 1; j < Vertices; j++) { // Only fill the upper triangle, as the graph is undirected
            int relation = getValidRelationInput(i, j);
            adj[i][j] = relation;
            adj[j][i] = relation; // Since the graph is undirected, mirror the relation
        }
    }

    // Check if the graph is connected
    if (isConnected(adj, Vertices)) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is not connected." << endl;
    }

    return 0;
}