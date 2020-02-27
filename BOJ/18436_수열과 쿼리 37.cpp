#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

struct ST {
	int* odd, *even, leaf;
	ST(int n) {
		leaf = (1 << (int)ceil(log2(n)));
		odd = new int[leaf * 2]();
		even = new int[leaf * 2]();
		leaf--;
	}
	void update(int idx, int val) {
		idx += leaf;
		if (val & 1) odd[idx] = 1, even[idx] = 0;
		else odd[idx] = 0, even[idx] = 1;
		while (idx >>= 1) {
			odd[idx] = odd[idx << 1] + odd[idx << 1 | 1];
			even[idx] = even[idx << 1] + even[idx << 1 | 1];
		}
	}
	int query(int l, int r, int c) {
		int ret = 0;
		l += leaf, r += leaf;
		for (; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) ret += c ? odd[l++] : even[l++];
			if (~r & 1) ret += c ? odd[r--] : even[r--];
		}
		if (l == r) ret += c ? odd[l] : even[l];
		return ret;
	}
	~ST() {
		delete[] odd, delete[] even;
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
	int m; cin >> m;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) st.update(b, c);
		else cout << st.query(b, c, a - 2) << '\n';
	}
	return 0;
}