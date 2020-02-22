#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

struct p { int r, c; };

int main() {
	FIO;
	int n, w; cin >> n >> w;
	int dp[1005][1005];
	p cd[1005];
	for (int i = 1; i <= w; i++) cin >> cd[i].r >> cd[i].c;
	memset(dp, -1, sizeof(dp));
	cd[w + 1] = p{ 1,1 }, cd[w + 2] = p{ n,n };
	auto dist = [&](p a, p b) {return abs(a.r - b.r) + abs(a.c - b.c); };
	function <int(int, int, int)> DP = [&](int now, int one, int two){
		if (now > w) return 0;
		int ret, &a = dp[two][now], &b = dp[one][now];
		if (a == -1) a = DP(now + 1, now, two);
		ret = a + dist(cd[one], cd[now]);
		if (b == -1) b = DP(now + 1, one, now);
		ret = min(ret, b + dist(cd[two], cd[now]));
		return ret;
	};
	auto trace = [&](int one, int two) {
		for (int i = 1; i <= w; i++) {
			int a = dp[one][i] + dist(cd[two], cd[i]);
			int b = dp[two][i] + dist(cd[one], cd[i]);
			if (a < b) cout << 2 << '\n', two = i;
			else cout << 1 << '\n', one = i;
		}
	};
	cout << DP(1, w + 1, w + 2) << '\n';
	trace(w + 1, w + 2);
	return 0;
}