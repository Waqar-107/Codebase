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

ll modularInverse(ll a, ll m)
{
	/*
		if a and m are co-prime that is gcd(a,m)==1 then
			a^phi(m) % m =1
		=> a^{phi(m)-1} % m = a^-1
		if m is prime then phi(m) - 1 = m - 1 - 1 = m-2
		so a^-1 % m = a ^ m-2
	*/
	return bigMod(a, m - 2, m);
}

int main()
{
	//freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m;

	return 0;
}
