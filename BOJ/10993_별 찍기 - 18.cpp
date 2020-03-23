#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
using namespace std;

int main() {
	FIO;
	char map[1 << 10][1 << 11];
	memset(map, ' ', sizeof(map));
	int n; cin >> n;

	function <void(int, int, int)> f = [&](int r, int c, int d) {
		if (!d) return;
		int j = d & 1 ? 0 : (1 << d) - 2;
		FOR(i, r, r + (1 << d) - 2) {
			map[i][c + j] = map[i][c - j] = '*';
			j += (d & 1 ? 1 : -1);
		}
		int k = (d & 1 ? r + (1 << d) - 2 : r);
		FOR(i, 0, (1 << d) - 2)
			map[k][c - i] = map[k][c + i] = '*';
		int nr = r + (d & 1 ? (1 << d - 1) - 1 : 1);
		f(nr, c, d - 1);
	};

	f(1, (1 << n) - 1, n);
	FOR(i, 1, (1 << n) - 1) {
		int c = n & 1 ? (1 << n) - 1 + i : (1 << n + 1) - 2 - i;
		FOR(j, 1, c) 
			cout << map[i][j];
		cout << '\n';
	}
	return 0;
}