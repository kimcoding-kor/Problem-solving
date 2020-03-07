#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define vi vector <int>
#define vvi vector <vi>
#define eb emplace_back
using namespace std;

int main() {
	FIO;
	int n, m, p; cin >> n >> m >> p;
	int a[1000005], b[1000005];
	FOR(i, 0, n-1) {
		int x; cin >> x;
		a[i] = x % p;
	}
	FOR(i, 0, m-1) {
		int x; cin >> x;
		b[i] = x % p;
	}
	int ans = 0;
	FOR(i, 0, n-1) if (a[i]) {
		ans += i; break;
	}
	FOR(i, 0, m-1) if (b[i]) {
		ans += i; break;
	}
	cout << ans << '\n';
	return 0;
}