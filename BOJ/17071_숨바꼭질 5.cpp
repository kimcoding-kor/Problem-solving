#include <cstdio>
#include <queue>
#define MAX 500000
using namespace std;
typedef pair<int, int> pii;

int n, k, cnt;
bool dp[MAX + 1][2];
queue <pii> q;

int solve() {
	q.push({ n,0 });
	dp[n][0] = 1;
	while (q.size()) {
		if (dp[k][cnt & 1]) return cnt;
		int now = q.front().first, num = q.front().second; q.pop();
		if (num > cnt) k += (++cnt);
		if (k > MAX) break;
		int dir[3] = { -1,1,now };
		for (auto d : dir) {
			if (now + d < 0 || now + d > MAX) continue;
			if (dp[now + d][(num + 1) & 1]) continue;
			q.push({ now + d,num + 1 });
			dp[now + d][(num + 1) & 1] = 1;
		}
	}
	return -1;
}

int main() {
	scanf("%d %d", &n, &k);
	printf("%d\n", solve());
	return 0;
}