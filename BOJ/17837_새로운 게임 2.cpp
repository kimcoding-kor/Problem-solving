#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct p { int r, c, d; };
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <p> vp;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k;
	int dir[][2] = { {0,1},{0,-1},{-1,0},{1,0} };
	vvi map(n + 1, vi(n + 1));
	vvvi state(n + 1, vvi(n + 1));
	vp pos(k + 1);
	FOR(i, 1, n) FOR(j, 1, n) cin >> map[i][j];
	FOR(i, 1, k) {
		cin >> pos[i].r >> pos[i].c >> pos[i].d;
		state[pos[i].r][pos[i].c].push_back(i);
		pos[i].d--;
	}
	int ans = 0, flag = 0;
	while (++ans <= 1000) {
		FOR(t, 1, k) {
			p now = pos[t];
			int nr = now.r + dir[now.d][0], nc = now.c + dir[now.d][1];
			if (nr < 1 || nc < 1 || nr > n || nc > n || map[nr][nc] == 2) {
				pos[t].d = now.d = (now.d + (now.d & 1 ? 3 : 1)) % 4;
				nr = now.r + dir[now.d][0], nc = now.c + dir[now.d][1];
				if (nr < 1 || nc < 1 || nr > n || nc > n || map[nr][nc] == 2) continue;
			}
			vi& ref = state[now.r][now.c];
			int cnt = 0, size = (int)ref.size();	
			FOR(i, 0, size - 1) {
				if (ref[i] == t) break;
				cnt++;
			}
			FOR(i, cnt, size - 1) {
				int idx;
				if (map[nr][nc]) idx = ref.size() - 1 + cnt - i;
				else idx = i;
				pos[ref[idx]] = { nr,nc,pos[ref[idx]].d };
				state[nr][nc].push_back(ref[idx]);
			}
			FOR(i, cnt, size - 1)
				ref.pop_back();
			FOR(i, 1, n) FOR(j, 1, n)
				if (state[i][j].size() >= 4) flag = 1;
			if (flag) break;
		}
		if (flag) break;
	}
	cout << (ans > 1000 ? -1 : ans) << '\n';
	return 0;
}