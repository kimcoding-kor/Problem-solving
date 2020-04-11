#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
using namespace std;

int main() {
	FIO;
	string s[4];
	FOR(i, 0, 3) cin >> s[i];
	int a[6][4] = { {0,1,2,3}, {0,4,2,5}, {1,4,3,5}, {0,3,2,1}, {0,5,2,4},{1,5,3,4} };
	int tp[6] = { 4, 3, 0, 5, 1, 2 }, b[4][4];
	bool chk[4][4] = {};
	map <tuple <int, int, int, int, int>, int> m;

	auto ctoi = [&](char c) {
		if (c == 'R') return 0;
		if (c == 'G') return 1;
		if (c == 'B') return 2;
		if (c == 'Y') return 3;
	};

	function <void(int, int)> f = [&](int d, int t) {
		if (d >= 4) {
			int x[4];
			FOR(k, 0, 3) {
				x[0] = x[1] = x[2] = x[3] = 0;
				FOR(i, 0, 3) FOR(j, 0, 3)
					x[i] = x[i] * 10 + b[i][(j + k) % 4];
				if (m.find({ x[0],x[1],x[2],x[3], t }) != m.end()) return;
			}
			m[{x[0], x[1], x[2], x[3], t}] = 1;
			return;
		}
		FOR(i, 0, 5) FOR(j, 0, 3) {
			int c[4];
			FOR(k, 0, 3)
				b[d][k] = c[k] = ctoi(s[d][a[i][(j + k) % 4]]);
			bool& r1 = chk[0][c[0]], & r2 = chk[1][c[1]];
			bool& r3 = chk[2][c[2]], & r4 = chk[3][c[3]];
			if (r1 || r2 || r3 || r4) continue;
			r1 = r2 = r3 = r4 = 1;
			f(d + 1, ctoi(s[d][tp[i]]));
			r1 = r2 = r3 = r4 = 0;
		}
	};

	f(0, 0);
	cout << m.size() << '\n';
	return 0;
}