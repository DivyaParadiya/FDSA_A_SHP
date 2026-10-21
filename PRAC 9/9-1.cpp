
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int node, vector<int> adj[], bool visited[]) {
    visited[node] = true;
    cout << node << " ";

    for (int next : adj[node]) {
        if (!visited[next])
            DFS(next, adj, visited);
    }
}

void BFS(int start, vector<int> adj[], int n) {
    bool visited[n] = {};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int next : adj[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter buildings and roads: ";
    cin >> n >> m;

    vector<int> adj[n];

    cout << "Enter roads (building1 building2):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter starting building: ";
    cin >> start;

    bool visited[n] = {};

    cout << "DFS: ";
    DFS(start, adj, visited);

    cout << "\nBFS: ";
    BFS(start, adj, n);

    return 0;
}
