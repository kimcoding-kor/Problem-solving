#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define vi vector <int>
#define vvi vector <vi>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define fs first
#define sd second
#define eb emplace_back
using namespace std;

int main() {
	FIO;
	int n; cin >> n;
	vi v(n + 1), path;
	vvi adj(n + 1);
	vector <pii> dp(n + 1);
	FOR(i, 1, n) cin >> v[i];
	FOR(i, 1, n - 1) {
		int a, b; cin >> a >> b;
		adj[a].eb(b);
		adj[b].eb(a);
	}
	function <pii(int, int)> DP = [&](int now, int par) {
		pii& ret = dp[now] = { 0,v[now] };
		for (int next : adj[now]) {
			if (next == par) continue;
			pii val = DP(next, now);
			ret.fs += max(val.fs, val.sd);
			ret.sd += val.fs;
		}
		return ret;
	};
	function <void(int,int,int)> trace = [&](int now, int par, int chk){
		if (!chk && dp[now].fs < dp[now].sd) path.eb(now), chk = 1;
		else chk = 0;
		for (int next : adj[now]) {
			if (next == par) continue;
			trace(next, now, chk);
		}
	};
	pii ans = DP(1, 0);
	cout << max(ans.fs, ans.sd) << '\n';
	trace(1, 0, 0);
	sort(all(path));
	for (int i : path) cout << i << ' ';
	return 0;
}