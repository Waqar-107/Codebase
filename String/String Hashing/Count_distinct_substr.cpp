/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n")
#define nl printf("\n")
#define N 100100
#define inf 1e9

#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d",n)
#define pff(n,m) printf("%d %d",n,m)
#define pffl(n,m) printf("%I64d %I64d",n,m)
#define pfl(n) printf("%I64d",n)
#define pfs(s) printf("%s",s)

#define pb push_back
#define pp pair<ll, ll>

using namespace std;

int count_unique_substr(string s)
{
    int n = s.length();

    const int p = 31;
    const int mod = 1e9 + 9;

    vector<ll> p_pow(n);

    p_pow[0] = 1;
    for(int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i - 1] * p) % mod;

    vector<ll> h(n + 1, 0);
    for(int i = 0; i < n; i++)
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % mod;

    int cnt = 0;
    for(int l = 1; l <= n; l++)
    {
        set<ll> hs;
        for(int i = 0; i <= n - l; i++)
        {
            ll cur = (h[i + 1] + mod - h[i]) % mod;
            cur = (cur * p_pow[n - i - 1]) % mod;

            hs.insert(cur);
        }

        cnt += hs.size();
    }

    return cnt;
}

int main()
{
    // freopen("in.txt", "r", stdin);

    int i, j, k;
    int n, m, t;

    return 0;
}
