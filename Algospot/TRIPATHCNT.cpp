#include <cstdio>
#include <cstring>

typedef struct p {
	int val, cnt;
}p;

p dp[105][105];
int arr[105][105], n;

p max(p a, p b) {
	if (a.val == b.val) 
		return p{ a.val, a.cnt + b.cnt };
	else if (a.val < b.val) return b;
	else return a;
}

p dfs(int r, int c) {
	p &ret = dp[r][c];
	if (ret.val) return ret;
	if (r == n) {
		ret.val = arr[r][c];
		ret.cnt = 1;
		return ret;
	}
	p a = dfs(r + 1, c);
	p b = dfs(r + 1, c + 1);
	ret = max(a, b);
	ret.val += arr[r][c];
	return ret;
}

int main() {
	int test; scanf("%d", &test);
	while (test--) {
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= i; j++)
				scanf("%d", &arr[i][j]);
		printf("%d\n", dfs(1, 1).cnt);
	}
	return 0;
}