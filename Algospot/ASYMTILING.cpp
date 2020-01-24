#include <cstdio>
#define mod 1000000007
int dp[105];

void get_dp() {
	dp[1] = 1, dp[2] = 2;
	for (int i = 3; i <= 100; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
}

int main() {
	get_dp();
	int test; scanf("%d", &test);
	while (test--) {
		int n; scanf("%d", &n);
		if (n < 3)
			printf("0\n");
		else if (n & 1)
			printf("%d\n", ((dp[n] + mod) - dp[(n - 1) / 2]) % mod);
		else
			printf("%d\n", ((dp[n] + mod) - (dp[n / 2] + dp[(n - 2) / 2]) % mod) % mod);
	}
	return 0;
}