#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

struct Trie {
	Trie* next[65];
	bool chk, finish;

	Trie() : chk(true), finish(false) {
		memset(next, 0, sizeof(next));
	}

	int ctoi(char key) {
		if (key >= 'a' && key <= 'z') return key - 'a';
		if (key >= 'A' && key <= 'Z') return key - 'A' + 26;
		if (key >= '0' && key <= '9') return key - '0' + 52;
		return 62;
	}

	void insert(char* key) {
		if (!*key) finish = true;
		else {
			int v = ctoi(*key);
			if (!next[v]) next[v] = new Trie();
			next[v]->insert(key + 1);
		}
	}

	void update(char *key) {
		chk = false;
		if (!*key) return;
		int v = ctoi(*key);
		if (!next[v]) return;
		next[v]->update(key + 1);
	}

	int query() {
		if (chk) return 1;
		int ret = 0;
		FOR(i, 0, 64) {
			if (!next[i]) continue;
			ret += next[i]->query();
		}
		return ret + finish;
	}

	~Trie() {
		FOR(i, 0, 64)
			if (next[i]) delete next[i];
	}
};

int main() {
	FIO;
	int t; cin >> t; while (t--) {
		Trie t;
		int n, m;
		cin >> n;
		FOR(i, 1, n) {
			string s;
			cin >> s;
			t.insert(&s[0]);
		}
		cin >> m;
		FOR(i, 1, m) {
			string s;
			cin >> s;
			t.update(&s[0]);
		}
		cout << t.query() << '\n';
	}
	return 0;
}