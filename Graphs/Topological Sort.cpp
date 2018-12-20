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
#include<sstream>
#include<string>
#include<time.h>
#include<utility>
#include<vector>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n");
#define nl printf("\n");
#define N 310
#define inf 1000000

using namespace std;


vector<int> ans;
int color[N];
vector<int>adj[N];

void dfs(int s)
{
	if (!color[s])
	{
		color[s] = 1;

		for (int e : adj[s])
			dfs(e);

		color[s] = 2;
		ans.push_back(s);
	}

	//cycle found
	else if (color[s] == 1)
	{
		printf("cycle\n");
		exit(0);
	}
}

int main()
{
	freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m;
	int u, v;

	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &u, &v);

		//u depends on v
		adj[u].push_back(v);
	}

	memset(color, 0, sizeof(color));
	for (i = 1; i <= n; i++)
	{
		if (!color[i])
			dfs(i);
	}

	for (i = 0; i < n; i++)
		printf("%d ", ans[i]);

	return 0;
}
