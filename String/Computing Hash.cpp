/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;

using namespace std;

//hash(s) = (s[0] + s[1].p + s[2].p^2 + ...)%m
ll compute_hash(string s)
{
    const int p=31;
    const int m=1e9+9;

    ll hash_value=0;
    ll p_pow=1;

    for(char c : s)
    {
        hash_value=(hash_value+(c-'a'+1)*p_pow)%m;
        p_pow=(p_pow*p)%m;
    }

    return hash_value;
}

int main()
{
    freopen("in.txt","r",stdin);

    int i,j,k;
    int n,m;

    return 0;
}

