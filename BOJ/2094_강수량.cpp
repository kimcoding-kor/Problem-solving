#include <cstdio>
#include <cmath>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

struct p {
	int val, cnt;
	p f(p u) {
		return p{ max(val,u.val),cnt + u.cnt };
	}
};

struct ST {
	p* tree;
	int leaf;
	ST(int n) {
		leaf = (1 << (int)ceil(log2(n)));
		tree = new p[leaf * 2];
		for (int i = 0; i < leaf * 2; i++) tree[i] = p{ (int)-1e9,0 };
	}
	void update(int idx, int val) {
		idx += leaf;
		tree[idx] = p{ val,1 };
		while (idx >>= 1) tree[idx] = tree[idx * 2].f(tree[idx * 2 + 1]);
	}
	p query(int l, int r) {
		p ret = p{ (int)-1e9, 0 };
		l += leaf, r += leaf;
		for (; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) ret = ret.f(tree[l++]);
			if (!(r & 1)) ret = ret.f(tree[r--]);
		}
		if (l == r) ret = ret.f(tree[l]);
		return ret;
	}
	~ST() {
		delete[] tree;
	}
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	map<int, int> check;
	ST st(n);
	for (int i = 0, a, b; i < n; i++) {
		cin >> a >> b;
		check[a] = i;
		st.update(i, b);
	}
	int m; cin >> m;
	auto solve = [&](int a, int b) {
		auto ca = check.find(a), cb = check.find(b);
		if (ca == check.end() && cb == check.end()) return 2;
		if (ca == check.end()) {
			p x = st.query(check[b], check[b]);
			auto idx = check.lower_bound(a);
			p qr = st.query(idx->second, check[b] - 1);
			if (qr.val < x.val) return 2;
			return 0;

		}
		if (cb == check.end()) {
			p y = st.query(check[a], check[a]);
			auto idx = check.lower_bound(b); --idx;
			p qr = st.query(check[a] + 1, idx->second);
			if (qr.val < y.val) return 2;
			return 0;
		}
		p y = st.query(check[a], check[a]), x = st.query(check[b], check[b]);
		if (y.val < x.val) return 0;
		p qr = st.query(check[a] + 1, check[b] - 1);
		if (qr.val < x.val) return (qr.cnt == b - a - 1) ? 1 : 2;
		return 0;
	};
	while (m--) {
		int a, b; cin >> a >> b;
		int ans = solve(a, b);
		cout << (ans == 1 ? "true\n" : (ans ? "maybe\n" : "false\n"));
	}
	return 0;
}