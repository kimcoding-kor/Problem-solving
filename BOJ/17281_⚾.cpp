#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
	FIO;
	int n; cin >> n;
	int hit[50][10], ans = 0;
	FOR(i, 1, n) FOR(j, 1, 9) cin >> hit[i][j];
	int order[10], visit[10] = {}; order[4] = 1;
	auto play_ball = [&]() {
		int idx = 1, score = 0;
		FOR(i, 1, n) {
			int out = 0, run[4] = {};
			while (out < 3) {
				int now = hit[i][order[idx]];
				if (!now) out++;
				RFOR(j, 3, 1) {
					if (!run[j]) continue;
					if (j + now > 3) score++, run[j] = 0;
					else run[j] = 0, run[j + now] = 1;
				}
				if (now < 4) run[now] = 1;
				else score++;
				idx = idx == 9 ? 1 : idx + 1;
			}
		}
		return score;
	};
	function <void(int)> per = [&](int now) {
		if (now == 10) {
			ans = max(ans, play_ball());
			return;
		}
		if (now == 4) {
			per(now + 1);
			return;
		}
		FOR(i, 2, 9) {
			if (visit[i]) continue;
			visit[i] = 1;
			order[now] = i;
			per(now + 1);
			visit[i] = 0;
		}
	};
	per(1);
	cout << ans << '\n';
	return 0;
}