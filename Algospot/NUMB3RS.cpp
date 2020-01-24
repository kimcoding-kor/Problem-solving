#include <cstdio>
#include <cstring>

int map[55][55], cnt[55], n, d, st, t;
double dp[55][105];

void get_dp() {
	dp[st][0] = 1.0;
	for (int day = 0; day < d; day++) {
		for (int now = 0; now < n; now++) {
			if (!dp[now][day]) continue;
			for (int next = 0; next < n; next++) {
				if (!map[now][next]) continue;
				dp[next][day + 1] += (1.0 / cnt[now]) * dp[now][day];
			}
		}
	}
}

int main() {
	int test; scanf("%d", &test); while (test--) {
		memset(dp, 0, sizeof(dp));
		memset(cnt, 0, sizeof(cnt));
		scanf("%d %d %d", &n, &d, &st);
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j]) cnt[i]++;
		}
		get_dp();
		scanf("%d", &t);
		for (int i = 1, x; i <= t; i++) {
			scanf("%d", &x);
			printf("%.8f ", dp[x][d]);
		}
		printf("\n");
	}
	return 0;
}