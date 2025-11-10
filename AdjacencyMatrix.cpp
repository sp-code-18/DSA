#include <iostream>
using namespace std;

#define MAX 10   // Maximum number of cities

// Function to perform Depth First Search (DFS)
void DFS(int graph[MAX][MAX], int visited[MAX], int n, int start) {
    visited[start] = 1;   // Mark current city as visited

    for (int i = 0; i < n; i++) {
        if (graph[start][i] == 1 && visited[i] == 0) {
            DFS(graph, visited, n, i);
        }
    }
}

// Main0 function
int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    string cities[MAX];
    cout << "Enter names of cities:\n";
    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }

    int graph[MAX][MAX];
    cout << "\nEnter adjacency matrix (1 if flight exists, 0 if not):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // Display adjacency matrix
    cout << "\nAdjacency Matrix:\n   ";
    for (int i = 0; i < n; i++)
        cout << cities[i] << " ";
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << cities[i] << " ";
        for (int j = 0; j < n; j++) {
            cout << " " << graph[i][j] << " ";
        }
        cout << endl;
    }

    // Check connectivity using DFS
    int visited[MAX] = {0};
    DFS(graph, visited, n, 0); // Start DFS from first city

    // Check if all cities were visited
    bool connected = true;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            connected = false;
            break;
        }
    }

    if (connected)
        cout << "\n The graph is CONNECTED. All cities are reachable.\n";
    else
        cout << "\n The graph is NOT connected. Some cities are unreachable.\n";

    return 0;
}

