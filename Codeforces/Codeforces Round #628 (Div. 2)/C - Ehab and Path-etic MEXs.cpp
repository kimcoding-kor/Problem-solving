#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
#define all(x) (x).begin(), (x).end()
#define vi vector <int>
#define vvi vector <vi>
#define ll long long
#define vll vector <ll>
#define vvl vector <vll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ep emplace
#define fs first
#define sd second
#define mod 998244353
#define EPS 1e-9
using namespace std;

int main() {
	FIO;
	int n; cin >> n;
	vvi v(n + 1);
	map <pii, int> m, arr;
	map <int, pii> r;
	vi in(n + 1);
	FOR(i, 0, n - 2) {
		int a, b; cin >> a >> b;
		arr[{ min(a, b), max(a, b) }] = i;
		v[a].eb(b);
		v[b].eb(a);
		in[a]++, in[b]++;
	}
	int root, val = 0;
	for (int i = 1; i <= n; i++) if (val < in[i]) val = in[i], root = i;
	function <void(int, int)> dfs = [&](int now, int par) {
		int child = 0;
		for (int next : v[now]) {
			child++;
			if (next == par) continue;
			dfs(next, now);
		}
		if(par) m[{child, arr[{min(now, par), max(now, par)}]}] = 1;
	};
	dfs(root, 0);
	vi ans(n - 1); int z = 0;
	for (auto it = m.begin(); it != m.end(); ++it) {
		ans[it->fs.sd] = z++;
	}
	for (int i : ans) cout << i << '\n';
	return 0;
}
