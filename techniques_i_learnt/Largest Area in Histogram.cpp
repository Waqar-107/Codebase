/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n")
#define nl printf("\n")
#define N 510
#define inf 1e6

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

int largestRectangleArea(vector<int>& heights)
{
    stack<int> stk;

    int i = 0, j;
    int n = heights.size();

    int ans = 0;
    while(i < n)
    {
        if(stk.empty() || heights[stk.top()] <= heights[i])
            stk.push(i), i++;

        else
        {
            j = stk.top();
            stk.pop();

            // empty means all those before this one is greater than this one.
            if(stk.empty())
                ans = max(ans, heights[j] * i);

            // length from te popped element to i
            else
                ans = max(ans, heights[j] * (i - stk.top() - 1));
        }
    }

    while(!stk.empty())
    {
        j = stk.top();
        stk.pop();

        // empty means all those before this one is greater than this one.
        if(stk.empty())
            ans = max(ans, heights[j] * i);

        // length from te popped element to i
        else
            ans = max(ans, heights[j] * (i - stk.top() - 1));
    }

    return ans;
}

int main()
{
    freopen("in.txt", "r", stdin);

    int i, j, k;
    int n, m;


    return 0;
}
