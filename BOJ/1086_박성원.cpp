#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

ll factorial(ll x) { 
	return x ? x * factorial(x - 1) : 1; 
}

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

int n, k;
ll dp[1 << 15][105];
string s[15];
int ten[55], rem[15];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	cin >> k;
	ten[0] = 1 % k;
	for (int i = 1; i <= 50; i++)
		ten[i] = (ten[i - 1] * 10) % k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < s[i].length(); j++)
			rem[i] = (ten[s[i].length() - j - 1] * (s[i][j] - '0') + rem[i]) % k;
	}
	dp[0][0] = 1;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) continue;
			for (int r = 0; r < k; r++)
				dp[i ^ (1 << j)][(r * ten[s[j].length()] + rem[j]) % k] += dp[i][r];
		}
	}

	ll total = factorial(1LL * n);
	ll gcd_num = gcd(total, dp[(1 << n) - 1][0]);
	cout << dp[(1 << n) - 1][0] / gcd_num << '/' << total / gcd_num << '\n';
	return 0;
}