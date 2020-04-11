#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
using namespace std;

int main() {
	FIO;
	int n, ans = 0;
	cin >> n;
	bool chk[35][3] = {};

	function <void(int)> BT = [&](int r) {
		if (r > n) {
			ans++;
			return;
		}
		FOR(i, 1, n) {
			if (chk[i][0] || chk[r + i][1] || chk[r - i + 15][2]) continue;
			chk[i][0] = chk[r + i][1] = chk[r - i + 15][2] = 1;
			BT(r + 1);
			chk[i][0] = chk[r + i][1] = chk[r - i + 15][2] = 0;
		}
	};

	BT(1);
	cout << ans << '\n';
	return 0;
}