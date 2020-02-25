#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
	FIO;
	int n, m; cin >> n >> m;
	int arr[101], dp[101][11][2001];
	memset(dp, -1, sizeof(dp));
	FOR(i,1,n) cin >> arr[i];
	function <int(int, int, int)> DP = [&](int now, int cnt, int sum) {
		int& ret = dp[now][cnt][sum];
		if (ret != -1) return ret;
		if (now == n) return ret = sum * arr[now];
		ret = 1e9;
		if (cnt) ret = min(ret, DP(now + 1, cnt - 1, 0));
		ret = min(ret, DP(now + 1, cnt, sum + arr[now]));
		return ret += arr[now] * sum;
	};
	auto trace = [&]() {
		int cnt = m, sum = 0;
		FOR(i, 1, n - 1) {
			if (!cnt) break;
			int a = dp[i + 1][cnt][sum + arr[i]], b = dp[i + 1][cnt - 1][0];
			if (a < b) sum += arr[i];
			else sum = 0, cnt--, cout << i << ' ';
		}
	};
	cout << DP(1, m, 0) << '\n';
	trace();
	return 0;
}