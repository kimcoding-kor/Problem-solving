#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
	FIO;
	int t; cin >> t; while (t--) {
		int n, w; cin >> n >> w;
		int dp[10005][3], arr[20005], ans = 1e9;
		FOR(i, 1, 2 * n) cin >> arr[i];
		if (n == 1) {
			cout << ((arr[1] + arr[n + 1]) <= w ? 1 : 2) << '\n';
			continue;
		}
		FOR(k, 1, 4) {
			memset(dp, 0x3f, sizeof(dp));
			if (k == 1)
				dp[1][1] = 1, dp[1][2] = 1, dp[1][0] = ((arr[1] + arr[n + 1]) <= w ? 1 : 2);
			else if (k == 2) {
				if (arr[1] + arr[n] <= w) dp[1][2] = 1, dp[1][0] = 2;
				else continue;
			}
			else if (k == 3) {
				if (arr[n + 1] + arr[2 * n] <= w) dp[1][1] = 1, dp[1][0] = 2;
				else continue;
			}
			else {
				if (arr[1] + arr[n] <= w && arr[n + 1] + arr[2 * n] <= w) dp[1][0] = 2;
				else continue;
			}
			dp[0][0] = 0;
			FOR(i, 2, n) {
				int val = (arr[i] + arr[i + n] <= w) ? 1 : 2;
				dp[i][0] = dp[i - 1][0] + val;
				dp[i][1] = dp[i][2] = dp[i - 1][0] + 1;
				val = (arr[i + n - 1] + arr[i + n] <= w) ? 1 : 2;
				dp[i][1] = min(dp[i][1], dp[i - 1][2] + val);
				dp[i][0] = min(dp[i][0], dp[i - 1][2] + val + 1);
				val = (arr[i] + arr[i - 1] <= w) ? 1 : 2;
				dp[i][2] = min(dp[i][2], dp[i - 1][1] + val);
				dp[i][0] = min(dp[i][0], dp[i - 1][1] + val + 1);
				if ((i > 2 || k == 1) && arr[i + n - 1] + arr[i + n] <= w && arr[i] + arr[i - 1] <= w)
					dp[i][0] = min(dp[i][0], dp[i - 2][0] + 2);
			}
			if (k == 1) ans = min(ans, dp[n][0]);
			if (k == 2) ans = min(ans, dp[n][1]);
			if (k == 3) ans = min(ans, dp[n][2]);
			if (k == 4) ans = min(ans, dp[n - 1][0]);
		}
		cout << ans << '\n';
	}
	return 0;
}