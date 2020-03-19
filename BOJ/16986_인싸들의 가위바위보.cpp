#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define FOR(i, a, b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
	FIO;
	int n, k;
	cin >> n >> k;
	int t[10][10];
	FOR(i, 1, n) FOR(j, 1, n) cin >> t[i][j];
	int rps[3][21], cnt[3] = {}, p[3] = {};
	bool v[10];
	FOR(i, 1, 20) cin >> rps[1][i];
	FOR(i, 1, 20) cin >> rps[2][i];

	function<int(int, int, int)> ans = [&](int i, int f, int s) {
		if (p[0] == k) return 1;
		if (p[1] == k || p[2] == k) return 0;
		cnt[f]++, cnt[s]++;
		int ff = rps[f][cnt[f]], ss = rps[s][cnt[s]];
		if (f && s) {
			int win = (t[ff][ss] == 2 || (t[ff][ss] == 1 && f > s)) ? f : s;
			p[win]++;
			if (ans(i + 1, win, 0)) return 1;
			p[win]--;
		}
		else {
			FOR(j, 1, n) {
				if (v[j]) continue;
				v[j] = 1;
				int x = rps[f | s][cnt[f | s]];
				int win = (t[j][x] == 2) ? 0 : f | s;
				p[win]++;
				if (ans(i + 1, win, 3 - f - s)) return 1;
				p[win]--;
				v[j] = 0;
			}
		}
		cnt[f]--, cnt[s]--;
		return 0;
	};

	cout << ans(1, 0, 1) << '\n';
	return 0;
}