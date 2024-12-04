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
    vector<int>h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    int Min = 0, Max = 0;
    for (int i = 0; i < n; i++)
    {
        if (h[i] > h[Max])
            Max = i;
        if (h[i] <= h[Min])
            Min = i;
    }
    int swaps = Max + (n - 1 - Min);
    if (Max > Min)
    {
        swaps -= 1;
    }

    cout << swaps << endl;
    return 0;
}
