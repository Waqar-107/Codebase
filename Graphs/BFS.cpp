#define _CRT_SECURE_NO_WARNINGS

/***from dust i have come, dust i will be***/

#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n")
#define nl printf("\n");
#define N 350
#define inf 100000000

#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d ",n)
#define pff(n,m) printf("%d %d\n",n,m)
#define pffl(n,m) printf("%I64d %I64d\n",n,m)
#define pfl(n) printf("%I64d\n",n)
#define pfs(s) printf("%s",s)

#define pb push_back
#define pp pair<int,int>

using namespace std;

int parent[N], vis[N], dist[N];
vector<int> adj[N];

void bfs(int s)
{
	memset(parent, 0, sizeof(parent));
	memset(vis, 0, sizeof(vis));

	queue<int> q;
	q.push(s); dist[s] = 0; vis[s] = 1;

	while (!q.empty())
	{
		int u = q.front(); q.pop();

		for (int e : adj[u])
		{
			if (!vis[e])
			{
				dist[e] = dist[u] + 1;
				q.push(e);
				vis[e] = 1;
				parent[e] = u;
			}
		}
	}
}

int main()
{
	freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m;
	int u, v;



	return 0;
}
