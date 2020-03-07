#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
#define all(x) (x).begin(), (x).end()
#define vi vector <int>
#define vvi vector <vi>
#define ll long long
#define vll vector <ll>
#define pii pair<int,int>
#define eb emplace_back
#define fs first
#define sd second
using namespace std;
 
struct ST {
	vll tree; int leaf;
	ST(int n) {
		leaf = (1 << (int)ceil(log2(n)));
		tree.resize(leaf * 2);
	}
	void update(int idx, ll val) {
		idx += leaf;
		tree[idx] = val;
		while (idx >>= 1) tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	}
	ll query(int l, int r) {
		ll ret = 0;
		l += leaf, r += leaf;
		for (; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) ret += tree[l++];
			if (~r & 1) ret += tree[r--];
		}
		if (l == r) ret += tree[l];
		return ret;
	}
	~ST() {
		tree.clear();
	}
};
 
map <pii, int> m;
 
int main() {
	FIO;
	int n; cin >> n;
	vector <pii> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].fs, v[i].sd = i;
	sort(all(v));
	vi time(n);
	ST st(n);
	for (int i = 0; i < n; i++) cin >> time[i];
	int now = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		while (m.size() && now < v[i].fs) {
			auto it = m.end(); --it;
			st.update(it->fs.sd, 0);
			ans += st.query(0,n - 1);
			now++;
			m.erase(it);
		}
		if (m.empty()) now = v[i].fs;
		st.update(v[i].sd, time[v[i].sd]); m[{time[v[i].sd], v[i].sd}] = 1;
		while (i < n - 1 && v[i].fs == v[i + 1].fs) {
			st.update(v[i + 1].sd, time[v[i + 1].sd]);
			m[{time[v[i + 1].sd], v[i + 1].sd}] = 1;
			i++;
		}
		auto it = m.end(); --it;
		st.update(it->fs.sd, 0);
		ans += st.query(0, n - 1);
		now++;
		m.erase(it);
	}
	while (m.size()) {
		auto it = m.end(); --it;
		st.update(it->fs.sd, 0);
		ans += st.query(0, n - 1);
		now++;
		m.erase(it);
	}
	cout << ans << '\n';
	return 0;
}