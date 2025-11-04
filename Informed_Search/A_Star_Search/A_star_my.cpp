#include <bits/stdc++.h>
using namespace std;

int main() {
    // Example graph
    map<string, vector<pair<string,int>>> graph = {
        {"A", {{"B",1},{"C",4}}},
        {"B", {{"C",2},{"D",5}}},
        {"C", {{"E",3}}},
        {"D", {{"E",2}}},
        {"E", {}}
    };

    map<string,int> h = {{"A",6},{"B",4},{"C",2},{"D",3},{"E",0}};
    map<string,int> g, f;
    map<string,string> parent;
    // for (map<string, vector<pair<string,int>>>::iterator it = graph.begin(); it != graph.end(); ++it) {
    //     g[it->first] = INT_MAX;
    //     f[it->first] = INT_MAX;
    //     parent[it->first] = "";
    // }
    for(auto it:graph){
        g[it.first]=INT_MAX; 
        f[it.first]=INT_MAX;
        parent[it.first]="";
    }

    string start = "A", goal = "E";
    g[start] = 0;
    f[start] = g[start] + h[start];

    typedef pair<int,string> PIS;
    priority_queue<PIS, vector<PIS>, greater<PIS>> open;
    set<string> closed;

    open.push({f[start], start});

    cout << "Starting A* Search...\n";

    while (!open.empty()) {
        pair<int,string> top = open.top();
        open.pop();

        string node = top.second;
        if (closed.count(node)) continue;
        closed.insert(node);

        cout << "\nExpanding: " << node 
             << " (g=" << g[node] << ", h=" << h[node] << ", f=" << f[node] << ")\n";

        if (node == goal) {
            cout << "\n✅ Goal reached: " << node << endl;
            // reconstruct path
            vector<string> path;
            string cur = node;
            while (cur != "") {
                path.push_back(cur);
                cur = parent[cur];
            }
            reverse(path.begin(), path.end());
            cout << "Path: ";
            for (int i=0;i<path.size();i++) cout << path[i] << " ";
            cout << "\nTotal cost: " << g[node] << endl;
            return 0;
        }

        // neighbor explore (no structured binding)
        for (int i=0; i<graph[node].size(); i++) {
            string nbr = graph[node][i].first;
            int cost = graph[node][i].second;

            if (closed.count(nbr)) continue;

            int g_new = g[node] + cost;
            int f_new = g_new + h[nbr];

            if (g_new < g[nbr]) {
                g[nbr] = g_new;
                f[nbr] = f_new;
                parent[nbr] = node;
                cout << "  Neighbor " << nbr << ": g=" << g_new << " h=" << h[nbr] << " f=" << f_new << endl;
                open.push(make_pair(f_new, nbr));
            }
        }
    }

    cout << "\n❌ No path found!\n";
    return 0;
}
