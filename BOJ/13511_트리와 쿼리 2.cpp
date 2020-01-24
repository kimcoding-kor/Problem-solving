#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

struct p {
	int node, weight;
};

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <ll> vll;
typedef vector <p> vp;
typedef vector <vp> vvp;

#define MAX ((int)log2(n))

vvp adj;
vvi par;
vi depth;
vll dist;
int n, m;

void dfs(int now, int level, ll sum) {
	depth[now] = level;
	dist[now] = sum;
	for (auto next : adj[now]) {
		if (depth[next.node] != -1) continue;
		par[next.node][0] = now;
		dfs(next.node, level + 1, sum + next.weight);
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

int node_k(int k, int lca, int a, int b) {
	int ad = depth[a] - depth[lca];
	int bd = depth[b] - depth[lca];
	if (ad == k) return lca;
	int ans;
	if (k < ad) ans = a;
	else ans = b, k = ad + bd - k;
	for (int i = 0; i <= MAX; i++)
		if (k & (1 << i)) ans = par[ans][i];
	return ans;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	par = vvi(n + 1, vi(MAX + 1));
	adj = vvp(n + 1);
	depth = vi(n + 1 , -1);
	dist = vll(n + 1, -1);
	for (int i = 1, a, b, w; i < n; i++) {
		cin >> a >> b >> w;
		adj[a].push_back(p{ b,w });
		adj[b].push_back(p{ a,w });
	}
	cin >> m;
	dfs(1, 1, 1LL * 0);
	for (int j = 1; j <= MAX; j++)
		for (int i = 1; i <= n; i++)
			par[i][j] = par[par[i][j - 1]][j - 1];
	while (m--) {
		int x, a, b, k;
		cin >> x >> a >> b;
		int lca = LCA(a, b);
		if (x == 1) 
			cout << dist[a] + dist[b] - 2 * dist[lca] << '\n';
		else {
			cin >> k;
			cout << node_k(k - 1, lca, a, b) << '\n';
		}
	}
	return 0;
}