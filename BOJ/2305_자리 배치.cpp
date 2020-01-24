#include <cstdio>

int fibo[45], fibo_sum[45], dp[45], n, k;

int main() {
	scanf("%d %d", &n, &k);
	fibo[0] = fibo[1] = fibo_sum[0] = 1;
	fibo_sum[1] = 2;
	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fibo_sum[i] = fibo_sum[i - 1] + fibo[i];
	}
	dp[0] = dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + fibo_sum[i - 2] + fibo_sum[i - 3];
	printf("%d\n", dp[n - k + 1] * fibo[k - 1] + dp[k] * fibo[n - k] - fibo[k - 1] * fibo[n - k]);
	return 0;
}