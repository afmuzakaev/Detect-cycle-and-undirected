#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool hasCycleUtil(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (hasCycleUtil(neighbor, node, adj, visited)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true;
        }
    }
    
    return false;
}

bool hasCycle(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (hasCycleUtil(i, -1, adj, visited)) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    int V, E;
    cin >> V >> E;
    
    vector<vector<int>> adj(V);
    
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Since the graph is undirected
    }
    
    if (hasCycle(adj, V)) {
        cout << "Output: 1" << endl;
    } else {
        cout << "Output: 0" << endl;
    }
    
    return 0;
}
