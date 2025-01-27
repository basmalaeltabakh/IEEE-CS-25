#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MaxN = 105;
vector<pair<int, int>> bosyAdj[MaxN];
int n;


int dfs(int node, int parent) {
    int maxCost = 0;
    for (auto& neighbor : bosyAdj[node]) {
        int nextNode = neighbor.first;
        int edgeCost = neighbor.second;
        if (nextNode != parent) {
            int currentCost = dfs(nextNode, node) + edgeCost;
            if (currentCost > maxCost) {
                maxCost = currentCost;
            }
        }
    }
    return maxCost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        bosyAdj[u].push_back({ v, c });
        bosyAdj[v].push_back({ u, c });
    }
    int maxCost = dfs(0, -1);
    cout << maxCost << endl;

    return 0;
}
