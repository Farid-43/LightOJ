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

ll lcm(ll a, ll b)
{
    return a / __gcd(a, b) * b;
}

void uttor()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> lst(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> lst[i];
    }

    ll cnt = 0;

    // Using bitwise operations to calculate inclusion-exclusion
    for (ll i = 1; i < (1 << m); i++)
    {
        vector<ll> bitCount;

        // Find all the set bits in i
        for (ll j = 0; j < m; j++)
        {
            if (CheckBit(i, j))
            {
                bitCount.push_back(lst[j]);
            }
        }

        ll ab = bitCount[0];

        for (auto x : bitCount)
        {
            ab = lcm(ab, x);
        }

        // Apply inclusion-exclusion principle
        if (bitCount.size() & 1)
        {
            cnt += (n / ab); // Add if odd count of set bits
        }
        else
        {
            cnt -= (n / ab); // Subtract if even count of set bits
        }
    }
    // cnt = number of numbers that is divisible by M array.
    cout << n - cnt << endl;
}

int main()
{
    FAST;
    int T;
    cin >> T;
    for (ll i = 1; i <= T; i++)
    {
        cout << "Case " << i << ": ";
        uttor();
    }
    return 0;
}
