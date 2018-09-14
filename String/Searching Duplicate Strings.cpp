/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n")
#define nl printf("\n");
#define N 1100
#define inf 10000000000000000

#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d ",n)
#define pff(n,m) printf("%d %d\n",n,m)
#define pffl(n,m) printf("%I64d %I64d\n",n,m)
#define pfl(n) printf("%I64d\n",n)
#define pfs(s) printf("%s",s)

#define pb push_back
#define pp pair<ll,int>

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

vector<string> s;
vector<int> ans[N];

//takes O(nm+nlogn)
void group_identical_strings()
{
    int i,j,k;
    int n=s.size();
    vector<pp> hashes(n);

    for(i=0; i<n; i++)
        hashes[i]= {compute_hash(s[i]),i};

    sort(hashes.begin(),hashes.end());

    k=0;
    for(i=0;i<n;i++)
    {
        if(i>0 && hashes[i].first!=hashes[i-1].first) k++;
        ans[k].pb(hashes[i].second);
    }
}

int main()
{
    freopen("in.txt","r",stdin);

    int i,j,k;
    int n,m;

    return 0;
}

