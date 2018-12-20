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
#define N 100005
#define inf 100000000
#define pp pair<int,int>

using namespace std;

class graph
{
	int n, m, t;
	int **res, **capacity, *parent;
	bool *vis;

public:
	graph(int n, int m)
	{
		this->n = n;
		this->m = m;

		t = n + m + 2;

		//residual capacity
		res = new int*[t];
		for (int i = 0; i < t; i++)
			res[i] = new int[t];


		//capacity
		capacity = new int*[t];
		for (int i = 0; i < t; i++)
			capacity[i] = new int[t];

		for (int i = 0; i < t; i++)
		{
			for (int j = 0; j < t; j++)
				capacity[i][j] = 0;
		}


		//parent
		parent = new int[t];


		//visited or not
		vis = new bool[t];
	}

	void addEdge(int u, int v)
	{
		capacity[0][u] = 1;
		capacity[u][v + n] = 1;
		capacity[v + n][t - 1] = 1;
	}

	bool bfs()
	{
		for (int i = 0; i <t; i++)
			vis[i] = 0;

		queue<int> q;

		vis[0] = 1;
		q.push(0);
		parent[0] = -1;

		while (!q.empty())
		{
			int u = q.front();
			q.pop();

			for (int v = 0; v <t; v++)
			{
				if (!vis[v] && res[u][v] > 0)
				{
					parent[v] = u;
					vis[v] = 1;
					q.push(v);
				}
			}
		}

		return vis[t-1];
	}

	int fordFulkerson()
	{
		//initially residual capacity is equal to the actual capacity
		for (int i = 0; i <t; i++)
		{
			for (int j = 0; j <t; j++)
				res[i][j] = capacity[i][j];
		}

		int flow = 0;
		int minFlow;
		int u, v;
		
		//augmenting the path to s to t while it is possible
		while (bfs())
		{
			minFlow = 1;
			//update residual capacity
			v = t-1;
			while (1)
			{
				u = parent[v];
				res[u][v] -= minFlow;
				res[v][u] += minFlow; 
				cout << u << " " << v << endl;
				v = u;

				if (v == 0)
					break;
			}

			//update flow
			flow += minFlow;
		}

		return flow;
	}
};

int main()
{
	//freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m;
	int s, t;
	int u, v, e;

	scanf("%d%d%d", &n, &m, &e);

	graph g(n, m);

	for (i = 0; i < e; i++)
	{
		scanf("%d%d", &u, &v);
		g.addEdge(u, v);
	}

	cout << g.fordFulkerson() << endl;

	return 0;
}
