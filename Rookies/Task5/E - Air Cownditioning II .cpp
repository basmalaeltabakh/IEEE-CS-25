#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int MinAmount(int i, int currentCost, vector<int>& cowCooling, vector<int>& currentCooling, vector<vector<int>>& AC) {

    if (i == AC.size()) {

        for (int j = 0; j < cowCooling.size(); j++) {
            if (cowCooling[j] > currentCooling[j]) return INT_MAX;
        }
        return currentCost;
    }

    int skipCurrentAC = MinAmount(i + 1, currentCost, cowCooling, currentCooling, AC);

    vector<int> coolingAfterUsingAC(currentCooling);
    for (int j = AC[i][0]; j <= AC[i][1]; j++) {
        coolingAfterUsingAC[j] += AC[i][2];
    }
    int useCurrentAC = MinAmount(i + 1, currentCost + AC[i][3], cowCooling, coolingAfterUsingAC, AC);
    return min(useCurrentAC, skipCurrentAC);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> cowCooling(101, 0), currentCooling(101, 0);
    for (int i = 0; i < N; i++) {
        int startStall, endStall, requiredCooling;
        cin >> startStall >> endStall >> requiredCooling;
        for (int j = startStall; j <= endStall; j++) {
            cowCooling[j] = max(cowCooling[j], requiredCooling);
        }
    }
    vector<vector<int>> AC(M, vector<int>(4));
    for (int i = 0; i < M; i++) {
        cin >> AC[i][0] >> AC[i][1] >> AC[i][2] >> AC[i][3];
    }
    int result = MinAmount(0, 0, cowCooling, currentCooling, AC);
    cout << (result == INT_MAX ? -1 : result) << endl;


    return 0;
}
