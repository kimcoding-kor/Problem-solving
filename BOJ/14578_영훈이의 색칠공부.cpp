#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define mod ((int)1e9 + 7)
using namespace std;

int main() {
	FIO;
	int n; cin >> n;
	int a = 1, b = 1, c = 1, f = 1;
	FOR(i, 3, n - 1)
		a = (1LL * (i - 1) * b + 1LL * (i - 2) * c) % mod, c = b, b = a;
	FOR(i, 1, n) f = (1LL * f * i) % mod;
	cout << 1LL * f * ((1LL * (n - 1) * a) % mod) % mod << '\n';
	return 0;
}