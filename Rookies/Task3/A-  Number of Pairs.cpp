#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        vector<ll>a(n);
        for (int i = 0; i < n; i++)cin >> a[i];
        sort(a.begin(), a.end());
        ll counter = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int left = i + 1, right = n - 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (a[i] + a[mid] >= l)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            int low = left;

            left = i + 1, right = n - 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (a[i] + a[mid] <= r)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            int high = right;

            if (low <= high)
            {
                counter += (high - low + 1);
            }
        }

        cout << counter << "\n";
    }



    return 0;
}
