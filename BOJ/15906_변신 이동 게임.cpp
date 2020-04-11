#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define vi vector <int>
#define vvi vector <vi>
#define ep emplace
#define eb emplace_back
using namespace std;

struct p {
	int v, w, x;
	bool operator < (const p& a) const {
		return w > a.w;
	}
};

int main() {
	FIO;
	int n, t, er, ec;
	cin >> n >> t >> er >> ec;
	er--, ec--;
	char map[250005];
	int dir[4][2] = { {-1,0}, {0,-1}, {1, 0}, {0,1} };
	vvi adj(n * n), d(n * n, vi(2, 1e9));

	FOR(i, 0, n - 1) FOR(j, 0, n - 1) cin >> map[i * n + j];
	FOR(i, 0, n - 1) FOR(j, 0, n - 1) {
		for (auto a : dir) {
			int cnt = 0;
			FOR(k, 1, n - 1) {
				int nr = i + a[0] * k, nc = j + a[1] * k;
				if (nr < 0 || nc < 0 || nr >= n || nc >= n) break;
				if (k > 1 && map[nr * n + nc] == '.') continue;
				if (map[nr * n + nc] == '#') cnt++;
				adj[i * n + j].eb(nr * n + nc);
				if (cnt) break;
			}
		}
	}

	auto dijkstra = [&]() {
		priority_queue <p> pq;
		pq.ep(p{ 0, 0, 0 });
		d[0][0] = 0;
		while (pq.size()) {
			p i = pq.top(); pq.pop();
			if (i.w > d[i.v][i.x]) continue;
			if (er * n + ec == i.v) return i.w;
			for (int j : adj[i.v]) {
				int chk = 0;
				if (!i.x && abs(i.v - j) != n && abs(i.v - j) != 1) chk = 1;
				if (i.x && map[j] != '#') chk = 1;
				int tt = (!i.x && chk ? t : 0) + 1, nx = chk ^ i.x;
				if (d[j][nx] > i.w + tt) {
					d[j][nx] = i.w + tt;
					pq.ep(p{ j, i.w + tt, nx });
				}
			}
		}
	};

	cout << dijkstra() << '\n';
	return 0;
}