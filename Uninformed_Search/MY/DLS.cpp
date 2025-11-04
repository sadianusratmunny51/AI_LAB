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
    int limit;
    cout << "Enter destination: ";
    cin >> dest;

    cout << "Enter depth limit: ";
    cin >> limit;

    cout << "DLS traversal from node A to " << dest << " with limit " << limit << ":\n";
    if (!dls('A', dest, limit)) {
        cout << "\nDestination not found within depth limit.\n";
    }

    return 0;
}
