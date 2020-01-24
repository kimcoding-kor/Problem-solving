#include <cstdio>

double dp[20][20][20], a, b, ans;
bool prime[20] = { 0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1 };

int main() {
	scanf("%lf %lf", &a, &b);
	a /= 100, b /= 100;
	dp[0][0][0] = 1;
	for (int i = 0; i < 18; i++)
		for (int j = 0; j <= i; j++)
			for (int k = 0; k <= i; k++) {
				double &ref = dp[i][j][k];
				dp[i + 1][j][k] += ref * (1 - a) * (1 - b);
				dp[i + 1][j + 1][k] += ref * a * (1 - b);
				dp[i + 1][j][k + 1] += ref * (1 - a) * b;
				dp[i + 1][j + 1][k + 1] += ref * a * b;
			}
	for (int i = 0; i <= 18; i++)
		for (int j = 0; j <= 18; j++)
			ans += dp[18][i][j] * (prime[i] || prime[j]);
	printf("%.11f\n", ans);
	return 0;
}