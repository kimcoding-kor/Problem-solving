#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> k >> m; m--;
	int dp[100005][31], arr[100005];
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= k; i++) cin >> dp[i][0];
	for (int i = 1; i < 31; i++)
		for (int j = 1; j <= k; j++)
			dp[j][i] = dp[dp[j][i - 1]][i - 1];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 31; j++)
			if (m & (1 << j)) arr[i] = dp[arr[i]][j];
		cout << arr[i] << ' ';
	}
	return 0;
}