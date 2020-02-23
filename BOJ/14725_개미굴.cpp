#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

struct Trie {
	map<string, int> m;
	string s;
	vector <Trie*> next;
	Trie(){}
	void insert(string* t) {
		if (*t != "") {
			if (m.find(*t) == m.end()) {
				m[*t] = m.size();
				next.emplace_back(new Trie());
			}
			next[m[*t]]->insert(t + 1);
			next[m[*t]]->s = *t;
		}
	}
	void print(int now) {
		for (int i = 1; i < now * 2 - 1; i++) cout << '-';
		if (now) cout << s << '\n';
		for (auto it = m.begin(); it != m.end(); ++it)
			next[it->second]->print(now + 1);
	}
	~Trie() {
		for (Trie* i : next) delete[] i;
		m.clear(), next.clear();
	}
};

int main() {
	FIO;
	Trie* root = new Trie();
	int n; cin >> n;
	for (int i = 0, k; i < n; i++) {
		cin >> k; string* s = new string[k + 1];
		for (int j = 0; j < k; j++) cin >> s[j];
		root->insert(s);
	}
	root->print(0);
	return 0;
}