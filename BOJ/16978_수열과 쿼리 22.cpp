#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define vi vector <int>
#define vvi vector <vi>
using namespace std;

struct p {
	int a, b, c, d;
	bool operator< (p u)const {
		return a < u.a;
	}
};

struct ST {
	vector <ll> tree;
	int leaf;
	ST(int n) {
		leaf = (1 << (int)ceil(log2(n)));
		tree.resize(leaf * 2);
	}
	void update(int idx, ll val) {
		idx += leaf;
		tree[idx] = val;
		while (idx >>= 1) tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	}
	ll query(int l, int r) {
		ll ret = 0;
		l += leaf, r += leaf;
		for (; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) ret += tree[l++];
			if (!(r & 1)) ret += tree[r--];
		}
		if (l == r) ret += tree[l];
		return ret;
	}
	~ST() {
		tree.clear();
	}
};

int main() {
	FIO;
	int n; cin >> n;
	ST st(n);
	vector <p> q1(1), q2;
	FOR(i, 1, n) {
		int x; cin >> x;
		st.update(i, x);
	}
	int m; cin >> m;
	FOR(i, 1, m) {
		int t, a, b; cin >> t >> a >> b;
		if (t == 1) q1.push_back(p{ a, b, 0, 0 });
		else {
			int c; cin >> c;
			q2.push_back(p{ a,b,c,(int)q2.size() });
		}
	}
	sort(all(q2));
	int idx = 0;
	vector <ll> ans(q2.size());
	FOR(i, 0, (int)q1.size() - 1) {
		st.update(q1[i].a, q1[i].b);
		while (idx < q2.size() && q2[idx].a <= i) {
			ans[q2[idx].d] = st.query(q2[idx].b, q2[idx].c);
			idx++;
		}
	}
	FOR(i, 0, (int)q2.size() - 1)
		cout << ans[i] << '\n';
	return 0;
}