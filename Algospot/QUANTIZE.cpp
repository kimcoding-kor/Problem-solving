#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[105][15], arr[105], n, s;

int total(int st, int ed) {
	int sum = 0;
	for (int i = st; i <= ed; i++) sum += arr[i];
	int val = (double)sum / (double)(ed - st + 1) + 0.5;
	sum = 0;
	for (int i = st; i <= ed; i++) sum += (arr[i] - val) * (arr[i] - val);
	return sum;
}

int function(int level, int idx) {
	if (idx > n) return 0;
	int &ret = dp[idx][level];
	if (level == s) return ret = total(idx, n);
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = idx; i <= n; i++)
		ret = min(ret, total(idx, i) + function(level + 1, i + 1));
	return ret;
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		memset(dp, -1, sizeof(dp));
		scanf("%d %d", &n, &s);
		for (int i = 1; i <= n; i++)
			scanf("%d", &arr[i]);
		sort(arr + 1, arr + n + 1);
		printf("%d\n", function(1, 1));
	}
	return 0;
}