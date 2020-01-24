#include <cstdio>
#include <cstring>

int map[25][25], n, m, ans;
int ir[4][3] = { { 0,1,1 },{ 0,1,1 },{ 0,0,1 },{ 0,0,1 } };
int ic[4][3] = { { 0,0,1 },{ 0,0,-1 },{ 0,1,1 },{ 0,1,0 } };

void dfs(int r, int c, int cnt) {
	if (!cnt) {
		ans++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j]) continue;
			if (i < r) return;
			if (i == r && j <= c) return;
			for (int a = 0, b; a < 4; a++) {
				for (b = 0; b < 3; b++) {
					int nr = ir[a][b] + i, nc = ic[a][b] + j;
					if (nr < 1 || nr > n || nc < 1 || nc > m) break;
					if (map[nr][nc]) break;
				}
				if (b < 3) continue;
				for (b = 0; b < 3; b++) {
					int nr = ir[a][b] + i, nc = ic[a][b] + j;
					map[nr][nc] = 1;
				}
				dfs(i, j, cnt - 3);
				for (b = 0; b < 3; b++) {
					int nr = ir[a][b] + i, nc = ic[a][b] + j;
					map[nr][nc] = 0;
				}
			}
		}
	}
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		memset(map, 0, sizeof(map));
		int cnt = 0; ans = 0;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				char ch;
				scanf(" %c", &ch);
				if (ch == '#') map[i][j] = 1;
				else cnt++;
			}
		if (cnt % 3) {
			printf("0\n");
			continue;
		}
		dfs(0, 0, cnt);
		printf("%d\n", ans);
	}
	return 0;
}