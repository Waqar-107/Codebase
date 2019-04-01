/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n")
#define nl printf("\n");
#define N 200100

#define white 0
#define grey 1
#define black 2

using namespace std;

int color[N];
vector<int> adj[N];

void dfs(int s, int p)
{
    color[s] = grey;

    for(int e : adj[s])
    {
        if(e == p)continue;

        if(color[e] == black)
            continue;

        else if(color[e] == white)
            dfs(e, s);

        else if(color[e] == grey)
        {
            printf("cycle detected\n");
            exit(0);
        }
    }

    color[s] = black;
}

int main()
{
    freopen("in.txt", "r", stdin);

    int i,j,k;
    int n,m;
    int u,v;

    scanf("%d%d",&n,&m);

    memset(color,white,sizeof(color));
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    return 0;
}
