#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
	FIO;
	int n; cin >> n;
	int a[105] = {}, b[105] = {};
	string s1, s2; cin >> s1 >> s2;
	FOR(i, 1, n) a[i] = s1[i - 1] - '0';
	FOR(i, 1, n) b[i] = s2[i - 1] - '0';

	int dp[105][15][15][15];
	memset(dp, -1, sizeof(dp));

	function <int(int, int, int, int)> DP = [&](int now, int x, int y, int z) {
		if (now > n) return 0;
		int& ret = dp[now][x][y][z];
		if (ret != -1) return ret;
		ret = 1e9;
		int ck = (b[now] - x + 10) % 10;
		int d[2] = { ck, 10 - ck };
		FOR(i, 0, 1) FOR(j, 0, d[i]) FOR(k, 0, j) {
			int yy = (y + (i ? -j : j) + 10) % 10;
			int zz = (z + (i ? -k : k) + 10) % 10;
			int val = DP(now + 1, yy, zz, a[now + 3]);
			val += (d[i] - j + 2) / 3 + (j - k + 2) / 3 + (k + 2) / 3;
			ret = min(ret, val);
		}
		return ret;
	};

	cout << DP(1, a[1], a[2], a[3]) << '\n';
	return 0;
}