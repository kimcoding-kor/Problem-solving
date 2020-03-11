#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
#define all(x) (x).begin(), (x).end()
#define vi vector <int>
#define vvi vector <vi>
#define ll long long
#define vll vector <ll>
#define vvl vector <vll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ep emplace
#define fs first
#define sd second
#define mod 998244353
using namespace std;

int main() {
	FIO;
	int n; cin >> n;
	pii map[1005][1005];
	int visit[1005][1005] = {};
	char ans[1005][1005] = {};
	FOR(i, 0, n - 1) FOR(j, 0, n - 1) {
		cin >> map[i][j].fs >> map[i][j].sd;
		if (i + 1 == map[i][j].fs && j + 1 == map[i][j].sd)
			ans[i][j] = 'X';
	}
	int d[4][2] = { {0,-1},{1,0}, {0,1},{-1,0} }, cnt = 0;
	char ch[4] = { 'R', 'U', 'L', 'D' };
	pii val;
	function <bool(int, int)> dfs = [&](int r, int c) {
		int k = 0;
		for (int i = 0; i < 4; i++) {
			int nr = r + d[i][0], nc = c + d[i][1];
			if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
			if (map[nr][nc] != val) continue;
			if (visit[nr][nc]) continue;
			if (!ans[r][c]) ans[r][c] = ch[(i + 2) % 4];
			visit[nr][nc] = 1;
			ans[nr][nc] = ch[i];
			cnt++; k++;
			dfs(nr, nc);
		}
		return k > 0;
	};
	FOR(i, 0, n - 1) FOR(j, 0, n - 1) {
		if (visit[i][j]) continue;
		if (map[i][j] != pii(-1, -1) && ans[i][j] != 'X') continue;
		val = map[i][j];
		cnt++; visit[i][j] = 1;
		if(!dfs(i, j) && map[i][j] == pii(-1,-1))
			return cout << "INVALID" << '\n', 0;
	}
	if (cnt < n * n) return cout << "INVALID" << '\n', 0;
	cout << "VALID" << '\n';
	FOR(i, 0, n - 1) {
		FOR(j, 0, n - 1) cout << ans[i][j];
		cout << '\n';
	}
	return 0;
}