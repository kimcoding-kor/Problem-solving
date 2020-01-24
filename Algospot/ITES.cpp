#include <cstdio>
#include <queue>
typedef long long ll;

std::queue <int> q;

int main() {
	int test; scanf("%d", &test); while (test--) {
		int k, n; scanf("%d %d", &k, &n);
		ll now = 1983, ans = 0, sum = 0;
		while (n--) {
			ll cur = now % 10000 + 1;
			q.push(cur); sum += cur;
			while (sum > k) {
				sum -= q.front();
				q.pop();
			}
			if (sum == k) ans++;		
			now = ((now * 214013 + 2531011) % (1LL << 32));
		}
		printf("%lld\n", ans);
		while (!q.empty()) q.pop();
	}
	return 0;
}