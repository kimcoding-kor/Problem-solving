#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define ll long long
using namespace std;

int main() {
	FIO;
	int n; cin >> n;
	ll a[55], ans = 0;
	FOR(i, 1, n) cin >> a[i];

	auto f = [&](int b, int c, ll x) {
		int bb = min(b, c), cc = max(b, c);
		FOR(i, bb + 1, cc - 1) {
			ll y = (a[c] - a[b]) * i + x;
			if (y >= 0 && y <= a[i] * (c - b)) return 0;
			if (y < 0 && y >= a[i] * (c - b)) return 0;
		}
		return 1;
	};

	FOR(i, 1, n) {
		ll cnt = 0;
		FOR(j, 1, n) {
			if (i == j) continue;
			ll x = a[i] * (j - i) - i * (a[j] - a[i]);
			cnt += f(i, j, x);
		}
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
	return 0;
}