#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int test; scanf("%d", &test);
	while (test--) {
		int dp[105][105], ans = 0;
		memset(dp, 0, sizeof(dp));
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				scanf("%d", &dp[i][j]);
				dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
				ans = max(ans, dp[i][j]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}