/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n")
#define nl printf("\n")
#define N 101010
#define inf 10000

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

int dp[N][17], parent[N], level[N];
vector<int> adj[N];

void dfs(int s, int lvl)
{
    level[s] = lvl;
    for(int e : adj[s])
    {
        if(e != parent[s])
            parent[e] = s, dfs(e, lvl + 1);
    }
}

void preCalc(int n)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 17; j++)
            dp[i][j] = -1;
    }

    // at 2 ^ 0 = 1 we store the actual parent
    for(int i = 1; i <= n; i++)
        dp[i][0] = parent[i];

    for(int h = 1; h < 17; h++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(dp[i][h - 1] != -1)
                dp[i][h] = dp[dp[i][h - 1]][h - 1];
        }
    }
}

int get_Kth_Ancestor(int node, int k)
{
    int ans = node;
    for(int i = 0; i < 17; i++)
    {
        // if 1 then we jump to ith parent of the node
        if(k & (1 << i))
            ans = dp[ans][i];

        if(ans == -1)
            break;
    }

    return ans;
}

int getLCA(int u, int v)
{
    // bring them in the same level
    if(level[u] < level[v])
        v = get_Kth_Ancestor(v, level[v] - level[u]);

    else if(level[v] < level[u])
        u = get_Kth_Ancestor(u, level[u] - level[v]);

    // u could be ancestor of v or vice versa
    // so leveling up them would cause the following if
    if(u == v)
        return u;

    int p = 0;
    while((1 << p) <= level[u])
        p++;

    for(int i = p; i >= 0; i--)
    {
        if(dp[u][i] != dp[v][i])
        {
            u = dp[u][i];
            v = dp[v][i];
        }
    }

    return dp[u][0];
}

int main()
{
    freopen("in.txt", "r", stdin);

    int i, j, k;
    int n, m, t;
    int u, v;

    sff(n, m);
    for(i = 1; i <= m; i++)
    {
        sff(u, v);

        adj[u].pb(v);
        adj[v].pb(u);
    }

    parent[1] = -1;
    dfs(1, 0);
    preCalc(n);

    cout << getLCA(2, 3);

    return 0;
}

/*
n, m
then m lines follows, each pair has an edge between them
22 21
1 2
2 4
4 8
8 12
12 16
12 17
2 5
1 3
3 6
6 9
9 13
9 20
20 18
18 14
18 21
3 7
7 10
7 11
11 15
15 19
19 22
*/
