#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<vector<char>> graph(N);  
unordered_map<char, bool> visited;

bool dfs(char node, char dest, vector<char>& traversal) {
    //cout << node << " ";
    if (node == dest) return true;

    visited[node] = true;

    for (char neighbor : graph[node]) {
        if (!visited[neighbor]) {
            traversal.push_back(neighbor);
            bool val=dfs(neighbor, dest, traversal);
               
            
            for(int i=0;i<traversal.size();i++){
               cout<<traversal[i]<<" ";
            }
            cout<<endl;
            traversal.clear();
            if (val) return true;
        }
    }
    return false;
}

int32_t main() {
    int node, edges;
    cout << "Enter the number of nodes:";
    cin >> node;

    cout << "Enter the number of edges:";
    cin >> edges;

    cout << "Enter edges:";
    for (int i = 1; i <= edges; i++) {
        char x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    char dest;
    cout << "Enter the destination: ";
    cin >> dest;

    cout << "DFS Traversal from node A to " << dest << ":\n";
    
    vector<char>traversal;
    traversal.push_back('A');

    if (!dfs('A', dest,traversal)) {
        cout << "Destination not reachable.";
    }

    return 0;
}
/*
15 14
A B
B F
B G
G K
G L
L O
A C
C H
A D
D I
I M
D J
J N
A E
O*/