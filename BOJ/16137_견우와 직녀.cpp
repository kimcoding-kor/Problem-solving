#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

struct p {
	int r, c, t, k;
	bool operator< (const p& a) const {
		return t > a.t;
	}
};

int main() {
	FIO;
	
	int n, m;
	cin >> n >> m;

	int map[15][15];
	FOR(i, 1, n) FOR(j, 1, n)
		cin >> map[i][j];

	int dir[][2] = { {-1,0}, {0,-1},{1,0},{0,1} };

	auto isRange = [&](int a, int b) {
		return !(a < 1 || b < 1 || a > n || b > n);
	};

	auto isPos = [&](int r, int c) {
		int cnt = 0, idx = -1;
		FOR(i,0,3) {
			int nr = r + dir[i][0], nc = c + dir[i][1];
			if (!isRange(nr, nc)) continue;
			if (map[nr][nc] != 1) {
				if (cnt && abs(i - idx) != 2) return false;
				cnt++, idx = i;
			}
		}
		return true;
	};

	auto solve = [&]() {
		bool visit[15][15][2] = {};
		priority_queue <p> pq;
		pq.push(p{ 1,1,0,0 });
		
		while (pq.size()) {
			p now = pq.top(); pq.pop();
			if (now.r == n && now.c == n) return now.t;

			for (auto d : dir) {
				int nr = now.r + d[0], nc = now.c + d[1], nk = now.k, nt = now.t + 1;
				if (!isRange(nr, nc)) continue;

				int c = map[nr][nc];

				if (c > 1) {
					if (map[now.r][now.c] != 1) continue;
					nt = now.t + c - now.t % c;
				}
				if (!c) {
					if (now.k || !isPos(nr,nc)) continue;
					nk = 1;
					nt = now.t + m - now.t % m;
				}

				if (visit[nr][nc][nk]) continue;
				visit[nr][nc][nk] = true;

				pq.push(p{ nr,nc,nt,nk });
			}
		}
	};

	cout << solve() << '\n';

	return 0;
}