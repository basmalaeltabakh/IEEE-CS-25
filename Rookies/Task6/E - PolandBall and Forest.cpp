#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void dfs(int node, vector<vector<int>>& BosyGraph, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : BosyGraph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, BosyGraph, visited);
        }
    }
}

int Trees(int n, vector<int>& p) {
    vector<vector<int>> BosyGraph(n + 1);
    for (int i = 1; i <= n; i++) {
        BosyGraph[i].push_back(p[i - 1]);
        BosyGraph[p[i - 1]].push_back(i);
    }
    vector<bool> visited(n + 1, false);
    int counter = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, BosyGraph, visited);
            counter++;
        }
    }

    return counter;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int result = Trees(n, p);
    cout << result << endl;


    return 0;
}
