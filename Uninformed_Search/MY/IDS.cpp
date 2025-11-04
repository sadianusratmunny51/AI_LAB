#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<vector<char>> graph(N);
 unordered_map<char, bool> visited;

bool dls(char node, char dest, int limit) {
    cout << node << " ";
    if (node == dest) return true;
    if (limit <= 0) return false;

    visited[node] = true;

    for (char neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (dls(neighbor, dest, limit - 1)) return true;
        }
    }
    return false;
}

bool ids(char start, char dest, int maxDepth) {
    for (int depth = 0; depth <= maxDepth; depth++) {

        cout << "\nDepth: " << depth << "\n";
        if (dls(start, dest, depth)) {
            cout << "\nDestination found.\n";
            return true;
        }
        cout << "\n";
    }
    cout << "Destination not found within depth limit.\n";
    return false;
}

int32_t main() {
    int nodes, edges;
    cout << "Enter number of nodes:\n";
    cin >> nodes;

    cout << "Enter number of edges:\n";
    cin >> edges;

    cout << "Enter edges (e.g. A B):\n";
    for (int i = 0; i < edges; i++) {
        char u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    char dest;
    int maxDepth;
    cout << "Enter destination: ";
    cin >> dest;

    cout << "Enter maximum depth: ";
    cin >> maxDepth;

    cout << "\nIDS traversal from node A to " << dest << ":\n";
    ids('A', dest, maxDepth);

    return 0;
}
