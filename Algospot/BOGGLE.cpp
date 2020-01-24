#include <cstdio>
#include <cstring>
int dp[55][55][15];
char map[6][6], arr[15];
int ir[] = { -1,-1,-1,0,1,1,1,0 };
int ic[] = { -1,0,1,1,1,0,-1,-1 };

int dfs(int r, int c, int level, int len) {
	int &ref = dp[r][c][level];
	if (level == len) return ref = 1;
	if (ref != -1) return ref;
	for (int i = 0; i < 8; i++) {
		int nr = r + ir[i], nc = c + ic[i];
		if (nr < 1 || nr > 5 || nc < 1 || nc > 5) continue;
		if (arr[level] != map[nr][nc]) continue;
		if (dfs(nr, nc, level + 1, len))
			return ref = 1;
	}
	return ref = 0;
}

int main() {
	int test, n;
	scanf("%d", &test);
	while (test--) {
		for (int i = 1; i <= 5; i++) for (int j = 1; j <= 5; j++) scanf(" %c", &map[i][j]);
		scanf("%d", &n);
		while (n--) {
			memset(dp, -1, sizeof(dp));
			scanf("%s", arr);
			int len = strlen(arr);
			int chk = 0;
			for (int i = 1; i <= 5; i++) {
				for (int j = 1; j <= 5; j++) {
					if (map[i][j] != arr[0]) continue;
					chk = dfs(i, j, 1, len);
					if (chk) break;
				}
				if (chk) break;
			}
			chk ? printf("%s YES\n", arr) : printf("%s NO\n", arr);
		}
	}
	return 0;
}