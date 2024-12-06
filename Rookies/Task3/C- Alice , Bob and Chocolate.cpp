#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    int l = 0, r = n - 1;
    int aliceTime = 0, bobTime = 0;
    int aliceCount = 0, bobCount = 0;

    while (l <= r) {
        if (aliceTime <= bobTime) {
            aliceTime += t[l];
            l++;
            aliceCount++;
        }
        else {
            bobTime += t[r];
            r--;
            bobCount++;
        }
    }

    cout << aliceCount << " " << bobCount << "\n";
    return 0;
}
