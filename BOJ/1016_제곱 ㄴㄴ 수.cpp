#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll a, b;
	cin >> a >> b;
	bool chk[1000005] = {};
	int ans = 0;
	for (ll i = 2; i * i <= b; i++) {
		ll j = ((a - 1) / (i * i) + 1) * i * i;
		for (; j <= b; j += (i * i)) chk[j - a] = 1;
	}
	for (int i = 0; i <= b - a; i++) ans += !chk[i];
	cout << ans << '\n';
	return 0;
}