#include <iostream>
#include <bits/stdc++.h>
#define long long ll
using namespace std;
vector<int> adj[100005];
bool visited[100005];
void BFS(int start, vector<int>& connected) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    connected.push_back(start);
    while (!q.empty()) {
        int city = q.front();
        q.pop();

        for (int neighbor : adj[city]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                connected.push_back(neighbor);
                q.push(neighbor);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<int>> connecteds;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> connected;
            bfs(i, connected);
            connecteds.push_back(connected);
        }
    }
    vector<pair<int, int>> new_roads;
    for (int i = 1; i < connecteds.size(); i++) {
        new_roads.push_back({ connecteds[i - 1][0], connecteds[i][0] });
    }
    cout << new_roads.size() << "\n";
    for (auto road : new_roads) {
        cout << road.first << " " << road.second << "\n";
    }

    return 0;
}
