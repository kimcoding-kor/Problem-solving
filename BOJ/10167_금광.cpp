#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

struct p {
	int x, y, w;
	bool operator< (const p& u) const {
		return y < u.y;
	}
};

struct ST {
	vector <ll> sum, l, r, Max;
	int leaf;
	ST(int n) {
		leaf = (1 << (int)ceil(log2(n)));
		sum = l = r = Max = vector <ll>(leaf * 2);
	}
	void update(int idx, ll val) {
		idx += leaf;
		sum[idx] = l[idx] = r[idx] = Max[idx] += val;
		while (idx /= 2) {
			int a = idx * 2, b = idx * 2 + 1;
			sum[idx] = sum[a] + sum[b];
			l[idx] = max(l[a], sum[a] + l[b]);
			r[idx] = max(r[b], sum[b] + r[a]);
			Max[idx] = max({ sum[idx], r[a] + l[b], Max[a], Max[b] });
		}
	}
	ll query() {
		return Max[1];
	}
	~ST() {
		sum.clear(), l.clear(), r.clear(), Max.clear();
	}
};

int main() {
	FIO;
	int n; cin >> n;
	vector <p> v(n);
	vector <int> xidx(n);
	FOR(i, 0, n - 1) {
		cin >> v[i].x >> v[i].y >> v[i].w;
		xidx[i] = v[i].x;
	}
	sort(all(v));
	sort(all(xidx));
	xidx.erase(unique(all(xidx)), xidx.end());
	ll ans = 0;
	FOR(i, 0, n - 1) {
		if (i && v[i].y == v[i - 1].y) continue;
		ST st(n);
		FOR(j, i, n - 1) {
			int cnt = 0;
			while (!cnt || (j < n && v[j - 1].y == v[j].y)) {
				int idx = lower_bound(all(xidx), v[j].x) - xidx.begin();
					st.update(idx, 1LL * v[j++].w);
					cnt++;
				}
			j--, ans = max(ans, st.query());
		}
	}
	cout << ans << '\n';
	return 0;
}