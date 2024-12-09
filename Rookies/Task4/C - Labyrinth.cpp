#include <bits/stdc++.h>
#include<iostream>
#define long long ll
using namespace std;
const int N = 1005;
int n, m;
char Map[N][N];
bool visited[N][N];
char parentDir[N][N];
pair<int, int> parentPos[N][N];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
char dir[] = { 'U', 'D', 'L', 'R' };

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && Map[x][y] != '#' && !visited[x][y];
}

void BFS(int startX, int startY, int endX, int endY) {
    queue<pair<int, int>> q;
    q.push({ startX, startY });
    visited[startX][startY] = true;

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        int x = front.first;
        int y = front.second;

        if (x == endX && y == endY) {
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
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (isValid(newX, newY)) {
                visited[newX][newY] = true;
                parentDir[newX][newY] = dir[i];
                parentPos[newX][newY] = { x, y };
                q.push({ newX, newY });
            }
        }
    }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int startX, startY, endX, endY;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> Map[i][j];
            if (Map[i][j] == 'A') {
                startX = i;
                startY = j;
            }
            else if (Map[i][j] == 'B') {
                endX = i;
                endY = j;
            }
        }
    }

    BFS(startX, startY, endX, endY);

    return 0;
}
