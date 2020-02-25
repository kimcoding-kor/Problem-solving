#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
	FIO;
	int n, m; cin >> n >> m;
	bool map[105][105] = {}, visit[105][105][4] = {};
	FOR(i, 1, n) FOR(j, 1, m) cin >> map[i][j];
	int sr, sc, sd, er, ec, ed;
	cin >> sr >> sc >> sd >> er >> ec >> ed;
	sd--, ed--;
	int dir[][2] = { {0,1},{0,-1},{1,0},{-1,0} };
	queue <tuple <int, int, int, int>> q;
	q.push({ sr,sc,sd,0 });
	visit[sr][sc][sd] = 1;
	while (q.size()) {
		int r, c, d, cnt;
		tie(r, c, d, cnt) = q.front(); q.pop();
		if (r == er && c == ec && d == ed)
			return cout << cnt << '\n', 0;
		FOR(i, 1, 3) {
			int nr = r + dir[d][0] * i, nc = c + dir[d][1] * i;
			if (nr < 1 || nc < 1 || nr > n || nc > m) break;
			if (map[nr][nc]) break;
			if (visit[nr][nc][d]) continue;
			visit[nr][nc][d] = 1;
			q.push({ nr,nc,d,cnt + 1 });
		}
		FOR(i, 2, 3) {
			int nd = (d + i - (d & 1 ? 1 : 0)) % 4;
			if (visit[r][c][nd]) continue;
			visit[r][c][nd] = 1;
			q.push({ r,c,nd,cnt + 1 });
		}
	}
	return 0;
}