#include <cstdio>
#include <cstring>

int dp[105][105], map[105][105];

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		int n;
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		memset(map, 0, sizeof(map));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &map[i][j]);
		dp[1][1] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!dp[i][j]) continue;
				if (i + map[i][j] <= n)
					dp[i + map[i][j]][j] = 1;
				if (j + map[i][j] <= n)
					dp[i][j + map[i][j]] = 1;
			}
		}
		dp[n][n] ? printf("YES\n") : printf("NO\n");
	}
	return 0;
}