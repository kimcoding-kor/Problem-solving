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
#define eb emplace_back
using namespace std;

int main() {
	FIO;
	int n, m; cin >> n >> m;
	vvi adj(n + 1);
	vi dfsn(n + 1);
	vector <pii> ans;
	int cnt = 0;
	while (m--) {
		int a, b; cin >> a >> b;
		adj[a].eb(b);
		adj[b].eb(a);
	}
	function <int(int, int)> get_point = [&](int now, int par) {
		int ret = dfsn[now] = ++cnt;
		for (int next : adj[now]) {
			if (next == par) continue;
 			if (dfsn[next]) ret = min(ret, dfsn[next]);
			else {
				int val = get_point(next, now);
				if (val > dfsn[now])
					ans.eb(pii{ min(now,next),max(now,next) });
				ret = min(ret, val);
			}
		}
		return ret;
	};
	FOR(i, 1, n)
		if (!dfsn[i]) get_point(i, 0);
	cout << ans.size() << '\n';
	sort(all(ans));
	for (pii i : ans) cout << i.fs << ' ' << i.sd << '\n';
	return 0;
}