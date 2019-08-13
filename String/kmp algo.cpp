/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n")
#define nl printf("\n")
#define N 101010
#define inf 1e18
#define mod 998244353

#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d",n)
#define pff(n,m) printf("%d %d",n,m)
#define pffl(n,m) printf("%I64d %I64d",n,m)
#define pfl(n) printf("%I64d",n)
#define pfs(s) printf("%s",s)

#define pb push_back
#define pp pair<int, int>

using namespace std;

int f[N];
void failure_function(string pattern)
{
    f[0] = 0;
    int k = 1, len = 0, len_p = pattern.length();

    while(k < len_p)
    {
        if(pattern[k] == pattern[len])
            f[k++] = ++len;

        else
        {
            if(len)
                len = f[len - 1];
            else
                f[k++] = 0;
        }
    }
}

bool kmp(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();

    failure_function(pattern);

    int i = 0; // initial state of automation, the empty string
    int j = 0; // first char of the text

    while(j < n)
    {
        if(text[j] == pattern[i])
        {
            i++; // go to the next state of the automation
            j++; // get the next char from the text

            if(i == m)return true;
        }

        else
        {
            // was in the start state, will stay in the start state
            //move forward in the text
            if(i == 0)
                j++;

            else
                i = f[i];
        }
    }

    return false;
}

int main()
{
    freopen("in.txt", "r", stdin);

    int i, j, k;
    int n, m;

    return 0;
}
