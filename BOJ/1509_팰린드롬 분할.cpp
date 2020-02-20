#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define MAX 2505
using namespace std;

int main() {
	FIO;
	int dp[MAX];
	memset(dp, 0x3f, sizeof(dp));
	bool pal[MAX][MAX] = {};
	string s; cin >> s;
	int n = s.length() - 1;
	FOR(i, 0, n) FOR(j, 0, n - i)
		pal[j][i + j] = (s[j] == s[i + j]) * (i <= 1 ? 1 : pal[j + 1][i + j - 1]);
	dp[0] = 1;
	FOR(i, 0, n) {
		dp[i] = (i ? dp[i - 1] : 0) + 1;
		FOR(j, 0, i - 1) {
			if (!pal[j][i]) continue;
			dp[i] = min(dp[i], (j ? dp[j - 1] : 0) + 1);
		}
	}
	cout << dp[n] << '\n';
	return 0;
}