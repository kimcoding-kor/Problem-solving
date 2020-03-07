#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int test; cin >> test; while (test--) {
		int n, m, k; cin >> n >> m >> k;
		vi v(n + 1);
		for (int i = 1; i <= n; i++) cin >> v[i];
		int ans = 0;
		k = min(k, m - 1);
		for (int i = 0; i <= k; i++) {
			int cnt = (m - 1) - k;
			int Min = 1e9;
			for (int j = 0; j <= cnt; j++) {
				int l = v[i + j + 1], r = v[n - (k - i) - (cnt - j)];
				Min = min(Min, max(l, r));
			}
			ans = max(ans, Min);
		}
		cout << ans << '\n';
	}
	return 0;
}