/***from dust i have come, dust i will be***/

/*
	given n elements (1<=n<=1e5) 
	find 2 elements such that their xor is maximum
*/

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

//gives answer in 32-bits
string decToBin(int n)
{
	string s = "";
	while (n)
	{
		s.pb(n % 2 + 48);
		n /= 2;
	}

	while (s.length() < 32)
		s.pb('0');

	reverse(s.begin(), s.end());
	return s;
}

int toDecimal(string s)
{
    int sum = 0, p = 1;
    for(int i = 31; i >=0; i--)
    {
        sum += p * (s[i] - 48);
        p *= 2;
    }

    return sum;
}

struct trieNode
{
	bool end;
	trieNode *next[2];

	trieNode() {
		end = false;
		for (int i = 0; i < 2; i++)
			next[i] = NULL;
	}
};

class trie
{
	trieNode *root;
public:
	trie() {
		root = new trieNode();
	}

	void insertWord(string s)
	{
		trieNode *curr = root;

		int n = s.length(), id;
		for (int i = 0; i < n; i++)
		{
			id = s[i] - '0';

			if (curr->next[id] == NULL)
				curr->next[id] = new trieNode();

			curr = curr->next[id];
		}

		curr->end = true;
	}

	int solve(int n)
	{
	    string s = decToBin(n), ans;

	    trieNode *curr = root;
	    for(int i = 0; i < 32; i++)
        {
            //get 1
            if(s[i] == '0')
            {
                if(curr->next[1] == NULL)
                    ans.pb('0'), curr = curr->next[0];
                else
                    ans.pb('1'), curr = curr->next[1];
            }

            //get 0
            else
            {
                if(curr->next[0] == NULL)
                    ans.pb('1'), curr = curr->next[1];
                else
                    ans.pb('0'), curr = curr->next[0];
            }
        }

        return toDecimal(ans);
	}
};


int main()
{
    freopen("in.txt", "r", stdin);

    int i, j, k;
    int n, m;

    sf(n);

    trie t;
    int a[n];
    for(i = 0; i <n; i++)
        sf(a[i]), t.insertWord(decToBin(a[i]));


    m = 0;
    for(i = 0; i < n; i++)
        m = max(m, t.solve(a[i]) ^ a[i]);

    pf(m);

    return 0;
}
