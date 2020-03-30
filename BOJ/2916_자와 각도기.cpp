#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
	FIO;
	int n, k;
	cin >> n >> k;
	bool chk[360] = {};
	chk[0] = 1;
	FOR(i, 1, n) {
		int x; cin >> x;
		for (int j = 0;;) {
			chk[j] = 1;
			FOR(m, 0, 359)
				if(chk[m]) chk[(j + m) % 360] = chk[abs(j - m)] = 1;
			j = (j + x) % 360;
			if (!j) break;
		}
	}
	while (k--) {
		int x; cin >> x;
		cout << (chk[x] ? "YES\n" : "NO\n");
	}
	return 0;
}