#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

int main() {
	FIO;
	int n, m;
	cin >> n >> m;
	int map[55][55], chk[55][55];
	memset(chk, -1, sizeof(chk));

	FOR(i, 1, n) FOR(j, 1, m) {
		char c; cin >> c;
		map[i][j] = c - '0';
	}

	int dir[4][2] = { {-1,0}, {0,-1}, {0, 1}, {1, 0} };

	function <void(int, int, int)> dfs = [&](int r, int c, int val) {		
		map[r][c] = val + 1;
		for (auto d : dir) {
			int nr = r + d[0], nc = c + d[1];
			if (nr < 1 || nc < 1 || nr > n || nc > m) continue;
			if (map[nr][nc] != val) continue;
			dfs(nr, nc, val);
		}
	};

	int ans = 0;
	FOR(t, 1, 9) {
		FOR(i, 1, n) FOR(j, 1, m) {
			if (t != map[i][j]) continue;
			if (!(i == 1 || j == 1 || i == n || j == m)) continue;
			dfs(i, j, t);
		}

		FOR(i, 1, n) FOR(j, 1, m) {
			if (t != map[i][j]) continue;
			if (i == 1 || j == 1 || i == n || j == m) continue;
			map[i][j]++, ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}