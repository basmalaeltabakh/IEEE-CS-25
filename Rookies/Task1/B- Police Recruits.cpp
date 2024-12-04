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
    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int police = 0, unthreated = 0;

    for (int i = 0; i < n; i++) {
        if (c[i] > 0) {
            police += c[i];
        }
        else if (c[i] == -1) {
            if (police > 0) {
                police--;
            }
            else {
                unthreated++;
            }
        }
    }

    cout << unthreated << endl;
    return 0;
}
