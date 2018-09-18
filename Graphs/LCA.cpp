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
#define N 1100
#define inf 10000000

#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d ",n)
#define pff(n,m) printf("%d %d\n",n,m)
#define pffl(n,m) printf("%I64d %I64d\n",n,m)
#define pfl(n) printf("%I64d ",n)
#define pfs(s) printf("%s",s)

#define pb push_back
#define pp pair<int,int>

using namespace std;

int height[N];
int first[N], segTree[4 * N];
vector<int> adj[N];

class LCA
{
	int n;
	vector<int> euler;
public:
	
	LCA(int n)
	{
		this->n = n;

		euler.pb(-1);		 //in-order to make the vector one indexed
		dfs(1, -1, 1);
		
		height[0] = inf;	 //in query, when the range is out of query-range we return 0th node, so setting its height=inf
		build(1, 1, euler.size()-1);
	}

	//determines the euler path and the height of nodes
	//first[s] is for first occurance of node-s
	void dfs(int s, int p,int h)
	{
		height[s] = h;
		first[s] = euler.size();
		euler.pb(s);

		for (int e : adj[s])
		{
			if (e != p) {
				dfs(e, s, h + 1);
				euler.pb(s);
			}
		}
	}

	//for each node of the segment-tree, we keep track which vertex of the actual tree has the minimum value
	void build(int at, int l, int r)
	{
		if (l == r) {
			segTree[at] = euler[r];
			return;
		}

		int mid = (l + r) / 2;
		
		build(at * 2, l, mid);
		build(at * 2 + 1, mid + 1, r);

		int x = segTree[at * 2];
		int y = segTree[at * 2 + 1];

		if (height[x] <= height[y])
			segTree[at] = x;
		else
			segTree[at] = y;
	}

	int query(int at, int L, int R, int l, int r)
	{
		//we are now in the range L-R in the tree
		//we are given l-r as the query in the input

		//outta range
		if (r < L || R < l)
			return 0;

		//completely in the range
		if (l <= L && R <= r)
			return segTree[at];

		int mid = (L + R) / 2;

		int x = query(at * 2, L, mid, l, r);
		int y = query(at * 2 + 1, mid + 1, R, l, r);

		if (height[x] <= height[y])
			return x;

		else
			return y;
	}	

	int getLCA(int u, int v)
	{
		int l = first[u];
		int r = first[v];

		if (l > r)
			swap(l, r);

		return query(1, 1, euler.size() - 1, l, r);
	}
};

int main()
{
	//freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m;
	int u, v;

	sf(n);
	for (i = 0; i < n -1; i++)
	{
		sff(u, v);

		adj[u].pb(v);
		adj[v].pb(u);
	}

	LCA lca(n);

	int q; sf(q);
	while (q--)
	{
		sff(u, v);
		cout << lca.getLCA(u, v);nl
	}

	return 0;
}
