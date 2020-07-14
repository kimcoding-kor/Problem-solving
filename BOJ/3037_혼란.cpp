#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define mod ((int)1e9 + 7)
using namespace std;

int main() {
	FIO;
	int n, m;
	cin >> n >> m;
	
	int dp[2][10005] = {};
	dp[0][0] = 1;

	FOR(i, 2, n) {
		dp[1][0] = 1;
		FOR(j, 1, m) {
			int val = (j - i) < 0 ? 0 : dp[0][j - i];
			dp[1][j] = (1ll * dp[1][j - 1] + dp[0][j] - val + mod) % mod;
		}
		FOR(j, 0, m) dp[0][j] = dp[1][j];
	}

	cout << dp[0][m] << '\n';
	return 0;
}