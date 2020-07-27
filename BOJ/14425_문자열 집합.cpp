#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

int main() {
	FIO;
	map <string, int> h;
	int n, m;
	cin >> n >> m;
	FOR(i, 1, n) {
		string s;
		cin >> s;
		h[s] = 1;
	}

	int ans = 0;
	FOR(i, 1, m) {
		string s;
		cin >> s;
		ans += h[s];
	}

	cout << ans << '\n';
	return 0;
}