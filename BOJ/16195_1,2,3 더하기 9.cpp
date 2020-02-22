#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define mod ((int)1e9 + 9)
using namespace std;

int main() {
	FIO;
	int dp[1005][1005] = {};
	dp[1][1] = dp[2][1] = dp[3][1] = dp[2][2] = 1;
	for (int i = 3; i <= 1001; i++)
		for (int j = 2; j <= 1001; j++)
			dp[i][j] = (1LL * dp[i - 1][j - 1] + dp[i - 2][j - 1] + dp[i - 3][j - 1]) % mod;
	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m;
		int sum = 0;
		for (int i = 1; i <= m; i++) sum = (sum + dp[n][i]) % mod;
		cout << sum << '\n';
	}
	return 0;
}