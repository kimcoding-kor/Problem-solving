#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector <ll> vll;
typedef vector <vll> vvl;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	vvl dp = vvl(35, vll(35));
	for (int i = 1; i < 35; i++) dp[i][0] = 1;
	for (int i = 1; i < 35; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]);
		}
	}
	int n;
	while (cin >> n && n) {
		cout << dp[n][n] << '\n';
	}
	return 0;
}