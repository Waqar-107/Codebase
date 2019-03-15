/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n")
#define nl printf("\n")
#define N 510
#define inf 1e6

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

ll a[N][N];

ll nCr(int n, int r)
{
    if(a[n][r] != -1)
        return a[n][r];

    if(n == r)
        a[n][r] = 1;

    else if(r == 1)
        a[n][r] = n;

    else
        a[n][r] = nCr(n -1, r - 1) + nCr(n - 1, r);

    return a[n][r];
}

int main()
{
    freopen("in.txt", "r", stdin);

    int i, j, k;
    int n, m;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
            a[i][j] = -1;
    }

    cout<<nCr(4,2);


    return 0;
}
