/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n");
#define nl printf("\n");
#define N 1010

using namespace std;

ll bigMod(ll a, ll p, ll m)
{
	//a ^ 0 = 1
	if (p == 0)
		return 1;

	//odd
	if (p & 1)
	{
		//a^p = a * a^{p-1}
		return ((a%m)*bigMod(a, p - 1, m)) % m;
	}

	ll temp = bigMod(a, p / 2, m);
	return (temp*temp) % m;
}

int main()
{
	//freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m;



	return 0;
}
