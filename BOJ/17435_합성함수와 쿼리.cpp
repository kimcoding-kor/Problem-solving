#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

#define MAX ((int)log2(500005))

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int m; cin >> m;
	vvi dp(m + 1, vi(MAX + 1));
	vi visit(m + 1);
	for (int i = 1, x; i <= m; i++) {
		cin >> x;
		dp[i][0] = x;
	}
	for (int i = 1; i <= MAX; i++)
		for (int j = 1; j <= m; j++)
			dp[j][i] = dp[dp[j][i - 1]][i - 1];
	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		for (int i = 0; i <= MAX; i++)
			if (a & (1 << i)) b = dp[b][i];
		cout << b << '\n';
	}
	return 0;
}