#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct p { int r, c; }p;

char map[11][11];
p red, blue;
int n, m, dir[10];
int d[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

p move() {
	p tr = red, tb = blue;
	bool outr = 0, outb = 0;
	for (int i = 0; i < 10; i++) {
		int chkb = 0, chkr = 0;
        p prer = tr;
		while (map[tr.r][tr.c] != '#') {
			tr.r += d[dir[i]][0], tr.c += d[dir[i]][1];
			if (tr.r == tb.r && tr.c == tb.c) chkb = 1;
			if (map[tr.r][tr.c] == 'O') outr = 1;
		}
		tr.r -= d[dir[i]][0], tr.c -= d[dir[i]][1];
		if (chkb) tr.r -= d[dir[i]][0], tr.c -= d[dir[i]][1];
		while (map[tb.r][tb.c] != '#') {
			tb.r += d[dir[i]][0], tb.c += d[dir[i]][1];
			if (prer.r == tb.r && prer.c == tb.c) chkr = 1;
			if (map[tb.r][tb.c] == 'O') outb = 1;
		}
		tb.r -= d[dir[i]][0], tb.c -= d[dir[i]][1];
		if (chkr) tb.r -= d[dir[i]][0], tb.c -= d[dir[i]][1];
		if (outb) return p{ 0,0 };
		else if (outr ) return p{ 1,i + 1 };
	}
	return p{ 0,0 };
}

int rec(int level) {
	if (level == 10) {
		p chk = move();
		return chk.r ? chk.c : 11;
	}
	int Min = 11;
	for (int i = 0; i < 4; i++) {
		dir[level] = i;
		Min = min(Min, rec(level + 1));
	}
	return Min;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		scanf(" %c", &map[i][j]);
		if (map[i][j] == 'R') red = p{ i,j };
		if (map[i][j] == 'B') blue = p{ i,j };
	}
	int ans = rec(0);
	printf("%d\n", ans == 11 ? -1 : ans);
	return 0;
 }