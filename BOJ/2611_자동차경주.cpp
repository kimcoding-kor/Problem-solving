#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

int main() {
	FIO;
	int n, m;
	cin >> n >> m;

	vector <vector <pair <int, int>>> adj(n + 1);

	while (m--) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({ b,w });
	}

	int dp[1005], path[1005];
	memset(dp, -1, sizeof(dp));

	function <int(int)> dfs = [&](int now) {
		int& ret = dp[now];
		if (ret != -1) return ret;

		ret = 0;
		int Max = 0;

		for (auto next : adj[now]) {
			int v = next.first, w = next.second;
			int val = ((v == 1) ? 0 : dfs(v)) + w;
			if (Max < val) {
				Max = val;
				path[now] = v;
			}
		}

		return ret += Max;
	};

	cout << dfs(1) << '\n' << 1 << ' ';

	for (int i = path[1]; i != 1; i = path[i])
		cout << i << ' ';
	cout << 1 << '\n';

	return 0;
}