#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define mod ((int)1e9 + 7)
using namespace std;

struct ST {
	int* tree, leaf;
	ST(int n) {
		leaf = (1 << (int)ceil(log2(n)));
		tree = new int[leaf * 2];
		FOR(i, 1, leaf * 2 - 1) tree[i] = 1;
		leaf--;
	}
	void update(int idx, int val) {
		idx += leaf;
		tree[idx] = val;
		while (idx >>= 1) tree[idx] = (1ll * tree[idx << 1] * tree[idx << 1 | 1]) % mod;
	}
	int query(int l, int r) {
		int ret = 1;
		l += leaf, r += leaf;
		for (; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) ret = (1ll * ret * tree[l++]) % mod;
			if (~r & 1) ret = (1ll * ret * tree[r--]) % mod;
		}
		if (l == r) ret = (1ll * ret * tree[l]) % mod;
		return ret;
	}
	~ST() {
		delete[] tree;
	}
};

int main() {
	FIO;
	int n, m, k;
	cin >> n >> m >> k;
	ST st(n);
	FOR(i, 1, n) {
		int x; cin >> x;
		st.update(i, x);
	}
	FOR(i, 1, m + k) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) st.update(b, c);
		else cout << st.query(b, c) << '\n';
	}
	return 0;
}