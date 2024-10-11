#include "bits/stdc++.h"
using namespace std;
const int MOD = 1e9 + 7;
const double PI = acos(-1);
typedef long long ll;
typedef unsigned long long ull;
#define SetBit(x, k) (x |= (1ll << k))
#define ClearBit(x, k) (x &= ~(1ll << k))
#define CheckBit(x, k) ((x >> k) & 1)
#define toggleBit(x, k) (x ^ (1ll << k))
#define FAST                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
int main()
{
    FAST;
    int T;
    cin >> T;
    for (ll p = 1; p <= T; p++)
    {
        ll n, i, j;
        cin >> n;
        vector<ll> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll maxa = a[0];
        for (i = 0; i < n - 1; i++)
            maxa = max(maxa, a[i + 1] - a[i]);
        bool yes = false;
        ll k = maxa;
        if (a[0] == k)
            k--;
        for (i = 1; i < n; i++)
        {
            ll diff = a[i] - a[i - 1];
            if (diff > k)
            {
                yes = true;
                break;
            }
            else if (diff == k)
                k--;
        }
        if (yes)
            maxa++;

        cout << "Case " << p << ": " << maxa << endl;
    }
    return 0;
}