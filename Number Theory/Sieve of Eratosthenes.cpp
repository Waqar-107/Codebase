/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

#define dbg printf("in\n")
#define nl printf("\n")
#define N 1000

using namespace std;

bool status[N];
vector<int> primes;

void sieve_of_eratosthenes()
{
	int sq = sqrtl(N * 1.0);

	memset(status, 0, sizeof(status));

	status[0] = status[1] = 1;

	//all the evens except 2 is composite
	for (int i = 4; i < N; i += 2)
		status[i] = 1;

	for (int i = 3; i <= sq; i+=2)
	{
		if (!status[i])
		{
			//i is prime so its multipliers are not
			for (int j = i * i; j < N; j += i + i)
				status[j] = 1;
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (!status[i])
			primes.push_back(i);
	}
}

int main()
{
	freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m;

	sieve_of_eratosthenes();

	return 0;
}
