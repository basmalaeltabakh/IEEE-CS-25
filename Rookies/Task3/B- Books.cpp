#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, free;
    cin >> n >> free;
    vector<ll>books(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> books[i];
    }
    ll start = 0, maxBooks = 0, current = 0;

    for (ll end = 0; end < n; end++)
    {
        current += books[end];
        while (current > free)
        {
            current -= books[start];
            start++;
        }
        maxBooks = max(maxBooks, end - start + 1);
    }

    cout << maxBooks << endl;
    return 0;
}
