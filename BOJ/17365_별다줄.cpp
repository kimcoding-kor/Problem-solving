#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define mod ((int)1e9 + 7)

vector <vector <int>> v;
vector <int> dp;
int n, len;
char s[200005];

typedef struct Trie {
	vector <Trie*> next;
	bool finish;
	int child;
	Trie() : finish(false), child(0) {
		next.resize(26,0);
	}
	void insert(char* key) {
		child++;
		if (*key == '\0') finish = true;
		else {
			int node = *key - 'a';
			if (next[node] == NULL)
				next[node] = new Trie;
			next[node]->insert(key + 1);
		}
	}
	void find(int idx, int depth, char *key) {
		if (*key == '\0') return;
		int node = *key - 'a';
		if (next[node] == NULL) return;
		if (idx + depth >= len) return;
		v[idx].push_back(next[node]->child);
		next[node]->find(idx, depth + 1, key + 1);
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			delete next[i];
	}
}Trie;

int dfs(int idx) {
	if (idx == len) return 1;
	int& ret = dp[idx];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < v[idx].size(); i++)
		ret = (ret + (int)(1LL * v[idx][i] * dfs(idx + i + 1) % mod)) % mod;
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	Trie* root = new Trie;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		root->insert(s);
	}
	cin >> s;
	len = strlen(s);
	v.resize(len + 1);
	dp.resize(len + 1, -1);
	for (int i = 0; i < len; i++)
		root->find(i, 0, s + i);
	printf("%d\n", dfs(0));
	return 0;
}