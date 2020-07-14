#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define mod ((int)1e9 + 7)
using namespace std;

int main() {
	FIO;
	int n, m, k;
	cin >> n >> m >> k;

	vector <vector <pair <int, int>>> adj(n + 1);
	bool visit[1005] = {};
	int a[1005];

	FOR(i, 1, k) cin >> a[i];
	while (m--) {
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({ w, y });
		adj[y].push_back({ w, x });
	}

	priority_queue <pair<int, int>> pq;
	FOR(i, 1, k) pq.push({ 0, a[i] });

	auto prim = [&]() {
		int ret = 0;
		while (pq.size()) {
			auto now = pq.top(); pq.pop();
			if (visit[now.second]) continue;
			visit[now.second] = true;
			ret += -now.first;

			for (auto next : adj[now.second]) {
				int v = next.second, w = next.first;
				pq.push({ -w,v });
			}
		}
		return ret;
	};

	cout << prim() << '\n';
	return 0;
}