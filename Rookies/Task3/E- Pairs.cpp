#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll target;
    cin >> n >> target;
    vector<ll>a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll l = 0, r = 0, counter = 0;
    while (r < n)
    {

        if ((a[r] - a[l]) == target)
        {
            counter++;
            r++;
            l++;
        }
        else if ((a[r] - a[l]) < target)
        {
            r++;
        }
        else
        {
            l++;
        }
    }
    cout << counter << endl;
    return 0;
}
