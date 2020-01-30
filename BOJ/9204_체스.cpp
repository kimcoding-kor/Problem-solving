#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int test; cin >> test; while (test--) {
		char ch; int sr, sc, er, ec;
		cin >> ch >> sc;
		sr = ch - 'A' + 1;
		cin >> ch >> ec;
		er = ch - 'A' + 1;
		if (((sr + sc) & 1) != ((er + ec) & 1)) {
			cout << "Impossible\n";
			continue;
		}
		if (sr == er && sc == ec) {
			cout << "0 " << (char)(sr + 'A' - 1) << ' ' << sc << '\n';
			continue;
		}
		if (abs(sr - er) == abs(sc - ec)) {
			cout << "1 " << (char)(sr + 'A' - 1) << ' ' << sc << ' ';
			cout << (char)(er + 'A' - 1) << ' ' << ec << '\n';
			continue;
		}
		cout << "2 " << (char)(sr + 'A' - 1) << ' ' << sc << ' ';
		for (int i = 1; i <= 2; i++) {
			int a, b, c, d;
			if (i == 1) a = sr, b = sc, c = er, d = ec;
			else a = er, b = ec, c = sr, d = sc;
			int x = (a - b + c + d) / 2;
			if (x > 0 && x < 9) {
				int y = x - a + b;
				if (y > 0 && y < 9) {
					cout << (char)(x + 'A' - 1) << ' ' << y << ' ';
					break;
				}
			}
		}
		cout << (char)(er + 'A' - 1) << ' ' << ec << '\n';
	}
	return 0;
}