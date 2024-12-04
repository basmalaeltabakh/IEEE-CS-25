#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll low = 1, high = 1e18, ans = -1;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll sum = 0;
        ll power = 1;
        while (mid / power > 0) {
            sum += mid / power;
            power *= k;
        }
        if (sum >= n) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
