#include <bits/stdc++.h>
#include <iostream>
#define long long ll
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    int dx[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
    int dy[] = { 1, -1, 1, -1, 2, -2, 2, -2 };
    while (t--)
    {
        string start, dest;
        cin >> start >> dest;

        int startX = start[0] - 'a';
        int startY = start[1] - '1';
        int destX = dest[0] - 'a';
        int destY = dest[1] - '1';
        if (startX == destX && startY == destY)
        {
            cout << 0 << endl;
            continue;
        }
        queue<pair<pair<int, int>, int>> q;
        q.push({ {startX,startY},0 });
        vector<vector<bool>> visited(8, vector<bool>(8, false));
        visited[startX][startY] = true;
        bool found = false;
        while (!q.empty() && !found)
        {
            auto front = q.front();
            q.pop();
            int X = front.first.first;
            int Y = front.first.second;
            int steps = front.second;
            for (int i = 0; i < 8; i++)
            {
                int newX = X + dx[i];
                int newY = Y + dy[i];
                if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8 && !visited[newX][newY])
                {
                    if (newX == destX && newY == destY)
                    {
                        cout << steps + 1 << endl;
                        found = true;
                        break;
                    }
                    visited[newX][newY] = true;
                    q.push({ {newX,newY},steps + 1 });
                }

            }

        }
    }

    return 0;
}
