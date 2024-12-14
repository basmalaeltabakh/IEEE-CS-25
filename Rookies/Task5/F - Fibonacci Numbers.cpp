#include<iostream>
#include <bits/stdc++.h>
#define long long ll
using namespace std;
int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return fib(n - 1) + fib(n - 2);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    cout << fib(n) << endl;
    return 0;
}
