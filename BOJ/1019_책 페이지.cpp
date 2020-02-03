#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vi v(1), ans(10);
	int temp = n;
	while (temp) {
		v.push_back(temp % 10);
		temp /= 10;
	}
	int size = v.size();
	vvi dp(11, vi(10));
	for (int i = 0; i < 10; i++) dp[1][i] = 1;
	for (int i = 2, p = 10; i < size - 1; i++, p *= 10) {
		for (int j = 1; j < 10; j++) {
			for (int k = 0; k < 10; k++)
				dp[i][k] += dp[i - 1][k];
			if (j) dp[i][j] += p;
			for (int k = 2, c = 10; k < i; k++, c *= 10) dp[i][0] += c;
		}
		for (int j = 0; j < 10; j++) dp[i][j] += dp[i - 1][j];
	}
	for (int i = size - 1, p = pow(10, i - 1); i > 0; i--, p /= 10) {
		for (int j = 0; j < v[i]; j++) {
			if (i != size - 1 || j) ans[j] += p;
			for (int k = 0; k < 10; k++) {
				ans[k] += dp[i - 1][k];
			}
			if(i != size - 1 || j) for (int k = 2, c = 10; k < i; k++, c *= 10) ans[0] += c;
		}
		int temp = 0;
		for (int j = i - 1; j > 0; j--) temp = temp * 10 + v[j];
		ans[v[i]] += temp + 1;
	}
	if (n > 9)ans[0]--;
	for (int i = 0; i < 10; i++) cout << ans[i] << ' ';
	return 0;
}