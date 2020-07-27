#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

struct Trie {
	Trie* next[26];
	int next_cnt = 0, finish = 0;
	Trie() {
		memset(next, 0, sizeof(next));
	}

	void insert(char* key) {
		if (!(*key)) finish = 1;
		else {
			int node = *key - 'a';
			if (!next[node]) {
				next[node] = new Trie();
				next_cnt++;
			}
			next[node]->insert(key + 1);
		}
	}

	int find(char* key) {
		if (!(*key)) return 0;
		int node = *key - 'a';
		return next[node]->find(key + 1) + ((next_cnt > 1) | finish);
	}

	~Trie() {
		FOR(i, 0, 25)
			if (next[i])
				delete next[i];
	}
};

int main() {
	FIO;
	int n;
	cout << fixed;
	cout.precision(2);
	while (cin >> n) {
		vector <string> s(n + 1);
		Trie* t = new Trie();
		t->finish = 1;
		FOR(i, 1, n) {
			cin >> s[i];
			t->insert(&s[i][0]);
		}
		double sum = 0;
		FOR(i, 1, n)
			sum += t->find(&s[i][0]);
		cout << sum / n << '\n';
		delete t;
	}
	return 0;
}