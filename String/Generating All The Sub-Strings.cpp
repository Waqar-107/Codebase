/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n");
#define nl printf("\n");
#define N 200138

using namespace std;

int main()
{
	//freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m, x;

	string s, t;

	s = "test";
	n = s.length();

	for (i = 0; i < n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			//substr(starting position,len)
			if (i + j<= n)
				t = s.substr(i, j), cout << t << endl;
		}
	}

	return 0;
}