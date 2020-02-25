#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pic pair <int,char>
#define fs first
#define sd second
using namespace std;

int main() {
	FIO;
	int n, ans = 0; cin >> n;
	pic rot[10][4][5][5];
	FOR(i, 0, n - 1) {
		FOR(j, 0, 3) FOR(k, 0, 3) cin >> rot[i][0][j][k].fs;
		FOR(j, 0, 3) FOR(k, 0, 3) cin >> rot[i][0][j][k].sd;
		FOR(r, 0, 2) FOR(j, 0, 3) FOR(k, 0, 3)
			rot[i][r + 1][k][3 - j] = { rot[i][r][j][k].fs,rot[i][r][j][k].sd };
	}
	tuple <int, int, int, int> arr[3];
	bool visit[10] = {};
	int chk[26];
	chk['W' - 'A'] = 0, chk['R' - 'A'] = 7, chk['B' - 'A'] = 5;
	chk['G' - 'A'] = 3, chk['Y' - 'A'] = 2;
	function <void(int)> per = [&](int lv) {
		if (lv == 3) {
			pic map[5][5];
			FOR(i, 0, 4) FOR(j, 0, 4) map[i][j] = { 0, 'W' };
			FOR(i, 0, 2) FOR(j, 0, 3) FOR(k, 0, 3) {
				int d, r, y, x;
				tie(d, r, y, x) = arr[i];
				y += j, x += k;
				pic& a = map[y][x], &b = rot[d][r][j][k];
				if (b.sd != 'W') a.sd = b.sd;
				a.fs += b.fs;
				if (a.fs < 0) a.fs = 0;
				if (a.fs > 9) a.fs = 9;
			}
			int sum = 0;
			FOR(i, 0, 4) FOR(j, 0, 4)
				sum += chk[map[i][j].sd - 'A'] * map[i][j].fs;
			ans = max(ans, sum);
			return;
		}
		FOR(i, 0, n - 1) {
			if (visit[i]) continue;
			visit[i] = 1;
			FOR(j, 0, 1) FOR(k, 0, 1) FOR(r, 0, 3) {
				arr[lv] = { i,r,j,k };
				per(lv + 1);
			}
			visit[i] = 0;
		}
	};
	per(0);
	cout << ans << '\n';
	return 0;
}