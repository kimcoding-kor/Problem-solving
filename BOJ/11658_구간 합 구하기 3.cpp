#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

struct FT {
	vvi tree;
	int tree_size;
	FT(int n) : tree_size(n) {
		tree = vvi(n + 1, vi(n + 1));
	}
	void update(int i, int x, int diff) {
		while (i <= tree_size) {
			int j = x;
			while (j <= tree_size) {
				tree[i][j] += diff;
				j += j & -j;
			}
			i += i & -i;
		}
	}
	int sum(int i, int x) {
		int ans = 0;
		while (i) {
			int j = x;
			while (j) {
				ans += tree[i][j];
				j -= j & -j;
			}
			i -= i & -i;
		}
		return ans;
	}
	int query(int a, int b, int c, int d) {
		return sum(c, d) - sum(a - 1, d) - sum(c, b - 1) + sum(a - 1, b - 1);
	}
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m; cin >> n >> m;
	FT ft(n);
	for (int i = 1; i <= n; i++)
		for (int j = 1, x; j <= n; j++) {
			cin >> x;
			ft.update(i, j, x);
		}
	while (m--) {
		int x, a, b, c, d;
		cin >> x >> a >> b >> c;
		if (x) {
			cin >> d;
			cout << ft.query(a, b, c, d) << '\n';
		}
		else {
			int diff = c - ft.query(a, b, a, b);
			ft.update(a, b, diff);
		}
	}
	return 0;
}