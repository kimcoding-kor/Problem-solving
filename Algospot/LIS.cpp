#include <cstdio>
#define max(a,b) a > b ? a : b;
int dp[505],arr[505];
int main() {
	int test; scanf("%d", &test);
	while (test--) {
		int n; scanf("%d", &n);
		int ans = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &arr[i]);
		for (int i = 1; i <= n; i++) {
			dp[i] = 1;
			for (int j = 1; j < i; j++) {
				if (arr[i] > arr[j])
					dp[i] = max(dp[i], dp[j] + 1);
			}
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}