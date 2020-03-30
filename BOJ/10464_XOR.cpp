#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
	FIO;
	int t; cin >> t; while (t--) {
		int a, b; cin >> a >> b;
		int ans = 0;
		FOR(i, 0, 29) {
			int x = 1 << i;
			int y = 1 << (i + 1);
			if (x > b) break;
			int z = ((b - x + 1) / y * x + min((b - x + 1) % y, x)) & 1;
			if (x <= a) z ^= (a - x) / y * x + min((a - x) % y, x);
			if (z & 1) ans += (1 << i);
		}
		cout << ans << '\n';
	}
	return 0;
}