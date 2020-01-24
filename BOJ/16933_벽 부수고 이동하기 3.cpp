#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct p { int r, c, dis, wall; }p;

int n, m, k;
bool map[1001][1001];
int dp[1001][1001][11];
int dir[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };

int bfs() {
	dp[1][1][0] = 1;
	queue <p> q;
	q.push(p{ 1,1,1,0 });
	while (q.size()) {
		p now = q.front(); q.pop();
		if (now.r == n && now.c == m) return now.dis;
		for (auto d : dir) {
			int nr = now.r + d[0], nc = now.c + d[1], nd = now.dis + 1, nw = now.wall;
			if (nr < 1 || nr > n || nc < 1 || nc > m) continue;
			if (map[nr][nc]) {
				if (++nw > k) continue;
				if (nd & 1) nr = now.r, nc = now.c, nw--;
				else if (nd < dp[nr][nc][nw]) dp[nr][nc][nw] = nd;
				else continue;
			}
			else if (nd < dp[nr][nc][nw]) dp[nr][nc][nw] = nd;
			else continue;
			q.push(p{ nr,nc,nd,nw });
		}
	}
	return -1;
}

int main() {
	memset(dp, 0x3f3f, sizeof(dp));
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		scanf("%1d", &map[i][j]);
	printf("%d\n", bfs());
	return 0;
}