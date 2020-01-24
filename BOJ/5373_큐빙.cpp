#include <cstdio>
#define FOR(i,a,b) for(int i=a;i<b;i++)

char cube[6][3][3];
int dir[3][4] = { {1,5,3,4}, {0,4,2,5},{0,1,2,3} };
int ri[3][4] = { {0,1,2,3},{0,0,2,0},{1,1,1,1} };

void setting() {
	char ch[6] = { 'w','r','y','o','g','b' };
	FOR(i, 0, 6) FOR(j, 0, 3) FOR(k, 0, 3)
		cube[i][j][k] = ch[i];
}

void rotate(int f) {
	int temp[3][3];
	FOR(i, 0, 3) FOR(j, 0, 3)
		temp[i][j] = cube[f][2 - j][i];
	FOR(i, 0, 3) FOR(j, 0, 3)
		cube[f][i][j] = temp[i][j];
}

void spin(int f, int s, int clock) {
	char temp[3];
	FOR(i, 0, 4) FOR(j, 0, ri[f][i])
		rotate(dir[f][i]);
	FOR(i, 0, 3)
		temp[i] = cube[dir[f][clock == 1 ? 3 : 0]][s][i];
	FOR(i, 0, 3) FOR(j, 0, 3) {
		int idx = clock == 1 ? (3 - i) : i;
		cube[dir[f][idx]][s][j] = cube[dir[f][idx - clock]][s][j];
	}
	FOR(i, 0, 3)
		cube[dir[f][clock == 1 ? 0 : 3]][s][i] = temp[i];
	FOR(i, 0, 4) FOR(j, 0, 4 - ri[f][i])
		rotate(dir[f][i]);
}

int main() {
	int t; scanf("%d", &t); while (t--) {
		setting();
		int n; scanf("%d", &n);
		while (n--) {
			char a, b;
			scanf(" %c %c", &a, &b);
			if (a == 'U') spin(0, 0, (b == '+' ? -1 : 1));
			if (a == 'D') spin(0, 2, (b == '+' ? 1 : -1));
			if (a == 'B') spin(1, 0, (b == '+' ? 1 : -1));
			if (a == 'F') spin(1, 2, (b == '+' ? -1 : 1));
			if (a == 'L') spin(2, 0, (b == '+' ? 1 : -1));
			if (a == 'R') spin(2, 2, (b == '+' ? -1 : 1));
			char temp[6] = { 'U', 'F','D','B','L','R' };
			FOR(i, 0, 6) if (temp[i] == a)
				FOR(j, 0, (b == '+' ? 1 : 3)) rotate(i);
		}
		FOR(i, 0, 3) {
			FOR(j, 0, 3) printf("%c", cube[0][i][j]);
			printf("\n");
		}
	}
	return 0;
}