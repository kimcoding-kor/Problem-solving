#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
#define all(x) (x).begin(), (x).end()
#define vi vector <int>
#define vvi vector <vi>
#define ll long long
#define vll vector <ll>
#define vvl vector <vll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ep emplace
#define fs first
#define sd second
#define mod 998244353
#define EPS 1e-9
using namespace std;

int n, k, ans, m;

struct Trie {
	Trie* next[26];
	int val;
	Trie() : val(0) {
		FOR(i, 0, 25) next[i] = nullptr;
	}
	void insert(int now, string& s) {
		if (s[now]) {
			int node = s[now] - 'A';
			if (!next[node])
				next[node] = new Trie();
			next[node]->insert(now + 1, s);
			next[node]->val++;
		}
	}
	int find(int now) {
		int sum = 0;
		FOR(i, 0, 25) {
			if (!next[i] || next[i]->val < k) continue;
			sum += next[i]->find(now + 1);
		}
		ans += now * ((val - sum) / k);
		return sum + (val - sum) / k * k;
	}
	~Trie() {
		FOR(i,0,25)
			if (next[i])
				delete next[i];
	}
};

int main() {
	FIO;
	int test; cin >> test;
	FOR(t, 1, test) {
		ans = 0, m = 0;
		cin >> n >> k;
		Trie* root = new Trie();
		FOR(i, 0, n - 1) {
			string x; cin >> x;
			root->insert(0, x);
		}
		root->find(0);
		cout << "Case #" << t << ": " << ans << '\n';
		delete root;
	}
	return 0;
}