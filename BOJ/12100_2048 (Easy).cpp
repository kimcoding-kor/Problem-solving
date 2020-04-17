#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

void rotate(vvi& map, int n) {
	vvi temp = vvi(n + 1, vi(n + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			temp[i][j] = map[j][n - i + 1];
	map = temp;
}
int move(vvi& map, int n) {
	int ret = 2;
	for (int i = 1; i <= n; i++) {
		for (int j = 1, cnt = 1; j <= n; j++) {
			if (!map[i][j]) continue;
			int val = map[i][j];
			map[i][j++] = 0;
			ret = max(ret, val);
			while (j <= n && !map[i][j]) ++j;
			if (j == n + 1 || val != map[i][j]) {
				map[i][cnt++] = val; j--;
				continue;
			}
			ret = max(ret, map[i][cnt++] = val * 2);
			map[i][j] = 0;
		}
	}
	return ret;
}

int dfs(vvi map, int n, int level, int Max) {
	if (level == 5)
		return Max;
	for (int i = 1; i <= 4; i++) {
		rotate(map, n);
		vvi temp = map;
		int val = move(temp, n);
		Max = max(Max, dfs(temp, n, level + 1, val));
	}
	return Max;
}

int main() {
	int n; scanf("%d", &n);
	vvi map = vvi(n + 1, vi(n + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &map[i][j]);
	printf("%d\n", dfs(map, n, 0, 0));
	return 0;
}