#include "bits/stdc++.h"
using namespace std;
const int MOD = 1e9 + 7;
const double PI = acos(-1);
typedef long long ll;
typedef unsigned long long ull;
#define FAST                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
vector<ll> pre_fun(string s)
{
    ll n = s.size(), i, j;
    vector<ll> p(n, 0);
    for (i = 1; i < n; i++)
    {
        j = p[i - 1];

        while (j > 0 && s[i] != s[j])
            j = p[j - 1];

        if (s[i] == s[j])
            j++;
        p[i] = j;
    }
    return p;
}

ll kmp(string target, string source)
{
    vector<ll> pre = pre_fun(target);
    ll count = 0, i = 0, j = 0;

    while (i < source.size())
    {
        if (target[j] == source[i])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
                j = pre[j - 1];
            else
                i++;
        }

        if (j == target.size())
        {
            count++;
            j = pre[j - 1];
        }
    }
    return count;
}

int main()
{
    FAST;
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string a, b;
        cin >> a >> b;

        ll ans = kmp(b, a);
        cout << "Case " << i << ": " << ans << endl;
    }
}
