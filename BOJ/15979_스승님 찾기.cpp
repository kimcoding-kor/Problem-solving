#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

int main() {
	FIO;
	int n, m; cin >> n >> m;

	function <int(int, int)> gcd = [&](int a, int b) {
		return b ? gcd(b, a % b) : a;
	};

	n = abs(n), m = abs(m);

	if (!n && !m) cout << 0 << '\n';
	else if (gcd(max(n, m), min(n, m)) == 1)
		cout << 1 << '\n';
	else cout << 2 << '\n';

	return 0;
}