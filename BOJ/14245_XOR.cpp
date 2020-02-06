#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
using namespace std;

struct FT {
	int* tree, size;
	FT(int n) {
		tree = new int[(size = n) + 1]();
	}
	void update(int idx, int val) {
		while (idx <= size) {
			tree[idx] ^= val;
			idx += idx & -idx;
		}
	}
	int query(int idx) {
		int ret = 0;
		while (idx) {
			ret ^= tree[idx];
			idx -= idx & -idx;
		}
		return ret;
	}
	~FT() { delete[] tree; }
};

int main() {
	FIO;
	int n; cin >> n;
	FT ft(n);
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		ft.update(i, x);
		ft.update(i + 1, x);
	}
	int m; cin >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		if (a == 1) {
			int c, d; cin >> c >> d;
			ft.update(b + 1, d);
			ft.update(c + 2, d);
		}
		else cout << ft.query(b + 1) << '\n';
	}
	return 0;
}