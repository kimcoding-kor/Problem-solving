#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int test; cin >> test; while (test--) {
		ll n; cin >> n;
		ll ans = 0;
		ll low = 0, high = 1e9;
		while (low <= high) {
			ll mid = (low + high) / 2;
			if (mid * (mid + 1) / 2 <= n) {
				ans = mid;
				low = mid + 1;
			}
			else high = mid - 1;
		}
		cout << ans << '\n';
	}
	return 0;
}