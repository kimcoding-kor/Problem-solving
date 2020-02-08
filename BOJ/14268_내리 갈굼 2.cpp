#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
#define vi vector <int>
#define vvi vector <vi>
using namespace std;

struct FT {
	vi tree;
	int size;
	FT(int n):size(n) {
		tree.resize(size + 1);
	}
	void update(int a, int b, int diff) {
		update(a, diff);
		update(b + 1, -diff);
	}
	void update(int idx, int diff) {
		while (idx <= size) {
			tree[idx] += diff;
			idx += (idx & -idx);
		}
	}
	int query(int idx) {
		int ret = 0;
		while (idx) {
			ret += tree[idx];
			idx -= (idx & -idx);
		}
		return ret;
	}
};

int main() {
	FIO;
	int n, m; cin >> n >> m;
	FT ft(n);
	vvi adj(n + 1);
	vi cnt(n + 1), idx(n + 1);
	int z = 1;
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		if (x == -1) continue;
		adj[x].push_back(i);
	}
	function <int(int)> dfs = [&](int now) {
		idx[now] = z;
		ft.update(z, z++, now);
		for (int next : adj[now])
			cnt[now] += dfs(next);
		return cnt[now] + 1;
	};
	dfs(1);
	while (m--) {
		int t, a; cin >> t >> a;
		if (t == 1) {
			int b; cin >> b;
			ft.update(idx[a], idx[a] + cnt[a], b);
		}
		else cout << ft.query(idx[a]) << '\n';
	}
	return 0;
}