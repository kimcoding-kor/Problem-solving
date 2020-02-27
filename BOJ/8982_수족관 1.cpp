#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define pii pair<int,int>
#define fs first
#define sd second
using namespace std;

int main() {
	FIO;
	int n; cin >> n;
	pii arr[2505], d[2505];
	bool h[2505] = {};
	int a, b, c;
	cin >> a >> b; n = (n - 1) >> 1;
	FOR(i, 0, n - 1) {
		cin >> a >> b >> c;
		arr[i] = { a,c };
		d[i] = { b, 0 };
		cin >> c;
	}
	cin >> a >> b;
	auto cmp = [](const pii& a, const pii& b) {
		return a.fs < b.fs;
	};
	int k; cin >> k;
	while (k--) {
		cin >> a >> b >> c >> b;
		int idx = lower_bound(arr, arr + n, pii(a, c), cmp) - arr;
		h[idx] = 1;
	}
	int water = 0;
	auto f = [&](int i) {
		if (h[i]) water = d[i].fs;
		else water = max(min(water, d[i].fs), d[i].sd);
		d[i].sd = water;
	};
	RFOR(i, n - 1, 0) f(i);
	water = 0;
	FOR(i, 0, n - 1) f(i);
	int ans = 0;
	FOR(i, 0, n - 1)
		ans += (arr[i].sd - arr[i].fs) * (d[i].fs - d[i].sd);
	cout << ans << '\n';
	return 0;
}