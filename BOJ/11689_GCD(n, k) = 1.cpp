#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, ans; cin >> n;
	ll temp = ans = n;
	ll arr[15], cnt = 0;
	for (ll i = 2; i * i <= temp; i++) {
		if (temp % i) continue;
		while (!((temp /= i) % i));
		arr[cnt++] = i;
	}
	if(temp > 1) arr[cnt++] = temp;
	for (int i = 1; i < (1 << cnt); i++) {
		ll val = 1, z = 0;
		for (int j = 0; j < cnt; j++)
			if (i & (1 << j)) val *= arr[j], z++;
		if (z % 2) ans -= n / val;
		else ans += n / val;
	}
	cout << (n == 1 ? 1 : ans) << '\n';
	return 0;
}