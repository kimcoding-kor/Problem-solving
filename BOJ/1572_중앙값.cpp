#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct FT {
	vector <int> tree;
	FT() {
		tree.resize(65540);
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
	int p_search(int k) {
		int low = 0, high = tree.size() - 1, ans;
		while (low <= high) {
			int mid = (low + high) / 2;
			int val = query(mid);
			if (val >= (k + 1) / 2) {
				high = mid - 1;
				ans = mid - 1;
			}
			else low = mid + 1;
		}
		return ans;
	}
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, k; cin >> n >> k;
	FT ft;
	vector <int> v(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i < k; i++)
		ft.update(v[i] + 1, 1);
	long long ans = 0;
	for (int i = k; i <= n; i++) {
		ft.update(v[i] + 1, 1);
		ans += (1LL * ft.p_search(k));
		ft.update(v[i - k + 1] + 1, -1);
	}
	cout << ans << '\n';
	return 0;
}