#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()

vvi adj, dp;
vi w, ans;

int dfs(int now, int pick, int child) {
	int& ret = dp[now][pick];
	if (ret != -1) return ret;
	ret = 0;
	for (auto& next : adj[now]) {
		if (next == child) continue;
		int val = dfs(next, pick ^ 1, now);
		if (!pick) val = max(val, dfs(next, pick, now));
		ret += val;
	}
	return ret += (pick ? w[now] : 0);
}

void path(int now, int pick, int child) {
	for (auto& next : adj[now]) {
		if (next == child) continue;
		if (!pick && dp[next][1] > dp[next][0])
			path(next, 1, now);
		else path(next, 0, now);
	}
	if (pick) ans.push_back(now);
}

int main() {
	int n; scanf("%d", &n);
	adj = vvi(n + 1);
	dp = vvi(n + 1, vi(2, -1));
	w = vi(n + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for (int i = 1,a,b; i < n; i++) {
		scanf("%d %d", &a, &b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1, 1, 0) > dfs(1, 0, 0) ? path(1, 1, 0) : path(1, 0, 0);
	sort(all(ans));
	printf("%d\n", max(dp[1][0], dp[1][1]));
	for (auto& now : ans) printf("%d ", now);
	return 0;
}