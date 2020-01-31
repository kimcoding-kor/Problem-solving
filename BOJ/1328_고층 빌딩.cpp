#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define mod ((int)1e9 + 7)

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, r, l; cin >> n >> l >> r;
	int dp[101][101][101] = {};
	dp[1][1][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][1][i] = dp[i][i][1] = 1;
		for (int j = 1; j <= i; j++)
			for (int k = 1; k <= i; k++)
				dp[i][j][k] = (dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + 1LL * dp[i - 1][j][k] * (i - 2)) % mod;
	}
	cout << dp[n][l][r] << '\n';
	return 0;
}