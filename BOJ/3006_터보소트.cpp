#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX ((int)1e5)

struct FT {
	vector <int> tree;
	FT() {
		tree.resize(MAX * 2 + 1);
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
	FT ft;
	int n; cin >> n;
	vector <int> idx(n + 1);
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		idx[x] = i + 50000;
		ft.update(idx[x], 1);
	}
	for (int i = 1; i <= n; i++) {
		int now = i & 1 ? (i + 1) / 2 : n - (i - 1) / 2;
		int next = i & 1 ? now : 2 * MAX - (i - 1) / 2;
		if (i & 1)
			cout << ft.query(idx[now] - 1) - ft.query(next) << '\n';
		else 
			cout << (ft.query(next) - ft.query(idx[now])) << '\n';
		ft.update(idx[now], -1);
		ft.update(next, 1);
		idx[now] = next;
	}
	return 0;
}