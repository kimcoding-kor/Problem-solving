#include <cstdio>
#include <cstring>

int map[105][15], visit[105][15], n, k;
bool check[1005];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

int dfs(int r, int c, int x) {
	int cnt = 1;
	visit[r][c] = x;
	for (auto d : dir) {
		int nr = r + d[0], nc = c + d[1];
		if (nr < 1 || nc < 1 || nr > n || nc > 10) continue;
		if (visit[nr][nc] || map[nr][nc] != map[r][c]) continue;
		cnt += dfs(nr, nc, x);
	}
	return cnt;
}

void move() {
	for (int i = 1; i<=10; i++) {
		int low = n, high = n;
		while (high) {
			while (high && !map[high][i]) high--;
			if (high)
				map[low--][i] = map[high--][i];
		}
		while (low) map[low--][i] = 0;
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= 10; j++)
		scanf("%1d", &map[i][j]);
	while (1) {
		int chk = 0, flag = 0;
		memset(visit, 0, sizeof(visit));
		memset(check, 0, sizeof(check));
		for (int i = 1; i <= n; i++) for (int j = 1; j <= 10; j++)
			if (map[i][j] && !visit[i][j]) {
				int cnt = dfs(i, j, ++chk);
				check[chk] = (cnt >= k);
			}
		for (int i = 1; i <= n; i++) for (int j = 1; j <= 10; j++)
			if (check[visit[i][j]]) map[i][j] = 0, flag = 1;
		if (!flag) break;
		move();
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 10; j++)
			printf("%d", map[i][j]);
		printf("\n");
	}
	return 0;
}