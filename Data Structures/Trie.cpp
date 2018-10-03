#define _CRT_SECURE_NO_WARNINGS

/***from dust i have come, dust i will be***/

#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n")
#define nl printf("\n");
#define N 350
#define inf 100000000

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

struct trieNode
{
	bool end;
	trieNode *next[26];

	trieNode() {
		end = false;
		for (int i = 0; i < 26; i++)
			next[i] = NULL;
	}
};

class trie
{
	trieNode *root;

	bool del(string s, int i, trieNode *curr)
	{
		//if the word is not found
		if (i < s.length() && curr->next[s[i] - 'a'] == NULL)return false;

		if (i == s.length() - 1)
		{
			//now we can free the last node that has end = true
			delete(curr->next[s[i] - 'a']);

			//now if this node do not belongs to any other word then we can return true so that its parent can delete it
			//if it is the root, then it will not be affected as it will return true in deleteWord function where there will be none to free it
			for (int i = 0; i < 26; i++) {
				if (curr->next[s[i] - 'a'] != NULL) return false;
			}

			return true;
		}

		//check the next char
		bool f = del(s, i + 1, curr->next[s[i] - 'a']);

		if (f) delete(curr->next[s[i] - 'a']);

		for (int i = 0; i < 26; i++) {
			if (curr->next[s[i] - 'a'] != NULL) return false;
		}

		return true;
	}

	//recursively frees memory
	void fr(trieNode *curr)
	{
		for (int i = 0; i<26; i++)
		{
			if (curr->next[i])
				fr(curr->next[i]);
		}

		delete(curr);
	}

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
			id = s[i] - 'a';

			if (curr->next[id] == NULL)
				curr->next[id] = new trieNode();

			curr = curr->next[id];
		}

		curr->end = true;
	}

	bool searchWord(string s)
	{
		trieNode *curr = root;

		int n = s.length(), id;
		for (int i = 0; i < n; i++)
		{
			id = s[i] - 'a';

			if (curr->next[id] == NULL) return false;
			curr = curr->next[id];
		}

		//if matches then curr will be the last empty node that has end=true
		return curr->end;
	}

	void deleteWord(string s) {
		del(s, 0, root);
	}

	void deleteWordsWithCommonPrefix(string prefix)
	{
		trieNode *curr = root, *parent = NULL;

		int n = prefix.length(), id;
		for (int i = 0; i < n; i++)
		{
			id = prefix[i] - 'a';
			if (curr->next[id] == NULL) return;

			parent = curr;
			curr = curr->next[id];
		}

		fr(curr);

		//we have deleted words having common prefix, e.g if we delete word starting with "ab"
		//now parent-node have the node where 'b' is, but we can't delete the node, so we make b point to null
		
		if(parent)
			parent->next[prefix[n - 1] - 'a'] = NULL;
	}

	void freeMem() {
		fr(root);
	}
};

int main()
{
	freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m;


	return 0;
}
