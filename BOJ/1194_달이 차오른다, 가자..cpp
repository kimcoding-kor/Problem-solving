#include <cstdio>
#include <queue>

typedef struct p { int r, c, dis, k; }p;

int n, m;
bool dp[51][51][1 << 6];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
char map[51][51];
p start;

int bfs() {
	std ::queue <p> q;
	q.push(p{ start.r,start.c,0,0 });
	dp[start.r][start.c][0] = 1;
	while (q.size()) {
		p now = q.front(); q.pop();
		for (auto d : dir) {
			int nr = now.r + d[0], nc = now.c + d[1], nd = now.dis + 1, nk = now.k;
			if (nr < 1 || nr > n || nc < 1 || nc > m) continue;
			if (dp[nr][nc][nk]) continue;
			if (map[nr][nc] == '#') continue;
			if (map[nr][nc] >= 'A'  && map[nr][nc] <= 'F' && !(nk & 1 << (map[nr][nc] - 'A'))) continue;
			if (map[nr][nc] >= 'a'  && map[nr][nc] <= 'f') nk |= 1 << (map[nr][nc] - 'a');
			if (map[nr][nc] == '1') return nd;
			dp[nr][nc][nk] = 1;
			q.push(p{ nr,nc,nd,nk });
		}
	}
	return -1;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == '0') start = p{ i,j,0,0 };
		}
	printf("%d\n", bfs());
	return 0;
}