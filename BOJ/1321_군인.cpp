#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
using namespace std;

struct ST {
	int* tree, leaf;
	ST(int n) {
		leaf = 1 << (int)ceil(log2(n));
		tree = new int[leaf * 2]();
		leaf--;
	}
	void update(int i, int x) {
		i += leaf;
		tree[i] += x;
		while (i >>= 1) tree[i] = tree[i << 1] + tree[i << 1 | 1];
	}
	int query(int x) {
		int i = 1;
		while (i <= leaf) {
			int l = tree[i << 1], r = tree[i << 1 | 1];
			if (l >= x) i <<= 1;
			else i = i << 1 | 1, x -= l;
		}
		return i - leaf;
	}
};

int main() {
	FIO;
	int n; cin >> n;
	ST st(n);
	FOR(i, 1, n) {
		int x; cin >> x;
		st.update(i, x);
	}
	int k; cin >> k;
	while (k--) {
		int t, a; cin >> t >> a;
		if (t == 1) {
			int b; cin >> b;
			st.update(a, b);
		}
		if (t == 2) cout << st.query(a) << '\n';
	}
	return 0;
}