#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair <int,int>
#define fs first
#define sd second
using namespace std;

int main() {
	FIO;
	int n, m;
	cin >> n >> m;

	vector <pii> v;
	int cnt[1005] = {}, c = 0;

	FOR(i, 1, n) {
		int Min = 1e9;
		FOR(j, 1, m) {
			int x; cin >> x;
			v.push_back({ x, i });
			Min = min(Min, x);
		}
		c = max(c, Min);
	}

	sort(v.begin(), v.end());

	int l = 0, r = 0, ans = 1e9;
	while (c >= v[r].fs)
		cnt[v[r++].sd]++;
	r--;

	while(r < n * m) {
		ans = min(ans, v[r].fs - v[l].fs);

		int idx = v[l++].sd;
		if (--cnt[idx]) continue;
		
		while (r < n * m - 1) {
			cnt[v[++r].sd]++;
			if (idx == v[r].sd) break;
		}
		if (idx != v[r].sd) break;
	}

	cout << ans << '\n';
	return 0;
}