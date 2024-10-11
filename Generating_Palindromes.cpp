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

ll dp[105][105];
string ss;
ll cal(ll s, ll e)
{
    if (s >= e)
        return 0;
    if (dp[s][e] != -1)
        return dp[s][e];
    ll res = LLONG_MAX;
    if (ss[s] == ss[e])
        res = min(res, cal(s + 1, e - 1));
    else
        res = min(res, min(cal(s + 1, e) + 1, cal(s, e - 1) + 1));
    return dp[s][e] = res;
}

int main()
{
    FAST;
    int T;
    cin >> T;
    ll i, j, k;
    for (i = 1; i <= T; i++)
    {
        cin >> ss;
        ll n = ss.size();
        memset(dp, -1, sizeof(dp));
        cout << "Case " << i << ": " << cal(0, n - 1) << endl;
    }
    return 0;
}