#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
	FIO;
	int n, sum = 0, dp[105][105] = {};
	cin >> n;
	dp[2][1] = 2;
	FOR(i, 3, n) FOR(j, 1, i)
		dp[i][j] = (dp[i - 1][j] * 2 + dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 10007;
	FOR(i, 1, n) sum += dp[n][i];
	cout << sum % 10007 << '\n';
	return 0;
}