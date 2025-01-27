#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1005;
int n, m;
char Map[N][N];
int playerTime[N][N], monsterTime[N][N];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
char dir[] = { 'U', 'D', 'L', 'R' };

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && Map[x][y] != '#';
}

void monsterBFS(vector<pair<int, int>>& monsters) {
    queue<pair<int, int>> q;
    for (auto monster : monsters) {
        q.push(monster);
        monsterTime[monster.first][monster.second] = 0;
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isValid(nx, ny) && monsterTime[nx][ny] == -1) {
                monsterTime[nx][ny] = monsterTime[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }
}

bool playerDFS(int x, int y, int time, int startX, int startY, vector<vector<bool>>& visited) {
    if (!isValid(x, y) || visited[x][y] || (monsterTime[x][y] != -1 && time >= monsterTime[x][y]))
        return false;
    visited[x][y] = true;
    if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
        cout << "YES" << endl;
        string path = "";
        while (!(x == startX && y == startY)) {
            path += dir[Map[x][y]];
            int prevX = x - dx[Map[x][y]];
            int prevY = y - dy[Map[x][y]];
            x = prevX;
            y = prevY;
        }
        reverse(path.begin(), path.end());
        cout << path.length() << endl << path << endl;
        return true;
    }

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i], newY = y + dy[i];
        if (isValid(newX, newY) && !visited[newX][newY]) {
            Map[newX][newY] = i;
            if (playerDFS(newX, newY, time + 1, startX, startY, visited)) {
                return true;
            }
        }
    }

    visited[x][y] = false;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int startX, startY;
    vector<pair<int, int>> monsters;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> Map[i][j];
            if (Map[i][j] == 'A') {
                startX = i;
                startY = j;
            }
            else if (Map[i][j] == 'M') {
                monsters.push_back({ i, j });
            }
            playerTime[i][j] = -1;
            monsterTime[i][j] = -1;
        }
    }

    monsterBFS(monsters);

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    if (!playerDFS(startX, startY, 0, startX, startY, visited)) {
        cout << "NO" << endl;
    }

    return 0;
}
