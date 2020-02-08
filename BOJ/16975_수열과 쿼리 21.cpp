#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
#define ll long long
using namespace std;

struct FT {
	ll* tree;
	int size;
	FT(int n) {
		tree = new ll[(size = n) + 1]();
	}
	void update(int idx, ll val) {
		while (idx <= size) {
			tree[idx] += val;
			idx += idx & -idx;
		}
	}
	ll query(int idx) {
		ll ret = 0;
		while (idx) {
			ret += tree[idx];
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
	FOR(i,1,n) {
		int x; cin >> x;
		ft.update(i, 1LL * x);
		ft.update(i + 1, -1LL * x);
	}
	int m; cin >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		if (a == 1) {
			int c, d; cin >> c >> d;
			ft.update(b, 1LL * d);
			ft.update(c + 1, -1LL * d);
		}
		else cout << ft.query(b) << '\n';
	}
	return 0;
}