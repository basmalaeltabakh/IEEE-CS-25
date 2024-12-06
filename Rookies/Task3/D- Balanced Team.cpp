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
    vector<int> students(n);
    for (int i = 0;i < n;i++)cin >> students[i];
    int Maxcounter = 0;
    sort(students.begin(), students.end());
    int l = 0, r = n - 1;
    for (int r = 0;r < n;r++) {
        {
            while (students[r] - students[l] > 5)
                l++;
        }
        Maxcounter = max(Maxcounter, r - l + 1);
    }
    cout << Maxcounter << endl;
    return 0;
}
