#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define vi vector <int>
#define vvi vector <vi>
#define eb emplace_back
#define ll long long
using namespace std;

struct p {
	int node, val;
	bool operator< (const p& a) const {
		return val < a.val;
	}
};

struct ST {
	vector <p> tree;
	int leaf;
	ST(int n) {
		leaf = 1 << (int)ceil(log2(n));
		tree.resize(leaf << 1, p{ 0,0 });
	}
	void update(int now, int val) {
		now += leaf;
		tree[now] = p{ now - leaf, val };	
		while (now >>= 1)
			tree[now] = max(tree[now << 1], tree[now << 1 | 1]);
	}
	p query(int l, int r) {
		p ret = p{ 0, 0 };
		l += leaf, r += leaf;
		for (; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ret = max(ret, tree[l++]);
			if (~r & 1) ret = max(ret, tree[r--]);
		}
		if (l == r) ret = max(ret, tree[l]);
		return ret;
	}
	~ST() {
		tree.clear();
	}
};

int main() {
	FIO;
	int n, m;
	cin >> n >> m;
	vvi adj(n + 1);
	vector <ll> c(n + 1), l(n + 1), cnt(n + 1);
	FOR(i, 1, n) {
		int a;
		cin >> a >> c[i] >> l[i];
		adj[a].eb(i);
	}

	int z = 0;
	ll ans = 0;
	ST st(2 * n - 1);

	function <void(int)> dfs = [&](int now) {
		int idx = z;
		cnt[now]++;
		st.update(z++, c[now]);
		for (int next : adj[now]) {
			dfs(next);
			c[now] += c[next];
			cnt[now] += cnt[next];
		}
		while (c[now] > m) {
			p q = st.query(idx, z - 1);
			st.update(q.node, 0);
			c[now] -= q.val;
			cnt[now]--;
		}

		ans = max(ans, cnt[now] * l[now]);
	};

	dfs(1);
	cout << ans << '\n';
	return 0;
}