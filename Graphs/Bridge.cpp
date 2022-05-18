/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n")
#define nl printf("\n")
#define N 10101
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
#define pp pair<int, int>

using namespace std;

class Graph
{
    int n, time;
    vector<vector<int>> adj;
    vector<pp> answer;

    void bridgeUtil(int current, int parent, vector<bool> &visited, vector<int> &discoveryTime, vector<int> &low)
    {
        visited[current] = true;
        discoveryTime[current] = time;
        low[current] = time;

        time++;

        for(int e : adj[current])
        {
            if(!visited[e])
            {
                bridgeUtil(e, current, visited, discoveryTime, low);

                // now parent will see if they can disconnect the edge between them and the child
                // if the child has any adjacent node other than the parent whose discovery time is less than parents discovery time
                // then we can safely assume that the child can be reached out using that node instead of using the parent node
                // thus the edge between the parent and the child is not a bridge
                low[current] = min(low[current], low[e]);
                if(low[e] > discoveryTime[current])
                    answer.pb({ current, e});
            }

            else if(e != parent)
                low[current] = min(low[current], discoveryTime[e]);
        }
    }
public:
    Graph(int n)
    {
        this->n = n;
        adj.resize(n + 1);      // keeping this 1 indexed
    }

    void addEdge(int u, int v)
    {
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<pp> bridge()
    {
        vector<bool> visited(n + 1, false);
        vector<int> discoveryTime(n + 1);
        vector<int> low(n + 1);

        time = 1;
        answer.clear();

        for(int i = 1; i <= n; i++)
        {
            if(!visited[i])
                bridgeUtil(i, -1, visited, discoveryTime, low);
        }

        return answer;
    }
};

int main()
{
    freopen("in.txt", "r", stdin);

    int i, j, k;
    int n, m, t;
    int u, v;

    cin >> n >> m;

    Graph g(n);
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        g.addEdge(u, v);
    }

    vector<pp> ans = g.bridge();
    for(pp e : ans)
        cout << e.first << " " << e.second << endl;

    return 0;
}

/*
15 21
1 2
1 3
2 3
2 5
2 6
3 4
3 7
3 8
4 5
4 6
6 7
8 9
8 10
9 10
9 11
10 12
11 12
11 13
13 14
13 15
14 15
*/
