#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

struct p {
	int	Min = 1e9, idx = 0;
	bool operator< (const p& u) const{
		if (Min == u.Min) return idx < u.idx;
		return Min < u.Min;
	}
};

struct ST {
	p* tree;
	int leaf;
	ST(int n) {
		leaf = (1 << (int)ceil(log2(n)));
		tree = new p[leaf * 2];
		leaf--;
	}
	void update(int idx, int val) {
		idx += leaf;
		tree[idx] = p{ val, idx - leaf };
		while (idx >>= 1) tree[idx] = min(tree[idx << 1], tree[idx << 1 | 1]);
	}
	p query(int l, int r) {
		p ret;
		l += leaf, r += leaf;
		for (; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) ret = min(ret, tree[l++]);
			if (~r & 1) ret = min(ret, tree[r--]);
		}
		if (l == r) ret = min(ret, tree[l]);
		return ret;
	}
	~ST() {
		delete[] tree;
	}
};

int main() {
	FIO;
	int n, m; cin >> n;
	ST st(n);
	FOR(i, 1, n) {
		int x; cin >> x;
		st.update(i, x);
	}
	cin >> m;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) st.update(b, c);
		else cout << st.query(b, c).idx << '\n';
	}
	return 0;
}