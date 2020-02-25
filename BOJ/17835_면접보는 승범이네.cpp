#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
#define vi vector <int>
#define vvi vector <vi>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fs first
#define sd second
#define eb emplace_back
using namespace std;

int main() {
	FIO;
	int n, m, k; cin >> n >> m >> k;
	vector <vector <pii>> adj(n + 1);
	FOR(i, 1, m) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[b].eb(w, a);
	}
	priority_queue <pll> q;
	vector <ll> dist(n + 1, 1e18);
	FOR(i, 1, k) {
		int x; cin >> x;
		q.emplace(0, x);
		dist[x] = 0;
	}
	while (q.size()) {
		pll now = q.top(); q.pop();
		now.fs = -now.fs;
		if (dist[now.sd] < now.fs) continue;
		for (pii next : adj[now.sd]) {
			if (dist[next.sd] <= dist[now.sd] + next.fs) continue;
			dist[next.sd] = dist[now.sd] + next.fs;
			q.emplace(-dist[next.sd], next.sd);
		}
	}
	pll ans = { 0, 1e18 };
	for (int i = 1; i <= n; i++)
		if (dist[i] > ans.fs) ans = { dist[i], i };
	cout << ans.sd << '\n' << ans.fs << '\n';
	return 0;
}