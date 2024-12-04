#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, q;
    cin >> n >> q;
    vector<ll>points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i];
    }
    ll res = 0;
    int l = 0;
    for (int r = 0; r < n; r++)
    {
        while (points[r] - points[l] > q)
            l++;
        ll k = r - l;

        if (k >= 2)
        {
            res += (k * (k - 1)) / 2;

        }
    }
    cout << res << endl;

    return 0;
}
