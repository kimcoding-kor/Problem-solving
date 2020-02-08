#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define vi vector <int>
#define vvi vector <vi>
#define pii pair <int,int>
using namespace std;

struct LST {
	int* tree, * lazy;
	int size;
	LST(int n) {
		size = (1 << (int)(ceil(log2(n)) + 1));
		tree = new int[size]();
		lazy = new int[size]();
	}
	void propagate(int now, int s, int e) {
		if (!lazy[now]) return;
		tree[now] = max(tree[now], lazy[now]);
		if (s < e) {
			lazy[now * 2] = max(lazy[now * 2], lazy[now]);
			lazy[now * 2 + 1] = max(lazy[now * 2 + 1], lazy[now]);
		}
		lazy[now] = 0;
	}
	void update(int now, int s, int e, int l, int r, int val) {
		propagate(now, s, e);
		if (r < s || e < l) return;
		if (l <= s && e <= r) {
			lazy[now] = max(lazy[now], val);
			propagate(now, s, e);
			return;
		}
		int mid = (s + e) / 2;
		update(now * 2, s, mid, l, r, val);
		update(now * 2 + 1, mid + 1, e, l, r, val);
		tree[now] = max(tree[now * 2], tree[now * 2 + 1]);
	}
	int query(int now, int s, int e, int l, int r) {
		propagate(now, s, e);
		if (r < s || e < l) return 0;
		if (l <= s && e <= r) return tree[now];
		int mid = (s + e) / 2;
		return max(query(now * 2, s, mid, l, r), query(now * 2 + 1, mid + 1, e, l, r));
	}
	~LST() {
		delete[] tree;
		delete[] lazy;
	}
};

int main() {
	FIO;
	int n; cin >> n;
	vector <pii> v(n);
	vi idx(2 * n);
	FOR(i, 0, n - 1) {
		int a, b; cin >> a >> b;
		v[i] = { b,b + a - 1 };
		idx[i * 2] = b, idx[i * 2 + 1] = b + a - 1;
	}
	sort(all(idx));
	auto find_idx = [&](int x) {return lower_bound(idx.begin(), idx.end(), x) - idx.begin(); };
	LST lst(2 * n);
	int ans = 0;
	FOR(i, 0, n - 1) {
		pii now = v[i];
		int a = find_idx(now.first), b = find_idx(now.second);
		int c = lst.query(1, 1, 2 * n, a, b);
		ans = max(ans, c + 1);
		lst.update(1, 1, 2 * n, a, b, c + 1);
	}
	cout << ans << '\n';
	return 0;
}