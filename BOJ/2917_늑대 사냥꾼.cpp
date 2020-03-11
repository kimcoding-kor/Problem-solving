#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define vi vector <int>
#define vvi vector <vi>
#define pii pair <int,int>
#define fs first
#define sd second
#define ep emplace
using namespace std;

int main() {
	FIO;
	int n, m; cin >> n >> m;
	char map[505][505];
	queue <pii> q;
	vvi dist, dp;
	dist = dp = vvi(n + 1, vi(m + 1, -1));
	int sr, sc;
	FOR(i, 1, n) FOR(j, 1, m) {
		cin >> map[i][j];
		if (map[i][j] == '+') q.ep(i, j), dist[i][j] = 0;
		if (map[i][j] == 'V') sr = i, sc = j;
	}
	int dir[4][2] = { {-1,0}, {0,-1},{1,0},{0,1} };
	auto bfs = [&]() {
		while (q.size()) {
			pii now = q.front(); q.pop();
			for (auto d : dir) {
				int nr = d[0] + now.fs, nc = d[1] + now.sd;
				if (nr < 1 || nc < 1 || nr > n || nc > m) continue;
				if (dist[nr][nc] != -1) continue;
				dist[nr][nc] = dist[now.fs][now.sd] + 1;
				q.ep(nr, nc);
			}
		}
	};
	bfs();
	vvi visit(n + 1, vi(m + 1));
	auto solve = [&]() {
		priority_queue <pair <int, pii>> pq;
		visit[sr][sc] = 1;
		pq.ep(dist[sr][sc], pii(sr, sc));
		while (pq.size()) {
			auto now = pq.top(); pq.pop();
			for (auto d : dir) {
				int nr = d[0] + now.sd.fs, nc = d[1] + now.sd.sd;
				if (nr < 1 || nc < 1 || nr > n || nc > m) continue;
				if (visit[nr][nc]) continue;
				visit[nr][nc] = 1;
				if (map[nr][nc] == 'J') return min(now.fs, dist[nr][nc]);
				pq.ep(min(now.fs, dist[nr][nc]), pii(nr, nc));
			}
		}
	};
	cout << solve() << '\n';
	return 0;
}