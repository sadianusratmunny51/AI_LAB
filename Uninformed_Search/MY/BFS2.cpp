#include <bits/stdc++.h>
using namespace std;

const int N = 1e3; 
vector<vector<char>> graph(N); 
unordered_map<char, bool> visited;
void bfs(char start, char dest) {
    queue<char> q;
    q.push(start);
    visited[start] = true;

    bool found = false;

    while (!q.empty()) {
       // int levelSize = q.size();

        // while (levelSize--) {
            char node = q.front();
            q.pop();

            cout << node << " ";
            if (node == dest) {
                found = true;
                break;
            }

            for (char neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        // }

        //cout << endl;
        if (found) break;
    }

    if (!found)
        cout << "Destination node not found in BFS traversal.\n";
}


int32_t main(){

     int nodes, edges;
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter edges (e.g., A B):\n"; 
    for (int i = 0; i < edges; i++) {
        char u, v;
        cin >> u >> v;
        graph[u].push_back(v);
       
    }

    char dest;
    cout << "Enter the destination node: ";
    cin >> dest;

    cout << "\nBFS Traversal (level-wise) from node A to destination " << dest << ":\n";
    bfs('A', dest);

}
// A B
// A C
// B D
// B E
// C F
// C G
// D H
// E I
// F J