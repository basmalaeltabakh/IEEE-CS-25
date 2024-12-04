#include <iostream>
#include <bits/stdc++.h>
#define ll  long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int shops; cin >> shops;
    vector<int>prices(shops);
    for (int i = 0;i < shops;i++)
    {
        cin >> prices[i];
    }
    sort(prices.begin(), prices.end());
    ll days; cin >> days;
    vector<ll>res(days);
    for (int i = 0;i < days;i++)
    {
        ll coins; cin >> coins;
        int counter = upper_bound(prices.begin(), prices.end(), coins) - prices.begin();
        res[i] = counter;
    }
    for (auto result : res)
        cout << result << endl;

    return 0;
}
