#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define EPSILON 1e-9

double dp[1005][7][7][7];
int n;

int score(int a, int b, int c) {
	if (a == b && b == c) return 10000 + 1000 * a;
	if (a == b) return 1000 + 100 * a;
	if (b == c) return 1000 + 100 * b;
	if (a == c) return 1000 + 100 * c;
	return max(a, max(b, c)) * 100;
}

double dfs(int idx, int a, int b, int c) {
	double& ret = dp[idx][a][b][c];
	if (fabs(ret - 0.0) > EPSILON) return ret;
	ret = score(a, b, c);
	if (idx == n) return ret;
	double sum = 0;
	FOR(i, 1, 6)
		sum += 1.0 / 6.0 * dfs(idx + 1, b, c, i);
	return ret = max(ret, sum);
}

int main() {
	scanf("%d", &n);
	FOR(i, 1, 6) FOR(j, 1, 6) FOR(k, 1, 6)
		dfs(3, i, j, k);
	double ans = 0;
	FOR(i, 1, 6) FOR(j, 1, 6) FOR(k, 1, 6)
		ans += 1.0 / 216.0 * dp[3][i][j][k];
	printf("%.9f\n", ans);
	return 0;
}