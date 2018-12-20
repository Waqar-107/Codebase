/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

using namespace std;

bool vis[N];
int dp[N], h[N], diameter;
vector<int> adj[N];
vector<pp> vec;

//measure the height of the tree
int height(int s, int p)
{
	for (int e : adj[s])
	{
		if (e == p)continue;

		h[s] = max(h[s], height(e, s));
	}

	h[s]++;
	return h[s];
}

//measure the diameter of the tree 
int dfs(int s, int p)
{
	int mx1, mx2, mx_subtree;
	mx1 = mx2 = mx_subtree = 0;

	vis[s] = true;

	//mx1, mx2 furthest nodes in the subtree rooted t 's'
	for (int e : adj[s])
	{
		if (e == p)continue;

		if (mx1 < h[e])
			mx2 = mx1, mx1 = h[e];
		else
			mx2 = max(mx2, h[e]);
	}

	for (int e : adj[s])
	{
		if (e == p)continue;
		mx_subtree = max(mx_subtree, dfs(e, s));
	}

	//mx1+mx2+1 -> diameter when i am in the middle of the longest path 
	return max(mx_subtree, mx1 + mx2 + 1);
}

int main()
{
	return 0;
}
