#define _CRT_SECURE_NO_WARNINGS

/***from dust i have come, dust i will be***/

#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<functional>
#include<iomanip>
#include<iostream>
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

#define dbg printf("in\n");
#define nl printf("\n");
#define N 100010

using namespace std;

bool vis[N];
vector<int> adj[N];
vector<int> adj2[N];
stack<int> st;

void dfs(int s)
{
	vis[s] = 1;
	for (int i = 0; i < adj[s].size(); i++)
	{
		int u = adj[s][i];
		if (!vis[u])
			dfs(u);
	}

	st.push(s);
}

void dfs2(int s)
{
	vis[s] = 1;
	printf("%d ", s);

	for (int i = 0; i < adj2[s].size(); i++)
	{
		int u = adj2[s][i];
		if (!vis[u])
			dfs2(u);
	}
}

int main()
{
	freopen("in2.txt","r",stdin);

	int i, j, k;
	int n, m;
	int u, v;

	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &u, &v);

		adj[u].push_back(v);
		adj2[v].push_back(u); 	//reverse graph
	}

	memset(vis, 0, sizeof(vis));

	for (i = 1; i <= n; i++)
	{
		if (!vis[i])
			dfs(i);
	}

	memset(vis, 0, sizeof(vis));
	while (st.size())
	{
		if (!vis[st.top()]) {
			dfs2(st.top());
			printf("\n");
		}

		st.pop();
	}

	return 0;
}
