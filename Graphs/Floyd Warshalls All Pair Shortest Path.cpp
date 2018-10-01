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

int parent[N][N], dist[N][N];

int main()
{
	freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m;
	int u, v, w;

	memset(dist, 0, sizeof(dist));
	for (i = 0; i < N; i++)
		fill(dist[i], dist[i] + N, inf);

	sff(n, m);
	for (i = 0; i < m; i++)
	{
		sff(u, v); sf(w);

		//there maybe multiple edges
		dist[u][v] = min(dist[u][v], w);
		dist[v][u] = min(dist[v][u], w);
	}

	//Floyd_Warshall
	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					parent[i][j] = parent[k][j];
				}
			}
		}
	}

	return 0;
}
