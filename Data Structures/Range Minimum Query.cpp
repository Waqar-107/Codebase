/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n")
#define nl printf("\n")
#define N 1000
#define inf 1e9
#define mod 100000007

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
#define pp pair<int, int>

using namespace std;

int a[N], segTree[4 * N];

void build(int at, int l, int r)
{
    if(l == r)
    {
        segTree[at] = a[l];
        return;
    }

    int mid = (l + r) / 2;

    build(at * 2, l, mid);
    build(at *2 + 1, mid + 1, r);

    int x = segTree[at * 2];
    int y = segTree[at * 2 + 1];

    segTree[at] = min(x, y);
}

// we are now in the range L-R in the tree
// we are given l-r as the query in the input
int query(int at, int L, int R, int l, int r)
{
    // out of range
    if(r < L || R < l)return inf;

    // completely in range
    if(l <= L && R <= r)
        return segTree[at];

    int mid = (L + R) / 2;
    int x = query(at * 2, L, mid, l, r);
    int y = query(at * 2 + 1, mid + 1, R, l, r);

    return min(x, y);
}

int main()
{
    freopen("in.txt", "r", stdin);

    int i, j, k;
    int n, m, q;
    int l, r;

    sf(n);
    for(i = 1; i <= n; i++)
        sf(a[i]);

    build(1, 1, n);

    sf(q);
    while(q--)
    {
        sff(l, r);
        cout << query(1, 1, n, l, r) << endl;
    }

    return 0;
}
