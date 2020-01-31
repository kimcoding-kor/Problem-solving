#include <cstdio>
#include <cstring>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

#define mod ((int)1e9 + 7)

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int s, a, b, c; cin >> s >> a >> b >> c;
	int dp[51][51][51][51];
	memset(dp, -1, sizeof(dp));
	int dir[7][3] = { {0,0,1},{0,1,0},{1,0,0},{0,1,1},{1,0,1},{1,1,0},{1,1,1} };
	function <int(int, int, int, int)> get_dp = [&](int level, int x, int y, int z) {
		if (!level)
			return (!x && !y && !z) * 1;
		int& ret = dp[level][x][y][z];
		if (ret != -1) return ret;
		ret = 0;
		for (auto d : dir) {
			int nx = x - d[0], ny = y - d[1], nz = z - d[2];
			if (nx < 0 || ny < 0 || nz < 0) continue;
			ret = (1LL * ret + get_dp(level - 1, nx, ny, nz)) % mod;
		}
		return ret;
	};
	cout << get_dp(s, a, b, c) << '\n';
	return 0;
}