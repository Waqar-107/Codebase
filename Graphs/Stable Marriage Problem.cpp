
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
#define pp pair<int,int>
#define N 550

using namespace std;

//ranking[][] gives the rank of each woman in perspective of a man, rank[w][m]=i if womanPreffered[m][i]=w
//nxt[] tracks the next woman to propose

int wife[N], husband[N], nxt[N];
int menPrefference[N][N], womenPrefference[N][N], ranking[N][N];

void stable_marriage()
{
	int i, j, k;
	int n, m, w;

	scanf("%d", &n);

	//take menPrefference - the order of women, a man wants
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &m); m -= n;	//n+1 to 2n in the input
			menPrefference[i][j] = m;
		}
	}

	//take womenPrefference  - the order of men, an woman wants
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &w);
			womenPrefference[i][j] = w;
		}
	}

	//ranking of man perspective of a woman
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			ranking[i][womenPrefference[i][j]] = j;
	}

	queue<int> q;
	for (i = 1; i <= n; i++)
		q.push(i);

	fill(nxt, nxt + N, 1);
	fill(wife, wife + N, 0);
	fill(husband, husband + N, 0);

	//queue of men
	while (!q.empty())
	{
		m = q.front();
		w = menPrefference[m][nxt[m]];

		//w is single ;)
		if (husband[w] == 0)
		{
			wife[m] = w;
			husband[w] = m;
			q.pop();
		}

		else if(ranking[w][m] < ranking[w][husband[w]])
		{
			int curr = husband[w];

			q.pop();
			q.push(curr);

			wife[m] = w;
			wife[curr] = 0;
			husband[w] = m;
		}

		nxt[m]++;
	}

	for (i = 1; i <= n; i++)
		printf(" (%d %d)", i, wife[i] + n);
}

int main()
{
	freopen("in2.txt","r",stdin);

	int i, j, k;
	int t;

	scanf("%d", &t);

	//men=company, women=employee in this particular problem
	for (int c = 1; c <= t; c++)
	{
		printf("Case %d:", c);

		stable_marriage();
		printf("\n");
	}

	return 0;
}
