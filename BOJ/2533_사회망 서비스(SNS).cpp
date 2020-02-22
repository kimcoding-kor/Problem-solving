#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define vi vector <int>
#define vvi vector <vi>
#define eb emplace_back
using namespace std;

int main() {
	FIO;
	int n; cin >> n;
	vvi adj(n + 1), dp(n + 1, vi(2, -1));
	vi visit(n + 1);
	for (int i = 1, a, b; i < n; i++) {
		cin >> a >> b;
		adj[a].eb(b);
		adj[b].eb(a);
	}
	function <int(int, int)> DP = [&](int now, int PisE) {
		int& ret = dp[now][PisE];
		if (ret != -1) return ret;
		int yes = 0, no = 0; ret = 1e9;
		visit[now] = 1;
		for (int next : adj[now]) {
			if (visit[next]) continue;
			yes += DP(next, 1);
			no += DP(next, 0);
		}
		visit[now] = 0;
		return ret = min({ ret, yes + 1, (PisE ? no : ret) });
	};
	cout << min(DP(1, 0), DP(1, 1)) << '\n';
	return 0;
}