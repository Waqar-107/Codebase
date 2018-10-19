/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n");
#define nl printf("\n");
#define N 1000

using namespace std;

int status[N / 32];
vector<int> primes;

bool check_bit(int n, int pos) {
	return (bool)(n & (1 << pos));
}

int set_bit(int n, int pos) {
	return n = n | (1 << pos);
}

//each int is capable of keeping status for 32 integers whether they are prime
void bitwise_sieve()
{
	int i, j, k;
	int sq;

	sq = sqrtl(N*1.0);
	for (i = 3; i <= sq; i += 2)
	{
		if (check_bit(status[i / 32], i % 32) == 0)
		{
			for (j = i*i; j < N; j += i + i)
				status[j / 32] = set_bit(status[j / 32], j % 32);
		}
	}

	primes.push_back(2);
	for (i = 3; i < N; i++)
	{
		if (check_bit(status[i / 32], i % 32) == 0)
			primes.push_back(i);
	}
}

int main()
{
	//freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m, f;

	bitwise_sieve();

	return 0;
}
