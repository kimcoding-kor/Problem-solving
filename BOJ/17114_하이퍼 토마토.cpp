#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ep emplace
using namespace std;

int main() {
	FIO;
	int a[11];
	FOR(i, 0, 10) {
		int x;
		cin >> x;
		a[i] = (i ? a[i - 1] : 1) * x;
	}
	int sz = a[10];
	int map[1000005], visit[1000005] = {}, cnt = 0;
	queue<int> q;
	FOR(i, 0, sz - 1) {
		cin >> map[i];
		if (map[i] == 1) q.ep(i);
		if (!map[i]) cnt++;
	}
	auto bfs = [&]() {
		if (!cnt) return 0;
		while (q.size()) {
			int now = q.front();
			q.pop();
			FOR(i, 0, 10) FOR(j, 0, 1) {
				int val = (i ? a[i - 1] : 1);
				if (!j && (now % a[i]) - val < 0) continue;
				if (j && (now % a[i]) + val >= a[i]) continue;
				int next = now + (j ? val : -val);
				if (visit[next] || map[next]) continue;
				visit[next] = visit[now] + 1;
				if (!(--cnt)) return visit[next];
				q.ep(next);
			}
		}
		return -1;
	};
	cout << bfs() << '\n';
	return 0;
}