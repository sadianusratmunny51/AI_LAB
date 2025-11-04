#include <bits/stdc++.h>
using namespace std;

unordered_map<char, vector<pair<char, int>>> graph;

bool ucs(char start, char goal) {
    unordered_map<char, bool> visited; 
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        pair<int, char> current = pq.top();
        pq.pop();

        int cost = current.first;
        char node = current.second;

        if (visited[node]) continue;
        visited[node] = true;

        //cout << "Visited: " << node << " with cost: " << cost << endl;

        if (node == goal) {
            cout << "Goal '" << goal << "reached with total cost: " << cost << endl;
            return true;
        }

        for (pair<char, int> neighbor : graph[node]) {
            char nextNode = neighbor.first;
            int edgeCost = neighbor.second;

            if (!visited[nextNode]) {
                pq.push({cost + edgeCost, nextNode});
            }
        }
    }

    cout << "Goal not reachable from start node.\n";
    return false;
} 

int32_t main() {
    int edges;
    cout << "Enter number of edges:\n";
    cin >> edges;

    cout << "Enter edges with cost :\n";
    for (int i = 0; i < edges; i++) {
        char u, v;
        int cost;
        cin >> u >> v >> cost;
        graph[u].push_back({v, cost});
        // graph[v].push_back({u, cost});
    }

    char start, goal;
    cout << "Enter start node: ";
    cin >> start;
    cout << "Enter goal node: ";
    cin >> goal;

    cout << "\nUCS traversal from '" << start << "' to '" << goal << "':\n";
    ucs(start, goal);

    return 0;
}
