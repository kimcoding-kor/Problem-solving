#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
using namespace std;

typedef long long ll;

struct LST {
	ll* tree, * lazy;
	int size;
	LST(int n) {
		size = (1 << (int)(ceil(log2(n)) + 1));
		tree = new ll[size]();
		lazy = new ll[size]();
	}
	void propagate(int now, int start, int end) {
		if (!lazy[now]) return;
		tree[now] += lazy[now] * (end - start + 1);
		if (start < end) {
			lazy[now * 2] += lazy[now];
			lazy[now * 2 + 1] += lazy[now];
		}
		lazy[now] = 0;
	}
	void update(int now, int start, int end, int left, int right, ll val) {
		propagate(now, start, end);
		if (right < start || end < left) return;
		if (left <= start && end <= right) {
			lazy[now] += val;
			propagate(now, start, end);
			return;
		}
		int mid = (start + end) / 2;
		update(now * 2, start, mid, left, right, val);
		update(now * 2 + 1, mid + 1, end, left, right, val);
		tree[now] = tree[now * 2] + tree[now * 2 + 1];
	}
	ll query(int now, int start, int end, int left, int right) {
		propagate(now, start, end);
		if (right < start || end < left) return 0;
		if (left <= start && end <= right) return tree[now];
		int mid = (start + end) / 2;
		return query(now * 2, start, mid, left, right) + query(now * 2 + 1, mid + 1, end, left, right);
	}
	~LST() {
		delete[] tree;
		delete[] lazy;
	}
};

int main() {
	FIO;
	int n, m, k; cin >> n >> m >> k;
	LST lst(n);
	for (int i = 1; i <= n; i++) {
		ll x; cin >> x;
		lst.update(1, 1, n, i, i, x);
	}
	for (int i = 1; i <= m + k; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) {
			ll d; cin >> d;
			lst.update(1, 1, n, b, c, d);
		}
		else cout << lst.query(1, 1, n, b, c) << '\n';
	}
	return 0;
}