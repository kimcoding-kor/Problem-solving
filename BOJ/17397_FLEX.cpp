#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define power(a,b) (a <= b ? 0 : (a - b) * (a - b))

int dp[1005][215][15], arr[1005], n, m;

int dfs(int now, int cost, int pre) {
	if (now == n + 1) return 0;
	int& ret = dp[now][cost][pre];
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = 0; i <= cost; i++) {
		if (arr[now] + i > 10) break;
		int val = dfs(now + 1, cost - i, arr[now] + i);
		ret = min(ret, val + power(pre, (arr[now] + i)));
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	arr[n + 1] = 100;
	cout << dfs(1, m, 0) << '\n';
	return 0;
}