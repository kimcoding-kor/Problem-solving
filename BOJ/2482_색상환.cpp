#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define mod ((int)1e9 + 3)

int dp[1005][505];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, k; cin >> n >> k;
	if (k > (n + 1) / 2)
		cout << 0 << '\n';
	else if (k == 1) cout << n << '\n';
	else {
		for (int i = 1; i <= n; i++) dp[i][1] = i;
		for (int i = 2; i <= n; i++)
			for (int j = 2; j <= k && j <= (i + 1) / 2; j++)
				dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % mod;
		cout << (dp[n - 1][k] + dp[n - 3][k - 1]) % mod << '\n';
	}
	return 0;
}