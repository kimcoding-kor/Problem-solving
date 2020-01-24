#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX ((int)1e5)

struct FT {
	vector <int> tree;
	FT() {
		tree.resize(MAX + 1);
	}
	void update(int idx, int diff) {
		while (idx < tree.size()) {
			tree[idx] += diff;
			idx += (idx & -idx);
		}
	}
	int query(int idx) {
		int ans = 0;
		while (idx) {
			ans += tree[idx];
			idx -= (idx & -idx);
		}
		return ans;
	}
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	FT ft;
	for (int i = 1, a, b; i <= n; i++) {
		cin >> a >> b;
		int a_query = ft.query(a);
		int b_query = ft.query(b);
		ft.update(a, -a_query), ft.update(a + 1, a_query);
		ft.update(b, -b_query), ft.update(b + 1, b_query);
		cout << a_query + b_query << '\n';
		ft.update(a + 1, 1), ft.update(b, -1);
	}
	return 0;
}