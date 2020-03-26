#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
	FIO;
	int test; cin >> test;
	FOR(t, 1, test) {
		int n, k; cin >> n >> k;
		vector <int> v(n);
		FOR(i, 0, n - 1) cin >> v[i];
		sort(all(v));
		int ans = 0;
		FOR(i, 0, n - 1) {
			if (k - v[i] < 0) break;
			k -= v[i];
			ans++;
		}
		cout << "Case #" << t << ": " << ans << '\n';
	}
	return 0;
}