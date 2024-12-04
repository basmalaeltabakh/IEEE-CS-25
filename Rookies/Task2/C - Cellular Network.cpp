#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cities, towers;
    cin >> cities >> towers;
    vector<ll>coCities(cities);
    vector<ll>coTowers(towers);
    for (ll i = 0; i < cities; i++)cin >> coCities[i];
    for (ll i = 0; i < towers; i++)cin >> coTowers[i];
    sort(coCities.begin(), coCities.end());
    sort(coTowers.begin(), coTowers.end());
    ll l = 0, r = 2e9, res = r;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        bool valid = true;
        int current = 0;
        for (int i = 0; i < cities; i++)
        {
            while (current < towers && coTowers[current] < coCities[i] - mid)
            {
                current++;
            }

            bool covered = false;
            if (current < towers && abs(coTowers[current] - coCities[i]) <= mid)
            {
                covered = true;
            }
            if (current > 0 && abs(coTowers[current - 1] - coCities[i]) <= mid)
            {
                covered = true;
            }
            if (!covered)
            {
                valid = false;
                break;
            }
        }
        if (valid)
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }

    }
    cout << res << endl;
    return 0;
}
