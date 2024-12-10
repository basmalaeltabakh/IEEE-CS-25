#include<iostream>
#include <bits/stdc++.h>
#define long long ll
using namespace std;
const int N = 1005;
int n, m;
char Map[N][N];
bool visited[N][N];
char parentDir[N][N];
pair<int, int> parentPos[N][N];
int playerTime[N][N], monsterTime[N][N];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
char dir[] = { 'U', 'D', 'L', 'R' };
bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && Map[x][y] != '#';
}
void monsterBFS(vector<pair<int, int>> monsters) {
    queue<pair<int, int>> Monsterss;
    for (auto monster : monsters) {
        Monsterss.push(monster);
        monsterTime[monster.first][monster.second] = 0;
    }

    while (!Monsterss.empty()) {
        auto front = Monsterss.front();
        Monsterss.pop();

        int x = front.first, y = front.second;

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i], newY = y + dy[i];
            if (isValid(newX, newY) && monsterTime[newX][newY] == -1) {
                monsterTime[newX][newY] = monsterTime[x][y] + 1;
                Monsterss.push({ newX, newY });
            }
        }
    }
}
void playerBFS(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({ startX, startY });
    visited[startX][startY] = true;
    playerTime[startX][startY] = 0;

    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        int x = front.first, y = front.second;
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            cout << "YES\n";
            string path = "";
            while (!(x == startX && y == startY)) {
                path += parentDir[x][y];
                auto prev = parentPos[x][y];
                x = prev.first;
                y = prev.second;
            }
            reverse(path.begin(), path.end());
            cout << path.length() << "\n" << path << "\n";
            return;
        }
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i], newY = y + dy[i];
            if (isValid(newX, newY) && !visited[newX][newY] && (playerTime[x][y] + 1 < monsterTime[newX][newY] || monsterTime[newX][newY] == -1)) {
                visited[newX][newY] = true;
                parentDir[newX][newY] = dir[i];
                parentPos[newX][newY] = { x, y };
                playerTime[newX][newY] = playerTime[x][y] + 1;
                q.push({ newX, newY });
            }
        }
    }

    cout << "NO\n";
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
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            playerTime[i][j] = -1;
            monsterTime[i][j] = -1;
        }
    }
    monsterBFS(monsters);
    playerBFS(startX, startY);

    return 0;
}
