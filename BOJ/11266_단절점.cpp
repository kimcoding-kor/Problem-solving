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
	vi dfsn(n + 1), ans;
	int cnt = 0;
	while (m--) {
		int a, b; cin >> a >> b;
		adj[a].eb(b);
		adj[b].eb(a);
	}
	function <int(int, bool)> get_point = [&](int now, bool root) {
		int ret = dfsn[now] = ++cnt;
		int child = 0, flag = 0;
		for (int next : adj[now]) {
			if (dfsn[next]) ret = min(ret, dfsn[next]);
			else {
				child++;
				int val = get_point(next, 0);
				if (!root && val >= dfsn[now]) flag = 1;
				ret = min(ret, val);
			}
		}
		if (root && child > 1) ans.eb(now);
		else if (flag) ans.eb(now);
		return ret;
	};
	FOR(i, 1, n)
		if (!dfsn[i]) get_point(i, 1);
	cout << ans.size() << '\n';
	sort(all(ans));
	for (int i : ans) cout << i << ' ';
	return 0;
}