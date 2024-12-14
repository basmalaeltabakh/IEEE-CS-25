#include <iostream>
#include <bits/stdc++.h>
#define  ll long long
using namespace std;

ll MinDiference(ll x, ll group1, ll group2, const vector<ll>& weights) {
    if (x == weights.size()) {
        return abs(group1 - group2);
    }
    ll Group1 = MinDiference(x + 1, group1, group2 + weights[x], weights);
    ll Group2 = MinDiference(x + 1, group1 + weights[x], group2, weights);
    return min(Group1, Group2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    vector<ll> weights(n);
    for (ll i = 0; i < n; i++) {
        cin >> weights[i];
    }

    ll MinDif = MinDiference(0, 0, 0, weights);
    cout << MinDif << endl;

    return 0;
}
