#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define all(x) (x).begin(), (x).end()
#define vi vector <int>
#define eb emplace_back
using namespace std;

struct p {
	int a, b, c, t;
	bool operator< (p u) {
		if (a == u.a) return t < u.t;
		return a < u.a;
	}
};

struct ST {
	int* tree, *cnt;
	ST(int n) {
		int tree_size = 1 << ((int)ceil(log2(n)) + 1);
		tree = new int[tree_size]();
		cnt = new int[tree_size]();
	}
	void update(int a, int  b, int c) { update(1, 0, 30000, a, b, c); }
	void update(int now, int start, int end, int left, int right, int val) {
		if (right < start || end < left) return;
		if (left <= start && end <= right) cnt[now] += val;
		else {
			int mid = start + end >> 1;
			update(now << 1, start, mid, left, right, val);
			update(now << 1 | 1, mid + 1, end, left, right, val);
		}
		int x = 0;
		if (cnt[now]) x = end - start + 1;
		else if(start != end) x = tree[now << 1] + tree[now << 1 | 1];
		tree[now] = x;
	}
	int query() {
		return tree[1];
	}
	~ST() {
		delete[] tree;
	}
};


int main() {
	FIO;
	int n, ans = 0;
	cin >> n;
	vector <p> v;
	FOR(i, 0, n - 1) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v.eb(p{ a,b,d, 1 });
		v.eb(p{ c,b,d, -1 });
	}
	sort(all(v));
	ST st(30005);
	st.update(v[0].b, v[0].c - 1, 1);

	FOR(i, 1, 2 * n - 1) {
		ans += (v[i].a - v[i - 1].a) * st.query();
		st.update(v[i].b, v[i].c - 1, v[i].t);
	}

	cout << ans << '\n';
	return 0;
}