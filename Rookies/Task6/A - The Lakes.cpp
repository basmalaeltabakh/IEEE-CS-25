#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int dfs(int i, int j, vector<vector<int>>& a, vector<vector<bool>>& visited, int n, int m)
{
    visited[i][j] = true;
    int ans = a[i][j];

    if (i > 0 && a[i - 1][j] > 0 && !visited[i - 1][j])
    {
        ans += dfs(i - 1, j, a, visited, n, m);
    }
    if (i < n - 1 && a[i + 1][j] > 0 && !visited[i + 1][j])
    {
        ans += dfs(i + 1, j, a, visited, n, m);
    }
    if (j > 0 && a[i][j - 1] > 0 && !visited[i][j - 1])
    {
        ans += dfs(i, j - 1, a, visited, n, m);
    }
    if (j < m - 1 && a[i][j + 1] > 0 && !visited[i][j + 1])
    {
        ans += dfs(i, j + 1, a, visited, n, m);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && a[i][j] > 0)
                {
                    ans = max(ans, dfs(i, j, a, visited, n, m));

                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
