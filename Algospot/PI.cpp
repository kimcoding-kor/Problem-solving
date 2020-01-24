#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char ch[10005];
int dp[10005][3], len;

int function(int s, int e) {
	int i;
	for (i = s + 1; i < e; i++) if (ch[s] != ch[i]) break;
	if (i == e) return 1;
	for (i = s + 1; i < e; i++) if (ch[i-1] - '0' + 1 != ch[i] - '0') break;
	if (i == e) return 2;
	for (i = s + 1; i < e; i++) if (ch[i - 1] - '0' - 1 != ch[i] - '0') break;
	if (i == e) return 2;
	for (i = s; i < e - 2; i++) if (ch[i] != ch[i + 2]) break;
	if (i == e - 2) return 4;
	int a = ch[s + 1] - '0' - (ch[s] - '0');
	for (i = s + 2; i < e; i++) if (ch[i] - '0' - (ch[i-1] - '0') != a) break;
	if (i == e) return 5;
	return 10;
}

int dfs(int idx) {
	if (dp[idx][0] != -1) return min(dp[idx][0], min(dp[idx][1], dp[idx][2]));
	if (idx == len) return 0;
	if (idx > len) return 1e9;
	for (int i = 3; i <= 5; i++) {
		int val = function(idx, idx + i);
		dp[idx][i - 3] = dfs(idx + i) + val;
	}
	return min(dp[idx][0], min(dp[idx][1], dp[idx][2]));
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		memset(dp, -1, sizeof(dp));
		memset(ch, 0, sizeof(ch));
		scanf("%s", &ch);
		len = strlen(ch);
		printf("%d\n", dfs(0));
	}
	return 0;
}