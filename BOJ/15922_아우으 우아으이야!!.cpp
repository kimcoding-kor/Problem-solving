#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i, a, b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
	FIO;
	int n, ans = 0;
	cin >> n;
	int l, r; l = r = -1e9 - 1;
	FOR(i, 1, n) {
		int a, b; cin >> a >> b;
		if (a > r) {
			ans += (r - l);
			l = a, r = b;
		}
		else r = max(r, b);
	}
	ans += (r - l);
	cout << ans << '\n';
	return 0;
}