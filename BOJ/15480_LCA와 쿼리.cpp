#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

#define MAX ((int)log2(n))

vvi adj, par;
vi depth;
int n, m;

void dfs(int now, int level) {
	depth[now] = level;
	for (int next : adj[now]) {
		if (depth[next] != -1) continue;
		par[next][0] = now;
		dfs(next, level + 1);
	}
}

int LCA(int a, int b) {
	if(depth[a] < depth[b]) swap(a, b);
	for (int i = 0; i <= MAX; i++)
		if ((depth[a] - depth[b]) & (1 << i))
			a = par[a][i];
	if (a == b) return a;
	for (int i = MAX; i >= 0; i--) {
		if (par[a][i] == par[b][i]) continue;
		a = par[a][i];
		b = par[b][i];
	}
	return par[a][0];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	adj = vvi(n + 1);
	par = vvi(n + 1, vi(MAX + 1));
	depth = vi(n + 1, -1);
	for (int i = 1, a, b; i < n; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 1);
	for (int i = 1; i <= MAX; i++)
		for (int j = 1; j <= n; j++)
			par[j][i] = par[par[j][i - 1]][i - 1];
	cin >> m;
	while (m--) {
		int a, b, r;
		cin >> r >> a >> b;
		int ab_lca = LCA(a, b);
		int ar_lca = LCA(a, r);
		int br_lca = LCA(b, r);
		int ans = (depth[ab_lca] < depth[ar_lca] ? ar_lca : ab_lca);
		ans = (depth[ans] < depth[br_lca] ? br_lca : ans);
		cout << ans << '\n';
	}
	return 0;
}