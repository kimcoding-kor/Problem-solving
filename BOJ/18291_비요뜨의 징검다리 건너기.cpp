#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mod ((int)1e9 + 7)
using namespace std;

int main() {
	FIO;
	auto pw = [&](int a, int b) {
		int ret = 1;
		while (b >= 1) {
			if (b & 1) ret = (1LL * ret * a) % mod;
			b >>= 1, a = (1LL * a * a) % mod;
		}
		return ret;
	};
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		cout << pw(2,n-2) << '\n';
	}
	return 0;
}