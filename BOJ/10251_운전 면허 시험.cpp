#include <cstdio>
#include <cstring>
#define min(a,b) (a < b ? a : b)
#define FOR(i,a,b) for(int i = a;i <= b; i++)
#define DOWN 0
#define RIGHT 1

int map[105][105][2], dp[105][105][205][2];
int m, n, l, g;

int check() {
	auto& ndp = dp[m][n];
	FOR(k, 1, min(m - 1, n - 1) * 2)
		if (ndp[k][DOWN] <= g || ndp[k][RIGHT] <= g)
			return (m + n - 2) * l + k;
	return -1;
}

int solve() {
	dp[1][1][0][DOWN] = dp[1][1][0][RIGHT] = 0;
	FOR(i, 1, m) FOR(j, 1, n) FOR(k, 0, min(m - 1, n - 1) * 2) {
		auto& ndp = dp[i][j][k], &nmp = map[i][j];
		if (i < m) {
			dp[i + 1][j][k][DOWN] = min(dp[i + 1][j][k][DOWN], ndp[DOWN] + nmp[DOWN]);
			dp[i + 1][j][k + 1][DOWN] = min(dp[i + 1][j][k + 1][DOWN], ndp[RIGHT] + nmp[DOWN]);
		}
		if (j < n) {
			dp[i][j + 1][k + 1][RIGHT] = min(dp[i][j + 1][k + 1][RIGHT], ndp[DOWN] + nmp[RIGHT]);
			dp[i][j + 1][k][RIGHT] = min(dp[i][j + 1][k][RIGHT], ndp[RIGHT] + nmp[RIGHT]);
		}
	}
	return check();
}

int main() {
	int test; scanf("%d", &test);
	while (test--) {
		scanf("%d %d %d %d", &m, &n, &l, &g);
		FOR(i, 1, m) FOR(j, 1, n - 1)
			scanf("%d", &map[i][j][RIGHT]);
		FOR(i, 1, m - 1) FOR(j, 1, n)
			scanf("%d", &map[i][j][DOWN]);
		memset(dp, 0x3f3f, sizeof(dp));
		printf("%d\n", solve());
	}
	return 0;
}