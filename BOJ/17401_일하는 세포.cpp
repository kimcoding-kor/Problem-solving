#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;

#define mod ((int)1e9 + 7)

vvi operator* (const vvi& a, const vvi& b) {
	int size = a.size();
	vvi ret(size, vi(size));
	for (int i = 1; i < size; i++)
		for (int j = 1; j < size; j++)
			for (int k = 1; k < size; k++)
				ret[i][j] = (ret[i][j] + 1LL * a[i][k] * b[k][j]) % mod;
	return ret;
}

ostream& operator<<(ostream& os, const vvi& a) {
	for (int i = 1; i < a.size(); i++) {
		for (int j = 1; j < a.size(); j++) os << a[i][j] << ' ';
		os << '\n';
	}
	return os;
}

vvi pow_2(vvi a, int b) {
	vvi ret(a.size(),vi(a.size()));
	for (int i = 1; i < a.size(); i++) ret[i][i] = 1;
	while (b) {
		if (b & 1) ret = ret * a;
		a = a * a;
		b /= 2;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t, n, d; cin >> t >> n >> d;
	vvvi map(t + 1, vvi(n + 1, vi(n + 1)));
	vvi ans(n + 1, vi(n + 1));
	for (int i = 1; i <= n; i++) ans[i][i] = 1;
	for (int i = 1; i <= n; i++) map[0][i][i] = 1;
	for (int i = 1; i <= t; i++) {
		int m, a, b, c; cin >> m;
		while (m--) {
			cin >> a >> b >> c;
			map[i][a][b] = c;
		}
		ans = ans * map[i];
	}
	ans = pow_2(ans, d / t);
	for (int i = 1; i <= d % t; i++) ans = ans * map[i];
	cout << ans;
	return 0;
}