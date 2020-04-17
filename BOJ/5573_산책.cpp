#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
using namespace std;

int main() {
	FIO;
	int n, m, k;
	cin >> n >> m >> k;
	int dp[1005][1005] = {}, map[1005][1005];
	FOR(i, 1, n) FOR(j, 1, m) cin >> map[i][j];

	dp[1][1] = k - 1;
	FOR(i, 1, n) FOR(j, 1, m) {
		int d = dp[i][j];
		dp[i][j + 1] += (d / 2 + (d & 1) * map[i][j]);
		dp[i + 1][j] += (d / 2 + (d & 1) * !map[i][j]);
	}

	int r = 1, c = 1;
	while (r <= n && c <= m) {
		if ((dp[r][c] & 1) ^ map[r][c]) c++;
		else r++;
	}
	
	cout << r << ' ' << c << '\n';
	return 0;
}