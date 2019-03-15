/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;

#define dbg printf("in\n")
#define nl printf("\n")
#define N 510

using namespace std;

ll a[N][N];

ll nCr(int n, int r)
{
    if(a[n][r] != -1)
        return a[n][r];
	
	if(r == 0)
        a[n][r] = 1;

    if(n == r)
        a[n][r] = 1;

    else if(r == 1)
        a[n][r] = n;

    else
        a[n][r] = nCr(n -1, r - 1) + nCr(n - 1, r);

    return a[n][r];
}

int main()
{
    int i, j, k;
    int n, m;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
            a[i][j] = -1;
    }


    return 0;
}
