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

#define pb push_back
#define pp pair<ll,int>

using namespace std;

ll compute_hash(string s)
{
	const int p = 31;
	const int m = 1e9 + 9;

	ll hash_value = 0;
	ll p_pow = 1;

	for (char ch : s)
	{
		hash_value = (hash_value + (ch - 'a' + 1)*p_pow) % m;
		p_pow = (p_pow*p) % m;
	}

	return hash_value;
}

vector<string> str;
vector<vector<int>> ans;

void group_identical_strings()
{
	int i, j, k;
	int n = str.size();
	
	vector<pp> hashes(n);

	for (i = 0; i < n; i++)
		hashes[i] = { compute_hash(str[i]),i };

	sort(hashes.begin(), hashes.end());

	for (i = 0; i < n; i++) {
		if (i == 0 || hashes[i].first != hashes[i - 1].first)
			ans.emplace_back();

		ans.back().pb(hashes[i].second);
	}
}

int main()
{
	freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m;
	
	str.pb("s"); str.pb("s");
	str.pb("w");
	
	group_identical_strings();

	n = ans.size();
	for (i = 0; i < n; i++)
	{
		for (int e : ans[i])
			cout << str[e] << " ";
		nl
	}

	return 0;
}
