#include <bits/stdc++.h>
#include <iostream>
#define long long ll
using namespace std;

int n, m;
vector<vector<char>> building;
vector<vector<bool>> visited;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void BFS(int startX, int startY)
{
    queue<pair<int, int>> q;
    q.push({ startX, startY });
    visited[startX][startY] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && building[newX][newY] == '.' && !visited[newX][newY])
            {
                visited[newX][newY] = true;
                q.push({ newX, newY });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    building.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> building[i][j];
        }
    }

    int rooms = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (building[i][j] == '.' && !visited[i][j])
            {
                BFS(i, j);
                rooms++;
            }
        }
    }
    cout << rooms << endl;

    return 0;
}
