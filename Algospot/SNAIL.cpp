#include <cstdio>

double dp[1005][1005];

void get_dp() {
	dp[0][0] = 1;
	for (int i = 1; i <= 1000; i++) {
		dp[0][i] = dp[0][i - 1] * 0.25;
		for (int j = 1; j < i; j++) {
			double &ref = dp[j][i];
			ref += dp[j - 1][i - 1] * 0.75;
			ref += dp[j][i - 1] * 0.25;
		}
		dp[i][i] = dp[i - 1][i - 1] * 0.75;
	}
}

int main() {
	get_dp();
	int test; scanf("%d", &test);
	while (test--) {
		int n, m;
		scanf("%d %d", &n, &m);
		double ans = 0;
		for (int i = 0; i <= m; i++)
			if ((m-i) + (i*2) >= n)
				ans += dp[i][m];
		printf("%.8f\n", ans);
	}
	return 0;
}