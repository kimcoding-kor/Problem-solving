#include <cstdio>
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, t;
	cin >> n >> m >> t;
	vvi map = vvi(n + 1, vi(m + 1));
	vi acl;
	int dir[][2] = { {0,1},{0,-1},{1,0},{-1,0} };
	FOR(i, 1, n) FOR(j, 1, m) {
		cin >> map[i][j];
		if (map[i][j] == -1) acl.push_back(i);
	}
	while (t--) {
		vvi next = map;
		FOR(i, 1, n) FOR(j, 1, m) {
			if (map[i][j] <= 0) continue;
			int cnt = 0;
			for (auto d : dir) {
				int nr = i + d[0], nc = j + d[1];
				if (nr < 1 || nc < 1 || nr > n || nc > m) continue;
				if (map[nr][nc] == -1) continue;
				next[nr][nc] += map[i][j] / 5;
				cnt++;
			}
			next[i][j] -= map[i][j] / 5 * cnt;
		}
		map = next;
		RFOR(i, acl[0] - 1, 2) map[i][1] = map[i - 1][1];
		FOR(j, 1, m - 1) map[1][j] = map[1][j + 1];
		FOR(i, 1, acl[0] - 1) map[i][m] = map[i + 1][m];
		RFOR(j, m, 3) map[acl[0]][j] = map[acl[0]][j - 1];
		map[acl[0]][2] = 0;
		FOR(i, acl[1] + 1, n - 1) map[i][1] = map[i + 1][1];
		FOR(j, 1, m - 1) map[n][j] = map[n][j + 1];
		RFOR(i, n, acl[1] + 1) map[i][m] = map[i - 1][m];
		RFOR(j, m, 3) map[acl[1]][j] = map[acl[1]][j - 1];
		map[acl[1]][2] = 0;
	}
	int ans = 0;
	FOR(i, 1, n) FOR(j, 1, m) 
		if (map[i][j] != -1) ans += map[i][j];
	cout << ans << '\n';
	return 0;
}