
#include <iostream>
using namespace std;
#define ll long long 
ll weirdAlg(ll n)
{
    cout << n << " ";
    if (n == 1) return 1;
    else if (n % 2 == 0)
        return weirdAlg(n / 2);

    else if (n % 2 != 0)
        return  weirdAlg(3 * n + 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n; cin >> n;
    weirdAlg(n);
    return 0;
}