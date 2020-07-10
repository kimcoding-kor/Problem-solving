#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define mod ((int)1e9 + 9)
using namespace std;

int main() {
	FIO;
	int n, ans;
	cin >> n;
	ans = n > 1 ? 2 : 0;
	FOR(i, 3, n) ans = (1ll * ans * 3) % mod;
	cout << ans << '\n';
	return 0;
}