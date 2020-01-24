#include <cstdio>
#define mod 1000000007
int dp[105];

int main() {
	int test; scanf("%d", &test);
	dp[1] = 1, dp[2] = 2;
	for (int i = 3; i <= 100; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	while (test--) {
		int n; scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
	return 0;
}