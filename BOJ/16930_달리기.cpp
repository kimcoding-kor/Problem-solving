#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
using namespace std;

struct p {
	int r, c;
};

int main() {
	FIO;
	int n, m, k;
	cin >> n >> m >> k;
	char map[1005][1005];
	FOR(i, 1, n) FOR(j, 1, m)
		cin >> map[i][j];
	int visit[1005][1005];
	int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
	int sr, sc, er, ec;
	cin >> sr >> sc >> er >> ec;
	fill(&visit[0][0], &visit[1004][1004], 1e9);
	auto bfs = [&]() {
		queue <p> q;
		q.push(p{ sr,sc });
		visit[sr][sc] = 1;
		while (q.size()) {
			p now = q.front(); q.pop();
			FOR(i, 0, 3) FOR(j, 1, k) {
				int nr = now.r + dir[i][0] * j, nc = now.c + dir[i][1] * j;
				if (nr < 1 || nc < 1 || nr > n || nc > m) break;
				if (map[nr][nc] == '#') break;
				if (nr == er && nc == ec) return visit[now.r][now.c];
				if (visit[nr][nc] < visit[now.r][now.c] + 1) break;
				if (visit[nr][nc] != 1e9) continue;
				visit[nr][nc] = visit[now.r][now.c] + 1;
				q.push(p{ nr,nc });
			}
		}
		return -1;
	};
	cout << bfs() << '\n';
	return 0;
}