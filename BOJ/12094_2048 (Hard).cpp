#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
using namespace std;

int main() {
	int n; cin >> n;
	int map[25][25] = {};
	FOR(i, 1, n) FOR(j, 1, n) cin >> map[i][j];

	auto move = [&](int d) {
		if (d == 0) FOR(i, 1, n) {
			int k = 1;
			FOR(j, 1, n) {
				if (!map[i][j]) continue;
				map[i][k] = map[i][j++];
				while (j <= n && !map[i][j]) j++;
				if (j > n || map[i][k] != map[i][j]) k++, j--;
				else map[i][k++] *= 2;
			}
			FOR(j, k, n) map[i][j] = 0;
		}

		if (d == 1) FOR(i, 1, n) {
			int k = n;
			RFOR(j, n, 1) {
				if (!map[i][j]) continue;
				map[i][k] = map[i][j--];
				while (j > 0 && !map[i][j]) j--;
				if (!j || map[i][k] != map[i][j]) k--, j++;
				else map[i][k--] *= 2;
			}
			RFOR(j, k, 1) map[i][j] = 0;
		}

		if (d == 2) FOR(i, 1, n) {
			int k = n;
			RFOR(j, n, 1) {
				if (!map[j][i]) continue;
				map[k][i] = map[j--][i];
				while (j > 0 && !map[j][i]) j--;
				if (!j || map[k][i] != map[j][i]) k--, j++;
				else map[k--][i] *= 2;
			}
			RFOR(j, k, 1) map[j][i] = 0;
		}

		if (d == 3) FOR(i, 1, n) {
			int k = 1;
			FOR(j, 1, n) {
				if (!map[j][i]) continue;
				map[k][i] = map[j++][i];
				while (j <= n && !map[j][i]) j++;
				if (j > n || map[k][i] != map[j][i]) k++, j--;
				else map[k++][i] *= 2;
			}
			FOR(j, k, n) map[j][i] = 0;
		}

		int ret = 0;
		FOR(i, 1, n) FOR(j, 1, n) ret = max(ret, map[i][j]);
		return ret;
	};

	auto chk = [&](int temp[][25], int map[][25]) {
		FOR(i, 1, n) FOR(j, 1, n)
			if (temp[i][j] != map[i][j]) return 1;
		return 0;
	};

	function <int(int, int)> dfs = [&](int lv, int Max) {
		if (lv == 10)
			return Max;
		int temp[25][25] = {};
		FOR(i, 1, n) FOR(j, 1, n) temp[i][j] = map[i][j];
		FOR(i, 0, 3) {
			int val = move(i);
			if (val << (10 - lv - 1) > Max&& chk(temp, map))
				Max = max(Max, dfs(lv + 1, max(Max, val)));
			FOR(i, 1, n) FOR(j, 1, n) map[i][j] = temp[i][j];
		}
		return Max;
	};
	int Max = 0;
	FOR(i, 1, n) FOR(j, 1, n)
		Max = max(Max, map[i][j]);
	cout << dfs(0, Max) << '\n';
	return 0;
}