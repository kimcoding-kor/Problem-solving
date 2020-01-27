#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define mod ((int)1e9 + 7)

typedef long long ll;
int pow_2[300005], arr[300005], n, ans;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	pow_2[0] = 1;
	for (int i = 1; i <= 300000; i++)
		pow_2[i] = 1LL * pow_2[i - 1] * 2 % mod;
	for (int i = 1; i <= n; i++)
		ans = (ans + (pow_2[i - 1] - pow_2[n - i] + mod) % mod * 1LL * arr[i]) % mod;
	cout << ans << '\n';
	return 0;
}