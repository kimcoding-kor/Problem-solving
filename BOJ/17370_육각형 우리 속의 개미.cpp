#include <cstdio>

int dir[6][2] = { {0,-1},{-1,-1},{-1,1},{0,1},{1,1},{1,-1} }, n;
bool map[55][55];

int dfs(int r, int c, int level,int x) {
	if (map[r][c] || level == n)
		return (map[r][c] && level == n);
	int ans = 0;
	map[r][c] = 1;
	for (int i = 0; i < 6;i++) {
		if ((x & 1) != (i & 1) || x == i) continue;
		int nr = r + dir[i][0], nc = c + dir[i][1];
		ans += dfs(nr, nc, level + 1, (i + 3) % 6);
	}
	map[r][c] = 0;
	return ans;
}

int main() {
	map[25][25] = 1;
	scanf("%d", &n);
	printf("%d\n", dfs(25, 24, 0, 3));
	return 0;
}