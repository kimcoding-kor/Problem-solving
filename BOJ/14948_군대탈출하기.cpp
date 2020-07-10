#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

struct p {
	int r, c, lv, jump;
	bool operator< (const p& a) const {
		return lv > a.lv;
	}
};

int main() {
	FIO;
	int n, m;
	cin >> n >> m;

	int map[105][105];
	FOR(i, 1, n) FOR(j, 1, m)
		cin >> map[i][j];

	int dir[][2] = { {-1,0},{0,-1},{1,0},{0,1} };
	bool visit[105][105][2] = {};

	auto solve = [&]() {
		priority_queue <p> pq;
		pq.push(p{ 1,1,map[1][1],1 });
		visit[1][1][1] = true;
		while (pq.size()) {
			p now = pq.top(); pq.pop();
			if (now.r == n && now.c == m) return now.lv;
			for (auto d : dir) {
				FOR(k, 1, 2) {
					if (k == 2 && !now.jump) continue;
					int nr = now.r + d[0] * k, nc = now.c + d[1] * k;
					int nj = now.jump - (k == 2);
					if (nr < 1 || nc < 1 || nr > n || nc > m) continue;
					if (visit[nr][nc][nj]) continue;
					visit[nr][nc][nj] = true;
					pq.push(p{ nr,nc,max(now.lv, map[nr][nc]), nj });
				}
			}
		}
	};

	cout << solve() << '\n';

	return 0;
}