#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
using namespace std;

int main() {
	FIO;
	char map[1 << 10][1 << 11] = {};
	int n; cin >> n;

	function <void(int, int)> f = [&](int r, int d) {
		if (!d) return;
		int mid = (1 << n) - 2, h = (1 << d) - 2;
		FOR(i, 0, h) {
			int x = d & 1 ? i : h - i;
			FOR(j, mid - h, mid + i) {
				if (j == mid + i || j == mid - i || i == h)
					map[r + x][j] = '*';
				else map[r + x][j] = ' ';
			}
		}
		f(d & 1 ? r + (h >> 1) : r + 1, d - 1);
	};

	f(0, n);
	FOR(i, 0, (1 << n) - 2)
		cout << map[i] << '\n';
	return 0;
}