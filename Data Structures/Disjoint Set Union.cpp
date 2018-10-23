/*****from dust i have come, dust i will be*****/

#include<bits/stdc++.h>

#define dbg printf("in\n");
#define nl printf("\n");

using namespace std;

class DisjointSetUnion
{
	int n;
	int *p, *r;
public:
	DisjointSetUnion(int n)
	{
		this->n = n;
		p = new int[n + 1];
		r = new int[n + 1];

		for (int i = 0; i <= n; i++)
			r[i] = 1, p[i] = i;
	}

	void Union(int a,int b)
	{
		int x = Find(a);
		int y = Find(b);

		if (r[x] > r[y])
		{
			p[y] = x;
			r[x] += r[y];
		}

		else
		{
			p[x] = y;
			r[y] += r[x];
		}
	}

	int Find(int x)
	{
		if (p[x] == x)
			return x;

		return p[x] = Find(p[x]);
	}
};

int main()
{
    freopen("in.txt","r",stdin);

    int i,j,k;
    int n,m;

    DisjointSetUnion dsu(n);

    return 0;
}
