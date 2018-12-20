/***from dust i have come, dust i will be***/

/****************************************************************
Kruskal's algorithm of Minimum Spanning Tree

algorithm:

1. sort the edges in increasing order

2. make set for each nodes

3. iterate over all the edges, if u and v is in different sets, make union and add
to the result, use "find" to determine if they are in the same set

4. The edges in the result is the edges that forms the MST

****************************************************************/

#include<bits/stdc++.h>

#define dbg printf("in\n");
#define nl printf("\n");

using namespace std;

struct edge
{
    int u,v,w;

    edge(){}
    edge(int x,int y,int z)
    {
        u=x;v=y;w=z;
    }
};

class DisjointSetUnion
{
    int n;
    int *p,*r;

public:
    DisjointSetUnion(int x)
    {
        n=x;

        p=new int[n+1];
        r=new int[n+1];

        for(int i=1;i<=n;i++)
            p[i]=i;

        memset(r,0,sizeof(r));
    }

    void Union(int x,int y)
    {
        int a=p[x];
        int b=p[y];

        if(r[a]>r[b])
        {
            p[b]=a;
            r[a]=max(r[a],r[b]+1);
        }

        else
        {
            p[a]=b;
            r[b]=max(r[b],r[b]+1);
        }
    }

    int Find(int a)
    {
        if(p[a]==a)
            return a;

        return p[a]=Find(p[a]);
    }
};

bool cmp(edge u,edge v)
{
    return u.w<v.w;
}

int main()
{
    freopen("in.txt","r",stdin);

    int i,j,k;
    int n,m;
    int u,v,w;

    cin>>n>>m;

    DisjointSetUnion dsu(n);

    edge a[m];
    for(i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        a[i]=edge(u,v,w);
    }

    sort(a,a+m,cmp);

    int sum=0;
    for(i=0;i<m;i++)
    {

        if(dsu.Find(a[i].u)!=dsu.Find(a[i].v))
        {
            sum+=a[i].w;
            dsu.Union(a[i].u,a[i].v);

            cout<<a[i].u<<" "<<a[i].v<<endl;
        }
    }

    cout<<sum;

    return 0;
}
