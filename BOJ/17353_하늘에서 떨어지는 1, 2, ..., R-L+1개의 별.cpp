#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define fs first
#define sd second
#define vi vector <int>
#define vvi vector <vi>
#define pii pair<int,int>
#define ppi pair <pii,pii>
using namespace std;

struct FT {
	vector <pair<ll, ll>> tree;
	int size;
	FT(int n) :size(n) {
		tree.resize(n + 1);
	}
	void update(int a, int b) { update(a, 1, a), update(b + 1, -1, a); }
	void update(int idx, int val, int a) {
		while (idx <= size) {
			tree[idx].fs += val;
			tree[idx].sd += (a - 1) * val;
			idx += (idx & -idx);
		}
	}
	ll query(int idx) {
		ll ans = 0;
		int i = idx;
		while (i) {
			ans += 1LL * idx * tree[i].fs - tree[i].sd;
			i -= (i & -i);
		}
		return ans;
	}
	~FT() {
		tree.clear();
	}
};

int main() {
	FIO;
	int n; cin >> n;
	FT ft(n);
	vi v(n + 1);
	FOR(i, 1, n) cin >> v[i];
	int m; cin >> m;
	while (m--) {
		int t, a, b;
		cin >> t >> a;
		if (t == 1) {
			cin >> b;
			ft.update(a, b);
		}
		else cout << 1LL * v[a] + ft.query(a) << '\n';
	}
	return 0;
}