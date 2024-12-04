#include <iostream>
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char m; cin >> m;
    string message; cin >> message;
    string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";

    string orginal = "";

    if (m == 'R') {

        for (char c : message) {
            int i = keyboard.find(c);
            orginal += keyboard[i - 1];
        }
    }
    else if (m == 'L') {
        for (char c : message) {
            int i = keyboard.find(c);
            orginal += keyboard[i + 1];
        }
    }
    cout << orginal << endl;
    return 0;
}
