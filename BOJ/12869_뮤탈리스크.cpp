#include <cstdio>
#include <algorithm>
using namespace std;

int dp[65][65][65], n;
int dir[6][3] = { {1,3,9},{1,9,3},{3,1,9},{3,9,1},{9,1,3},{9,3,1} };

int solve(int a, int b, int c){
	if (a < 0) a = 0;
	if (b < 0) b = 0;
	if (c < 0) c = 0;
	int& ret = dp[a][b][c];
	if (!a && !b && !c) return ret = 0;
	if (ret) return ret;
	ret = 1e9;
	for (auto d : dir)
		ret = min(ret, solve(a - d[0], b - d[1], c - d[2]) + 1);
	return ret;
}

int main() {
	scanf("%d", &n);
	int scv[3] = {};
	for (int i = 0; i < n; i++)
		scanf("%d", &scv[i]);
	printf("%d\n", solve(scv[0], scv[1], scv[2]));
	return 0;
}