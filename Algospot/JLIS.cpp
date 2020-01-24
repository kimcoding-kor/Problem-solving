#include <cstdio>
#include <climits>
#include <cstring>
#define max(a,b) (a < b ? b : a)

int a[105], b[105];
int dp[105][105];
int n, m;

int dfs(int a_idx, int  b_idx) {
	int &ret = dp[a_idx][b_idx];
	if (ret != -1) return ret;
	int Max = max(a[a_idx], b[b_idx]);
	ret = 0;
	for (int i = a_idx + 1; i <= n; i++)
		if (Max < a[i]) ret = max(ret, dfs(i, b_idx) + 1);
	for (int i = b_idx + 1; i <= m; i++)
		if (Max < b[i]) ret = max(ret, dfs(a_idx, i) + 1);
	return ret;
}

int main() {
	int test; scanf("%d", &test);
	while (test--) {
		memset(dp, -1, sizeof(dp));
		scanf("%d %d", &n, &m);
		a[0] = b[0] = INT_MIN;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
		printf("%d\n", dfs(0, 0));
	}
	return 0;
}