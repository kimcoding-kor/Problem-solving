#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
	FIO;
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		int dp[505][505] = {}, sum[505] = {};
		FOR(i, 1, n) {
			int x; cin >> x;
			sum[i] = sum[i - 1] + x;
		}
		FOR(k, 1, n) FOR(i, 1, n - k) {
			dp[i][i + k] = INT_MAX;
			FOR(j, i, i + k - 1)
				dp[i][i + k] = min(dp[i][i + k], dp[i][j] + dp[j + 1][i + k] + sum[i + k] - sum[i - 1]);
		}
		cout << dp[1][n] << '\n';
	}
	return 0;
}