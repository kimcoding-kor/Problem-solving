#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int dp[1005][3], rgb[1005][3], n, ans = 1e9;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
	for (int t = 0; t < 3; t++) {
		memset(dp, 0x3f3f, sizeof(dp));
		for (int i = 0; i < 3; i++)
			if (i != t) dp[2][i] = rgb[2][i] + rgb[1][t];
		for (int i = 3; i <= n; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
			dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + rgb[i][2];
		}
		for (int i = 0; i < 3; i++)
			if (i != t) ans = min(ans, dp[n][i]);
	}
	cout << ans << '\n';
	return 0;
}