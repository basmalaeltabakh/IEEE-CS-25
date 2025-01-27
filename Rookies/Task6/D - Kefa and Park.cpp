#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m;
vector<vector<int>> bosyAdj;
vector<int> a;
int res = 0;
void dfs(int node, int parent, int cats)
{
    if (a[node] == 1)
    {
        cats++;
    }
    else
    {
        cats = 0;
    }

    if (cats > m)
    {
        return;
    }

    bool leaf = true;
    for (int neighbor : bosyAdj[node])
    {
        if (neighbor != parent)
        {
            leaf = false;
            dfs(neighbor, node, cats);
        }
    }

    if (leaf)
    {
        res++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    a.resize(n);
    bosyAdj.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        bosyAdj[x].push_back(y);
        bosyAdj[y].push_back(x);
    }

    dfs(0, -1, 0);
    cout << res << endl;
    return 0;
}
