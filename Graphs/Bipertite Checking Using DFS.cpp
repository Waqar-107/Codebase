/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;

#define dbg printf("in\n");
#define nl printf("\n");
#define pp pair<int,int>
#define N 1000

using namespace std;

int color[N];
bool vis[N];
vector<int> adj[N];

bool dfs(int s)
{
    bool f=true;
    vis[s]=1;

    for(int e : adj[s])
    {
        if(!vis[e])
        {
            if(color[s]==1)
                color[e]=2;
            else
                color[e]=1;

            f=dfs(e);
        }

        else
        {
            if(color[e]==color[s])
                return false;
        }
    }

    return f;
}

int main()
{
    //freopen("in.txt","r",stdin);

    int i,j,k;
    int n,u,v,m;

    //n nodes, m edges
    cin>>n>>m;

    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(vis,0,sizeof(vis));
    memset(color,-1,sizeof(color));

    color[1]=1;

    if(dfs(1))
        cout<<"Bipartite"<<endl;
    else
        cout<<"Not Bipartite"<<endl;

    return 0;
}
