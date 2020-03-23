#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define vi vector <int>
#define pii pair <int,int>
#define fs first
#define sd second
#define ep emplace
#define eb emplace_back
using namespace std;

int main() {
	FIO;
	int n, m, s, k; cin >> n >> m >> s >> k;
	vi chk(n + 1, -1), dist(n + 1, 1e9);
	vector <vector <pii>> adj(n + 1);
	FOR(i, 0, 2 * k - 1) {
		int x; cin >> x;
		chk[x] = i / k;
	}
	while (m--) {
		int a, b, w; cin >> a >> b >> w;
		adj[a].eb(w, b);
		adj[b].eb(w, a);
	}
	auto dijkstra = [&]() {
		priority_queue <pii> pq;
		pq.ep(0, s);
		dist[s] = 0;
		while (pq.size()) {
			pii now = pq.top(); pq.pop();
			now.fs = -now.fs;
			if (!chk[now.sd]) return pii(0, now.fs);
			if (chk[now.sd] == 1) {
				while (pq.size()) {
					pii x = pq.top(); pq.pop();
					if (-x.fs == now.fs && !chk[x.sd]) return pii(0, now.fs);
					if (-x.fs != now.fs) break;
				}
				return pii(1, now.fs);
			}
			if (dist[now.sd] < now.fs) continue;
			for (pii next : adj[now.sd]) {
				if (dist[next.sd] > now.fs + next.fs) {
					dist[next.sd] = now.fs + next.fs;
					pq.ep(-dist[next.sd], next.sd);
				}
			}
		}
		return pii(-1,-1);
	};
	pii ans = dijkstra();
	if (ans.fs == -1) cout << -1;
	else cout << (char)(ans.fs + 'A') << '\n' << ans.sd;
 	return 0;
}