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

bool bfs(int s)
{
    memset(vis,0,sizeof(vis));
    memset(color,-1,sizeof(color));

    queue<int> q;

    q.push(s);
    color[s]=1;
    vis[s]=1;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int e : adj[u])
        {
            //self loop
            if(e==u)
                return false;

            //non-visited node
            if(color[e]==-1)
            {
                if(color[u]==1)
                    color[e]=2;
                else
                    color[e]=1;

                q.push(e);
            }

            //if visited, then is the color different??
            else
            {
                if(color[u]!=color[e])
                    continue;
                else
                    return false;
            }
        }
    }
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

    if(bfs(1))
        cout<<"Bipartite"<<endl;
    else
        cout<<"Not Bipartite"<<endl;

    return 0;
}
