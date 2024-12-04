#include <iostream>
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string dir;
    cin >> dir;
    vector<int>pos(n);
    for (int i = 0; i < n; i++)
        cin >> pos[i];
    int MinTime = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (dir[i] == 'R' && dir[i + 1] == 'L')
        {
            int time = (pos[i + 1] - pos[i]) / 2;
            if (MinTime == -1 || time < MinTime)
                MinTime = time;
        }
    }
    cout << MinTime << endl;
    return 0;
}
