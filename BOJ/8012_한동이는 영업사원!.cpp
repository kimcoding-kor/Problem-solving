#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

#define MAX ((int)log2(n))

vvi par, adj;
vi depth;
int n, m;

void dfs(int now, int level) {
	depth[now] = level;
	for (auto next : adj[now]) {
		if (depth[next] != -1) continue;
		par[next][0] = now;
		dfs(next, level + 1);
	}
}

int LCA(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	for (int i = 0; i <= MAX; i++)
		if ((depth[a] - depth[b]) & (1 << i))
			a = par[a][i];
	if (a == b) return a;
	for (int i = MAX; i >= 0; i--)
		if (par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	return par[a][0];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	par = vvi(n + 1, vi(MAX + 1));
	adj = vvi(n + 1);
	depth = vi(n + 1 , -1);
	for (int i = 1, a, b; i < n; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cin >> m;
	dfs(1, 1);
	for (int j = 1; j <= MAX; j++)
		for (int i = 1; i <= n; i++)
			par[i][j] = par[par[i][j - 1]][j - 1];
	int pre = 1, ans = 0;
	while (m--) {
		int now; cin >> now;
		ans += (depth[now] + depth[pre] - 2 * depth[LCA(pre, now)]);
		pre = now;
	}
	cout << ans << '\n';
	return 0;
}