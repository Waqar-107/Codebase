/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;

#define dbg printf("in\n");
#define nl printf("\n");
#define inf 1000000000000

using namespace std;

//-------------------------------------------------------------------vertex or node
struct node
{
    ll at,cost;
    node(ll a, ll c)
    {
        at=a;
        cost=c;
    }
};
//-------------------------------------------------------------------vertex or node


//-------------------------------------------------------------------edge between u and v weighed w
struct edge
{
    ll v,w;
    edge(ll a,ll b)
    {
        v=a;
        w=b;
    }
};
//-------------------------------------------------------------------edge between u and v weighed w

bool operator<(node a, node b)
{
    return a.cost>b.cost;
}

class Graph
{
    ll *parent,nodes;
    ll *dist;
    bool *vis;bool dir;
    vector<edge> *adj;
    priority_queue<node> pq;

public:
    Graph(ll n,bool f)
    {
        nodes=n;
        parent=new ll[n+1];
        dist=new ll[n+1];
        vis=new bool[n+1];
        adj=new vector<edge>[n+1];
        dir=f;
    }

    void addEdge(ll u,ll v,ll w)
    {
        adj[u].push_back(edge(v,w));

        if(!dir)
            adj[v].push_back(edge(u,w));
    }

    void dijkstra(ll s)
    {
        for(ll i=1;i<=nodes;i++)
            dist[i]=inf,vis[i]=0,parent[i]=-1;

        pq.push(node(s,0));
        dist[s]=0;

        while(!pq.empty())
        {
            node u=pq.top();
            pq.pop();

            if(vis[u.at])
                continue;

            for(edge e : adj[u.at])
            {
                if(!vis[e.v] && dist[e.v]>dist[u.at]+e.w)
                {
                    dist[e.v]=dist[u.at]+e.w;
                    pq.push(node(e.v,dist[e.v]));

                    parent[e.v]=u.at;
                }
            }

            vis[u.at]=1;
        }
    }

    void print()
    {
        cout<<"shortest paths from the source"<<endl;
        for(ll i=1;i<=nodes;i++)
            cout<<i<<"  "<<dist[i]<<endl;
    }
};


int main()
{
    freopen("in.txt","r",stdin);

    ll i,j,k;
    ll n,m;
    ll u,v,d;

    scanf("%I64d%I64d",&n,&m);

    Graph g(n,0);

    for(i=0;i<m;i++)
    {
        scanf("%I64d%I64d%I64d",&u,&v,&d);
        g.addEdge(u,v,d);
    }

    //taking 0 as source
    g.dijkstra(1);
    g.print();

    return 0;
}
