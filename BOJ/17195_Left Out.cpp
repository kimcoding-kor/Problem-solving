#include <cstdio>
#include <iostream>
using namespace std;

bool map[1005][1005];
struct p { int r, c; };

int check(int r1, int c1, int r2, int c2, int val) {
	int cnt = 0;
	for (int i = r1; i <= r2; i++)
		for (int j = c1; j <= c2; j++)
			if (val == map[i][j]) cnt++;
	return cnt;
}

p solve(int n) {
	if (check(2, 2, n, n, 0) == 0) return p{ 1,1 };
	if (check(2, 2, n, n, 1) == n - 1) {
		for (int i = 2; i <= n; i++)
			if (check(i, 2, i, n, 1) == n - 1) return p{ i, 1 };
		for (int i = 2; i <= n; i++)
			if (check(2, i, n, i, 1) == n - 1) return p{ 1, i };
	}
	if (check(2, 2, n, n, 1) != 1) return p{ -1,-1 };
	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= n; j++)
			if (map[i][j]) return p{ i,j };
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			char x; cin >> x;
			map[i][j] = (x == 'R');
	}
	for (int i = 2; i <= n; i++) {
		map[i][1] ^= map[1][1];
		for (int j = 2; j <= n; j++)
			map[i][j] ^= map[i][1] ^ map[1][j];
	}
	p ans = solve(n);
	if (ans.r == -1) cout << -1 << '\n';
	else cout << ans.r << " " << ans.c << '\n';
	return 0;
}