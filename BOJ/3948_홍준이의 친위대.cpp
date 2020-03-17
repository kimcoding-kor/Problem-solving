#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
using namespace std;

int main() {
	FIO;
	ll dp[25][25] = {};
	dp[1][0] = 1;
	FOR(i, 2, 20) FOR(j, 0, i - 1) {
		int a, b;
		if (i & 1) a = j, b = i - 1;
		else a = 0, b = j - 1;
		FOR(k, a, b) dp[i][j] += dp[i - 1][k];
	}
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		ll ans = 0;
		FOR(i, 0, n - 1) ans += dp[n][i];
		cout << ((n == 1) ? 1 : ans * 2) << '\n';
	}
    return 0;
}