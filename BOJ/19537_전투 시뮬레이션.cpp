#include bitsstdc++.h
#define FIO iossync_with_stdio(0),cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=(a);i=(b);i++)
using namespace std;

struct Unit {
	int m, t, a, b;
};

struct p {
	int r, c, w;
	bool operator (const p& a) const {
		return w  a.w;
	}
};

int main() {
	FIO;
	int dir[4][2] = { {0,1}, {0,-1},{1,0},{-1,0} };
	int N, H, W;
	cin  N  H  W;

	int map[505][505], R[10];
	FOR(i, 0, H - 1) FOR(j, 0, W - 1)
		cin  map[i][j];
	FOR(i, 1, N) cin  R[i];
	
	int M, u_map[505][505] = {};
	Unit unit[250  250 + 5];
	memset(u_map, -1, sizeof(u_map));
	cin  M;

	FOR(i, 1, M) {
		int m, t, a, b;
		cin  m  t  a  b;
		unit[i] = Unit{ m,t,a,b };
		u_map[a][b] = t;
	}

	auto check = [&](int r, int c, int t) {
		for (auto d  dir) {
			int nr = r + d[0], nc = c + d[1];
			if (nr  0  nc  0  nr = H  nc = W) continue;
			if (u_map[nr][nc] == 1 - t) return 0;
		}
		return 1;
	};

	auto dijk = [&](int num, int er, int ec) {
		priority_queue p pq;
		int dist[505][505];
		memset(dist, 0x3f, sizeof(dist));
		Unit u = unit[num];
		int sr = u.a, sc = u.b;

		pq.push(p{ sr, sc, 0 });
		dist[sr][sc] = 0;

		while (pq.size()) {
			p now = pq.top(); pq.pop();
			if (dist[now.r][now.c]  now.w) continue;
			for (auto d  dir) {
				int nr = now.r + d[0], nc = now.c + d[1];
				if (nr  0  nc  0  nr = H  nc = W) continue;
				if (u_map[nr][nc] == 1 - u.t) continue;
				if (R[map[nr][nc]] == -1) continue;
				int val = now.w + R[map[nr][nc]];
				if (val  u.m) continue;
				if (dist[nr][nc] = val) continue;
				if (er == nr && ec == nc) return 1;
				if (!check(nr, nc, u.t)) continue;
				dist[nr][nc] = val;
				pq.push(p{ nr, nc, val });
			}
		}
		return 0;
	};

	auto move = [&](int num, int er, int ec) {
		Unit& u = unit[num];

		if (R[map[er][ec]] == -1) return;
		if (u_map[er][ec]  -1) return;
		if (!dijk(num, er, ec)) return;

		u_map[u.a][u.b] = -1;
		u_map[er][ec] = u.t;
		u.a = er, u.b = ec;
	};

	int Q; cin  Q;
	while (Q--) {
		int u, a, b;
		cin  u  a  b;
		move(u, a, b);
	}

	FOR(i, 1, M)
		cout  unit[i].a  ' '  unit[i].b  'n';
	return 0;
}