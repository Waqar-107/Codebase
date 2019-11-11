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

using namespace std;

ll compute_hash(string s)
{
	const int p = 31;
	const ll m = 72727272727272727;

	ll hash_value = 0;
	ll p_pow = 1;

	for (char ch : s)
	{
		hash_value = (hash_value + (ch - 'a' + 1)*p_pow) % m;
		p_pow = (p_pow*p) % m;
	}

	return hash_value;
}

int main()
{
	freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m;
	

	return 0;
}
