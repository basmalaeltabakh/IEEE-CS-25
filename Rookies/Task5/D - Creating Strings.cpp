#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string strr;
    cin >> strr;

    sort(strr.begin(), strr.end());
    vector<string> permutations;
    while (true) {
        permutations.push_back(strr);
        if (!next_permutation(strr.begin(), strr.end())) {
            break;
        }
    }

    cout << permutations.size() << endl;
    for (int i = 0; i < permutations.size(); ++i) {
        cout << permutations[i] << endl;
    }

    return 0;
}
