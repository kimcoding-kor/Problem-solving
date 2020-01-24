#include <cstdio>
#include <vector>
using namespace std;

bool check[105][105];
int dir[4][2] = { {1,0},{0,-1},{-1,0},{0,1} }, n, ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y, d, g;
		scanf("%d %d %d %d", &x, &y, &d, &g);
		check[y][x] = 1;
		y += dir[d][1], x += dir[d][0];
		check[y][x] = 1;
		vector <int> v;
		v.push_back(d);
		while (g--) {
			int end = v.size();
			for (int i = end - 1; i >= 0; i--) {
				y += dir[(v[i] + 1) % 4][1], x += dir[(v[i] + 1) % 4][0];
				check[y][x] = 1;
				v.push_back((v[i] + 1) % 4);
			}
		}
	}
	for (int i = 0; i < 100; i++) for (int j = 0; j < 100; j++)
		ans += (check[i][j] && check[i + 1][j] && check[i][j + 1] && check[i + 1][j + 1]);
	printf("%d\n", ans);
	return 0;
}