/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n");
#define nl printf("\n");
#define N 1000

using namespace std;

vector<int> phi;
void eulers_totient(int n)
{
	phi.resize(n + 1);
	for (int i = 1; i <= n; i++)
		phi[i] = i;

	for (int p = 2; p <= n; p++)
	{
		//not computed and is prime
		if (phi[p] == p)
		{
			//phi of a prime p is (p-1)
			phi[p] = p - 1;

			//update all the multiples of p
			//p1^a1(1- 1/p1) * p2^a2(1-1/p2) ...
			//p1^a1/p1*(p1-1)...
			//phi[i]/p1*(p1-1)...
			for (int i = 2 * p; i <= n; i += p)
				phi[i] = (phi[i] / p)*(p - 1);
		}
	}
}

int main()
{
	//freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m;

	eulers_totient(20);
	for (i = 1; i <= 20; i++)
		cout << phi[i] << endl;

	return 0;
}
