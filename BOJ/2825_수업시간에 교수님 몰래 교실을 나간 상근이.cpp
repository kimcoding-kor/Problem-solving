#include <cstdio>
typedef long long ll;

int dp[1 << 10];
ll ans;

int main() {
	int n; scanf("%d", &n);
	while(n--) {
		ll x, mask = 0;
		scanf("%lld", &x);
		do {
			mask |= (1 << (x % 10));
		} while (x /= 10);
		dp[mask]++;
	}
	for (int i = 1; i < (1 << 10); i++) {
		if (!dp[i]) continue;
		for (int j = i; j < (1 << 10); j++) {
			if (!(i & j) || !dp[j]) continue;
			if (i == j) ans += ((ll)dp[i] * (dp[i] - 1)) / 2;
			else ans += (ll)dp[i] * dp[j];
		}
	}
	printf("%lld\n", ans);
	return 0;
}