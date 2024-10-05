#include "bits/stdc++.h"
using namespace std;
const int MOD = 1000003;
const double PI = acos(-1);
typedef long long ll;
typedef unsigned long long ull;
#define SetBit(x, k) (x |= (1ll << k))
#define ClearBit(x, k) (x &= ~(1ll << k))
#define CheckBit(x, k) ((x >> k) & 1)
#define toggleBit(x, k) (x ^ (1ll << k))
ll bigmod(ll a, ll b, ll mod)
{
    ll res = 1;
    a %= mod;
    while (b > 0)
    {
        if (b & 1)
            res = ((res % mod) * (a % mod)) % mod;
        a = ((a % mod) * (a % mod)) % mod;
        b >>= 1;
    }
    return res;
}

#define FAST                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
ll fac[1000003LL];

int main()
{
    FAST;

    fac[0] = 1LL;
    ll i, j;
    for (i = 1; i < MOD; i++)
    {
        fac[i] = ((fac[i - 1] % MOD) * (i % MOD)) % MOD;
    }
    int T;
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        ll n, r;
        cin >> n >> r;
        ll low = ((fac[r] % MOD) * (fac[n - r] % MOD)) % MOD;
        ll hi = fac[n] % MOD;
        ll ans = bigmod(low, MOD - 2, MOD);
        ans = ((hi % MOD) * (ans % MOD)) % MOD;
        cout << "Case " << i << ": " << ans << endl;
    }
    return 0;
}