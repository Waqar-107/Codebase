/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n");
#define nl printf("\n");
#define N 100100

using namespace std;

/*
	ax + by = gcd(a, b); ------(1)

	b%a = b - floor(b / a)*a

	now assuming(x1, y1) coeff for (b%a, a)
	g = (b%a)*x1 + ay1
	   = (b - floor(b / a)*a)*x1 + ay1
	   = bx1 + a(y1 - floor(b / a)x1) -----(2)

	comparing (2) with (1),

	x = (y1 - floor(b / a)x1)
	y = x1
*/

int gcd(int a, int b, int &x, int &y)
{
	if (!a)
	{
		x = 0, y = 1;
		return b;
	}

	int x1, y1;
	int d = gcd(b%a, a, x1, y1);

	x = y1 - (b / a)*x1;
	y = x1;

	return d;
}

int main()
{
	//freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m;


	return 0;
}
