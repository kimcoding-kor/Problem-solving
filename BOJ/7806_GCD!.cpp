#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
using namespace std;

ll pw2(ll a, ll b) {
	ll ret = 1;
	while (b) {
		if (b & 1) ret *= a;
		a *= a, b >>= 1;
	}
	return ret;
}

int main() {
	FIO;
	ll n, k;
	while (!cin.eof() && cin >> n >> k) {
		if (!n) n++;
		ll ans = 1, temp = k;
		for (ll i = 2; i * i <= temp; i++) {
			if (k < i) break;
			ll a = 0, b = 0;
			while (!(k % i)) k /= i, a++;
			for (ll j = i; j <= n; j *= i) b += n / j;
			ans *= pw2(i, min(a, b));
		}
		cout << ans * (k <= n ? k : 1) << '\n';
	}
	return 0;
}