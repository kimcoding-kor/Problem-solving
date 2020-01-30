#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct FT {
	vector <int> tree;
	int size;
	FT(int n) {
		size = n;
		tree.resize(size + 1);
	}
	void update(int idx, int diff) {
		while (idx <= size) {
			tree[idx] += diff;
			idx += idx & -idx;
		}
	}
	int sum(int idx) {
		int ret = 0;
		while (idx) {
			ret += tree[idx];
			idx -= idx & -idx;
		}
		return ret;
	}
	int p_search(int cnt) {
		int low = 1, high = size, ret = 0;
		while (low <= high) {
			int mid = (low + high) / 2;
			int val = sum(mid);
			if (val < cnt) low = mid + 1;
			else {
				ret = mid;
				high = mid - 1;
			}
		}
		return ret;
	}
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k, now = 0;
	cin >> n >> k;
	FT ft(n);
	for (int i = 1; i <= n; i++) ft.update(i, 1);
	cout << '<';
	while(n) {
		now = (now + k) % n;
		if (!now) now = n;
		int val = ft.p_search(now);
		cout << val;
		if (n != 1) cout << ", ";
		ft.update(val, -1);
		now--, n--;
	}
	cout << ">\n";
	return 0;
}