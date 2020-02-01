#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct ST {
	vector <int> tree;
	int leaf;
	ST(int n) {
		leaf = (1 << (int)ceil(log2(n)));
		tree.resize(leaf * 2);
	}
	void update(int idx, int diff) {
		idx += leaf;
		tree[idx] += diff;
		while (idx /= 2) tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	}
	int query(int val) {
		int idx = 1;
		while (idx < leaf) {
			if (tree[idx * 2] >= val) idx *= 2;
			else {
				val -= tree[idx * 2];
				idx = idx * 2 + 1;
			}
		}
		return idx - leaf;
	}
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k;
	ST st(65540);
	int arr[250005];
	for (int i = 1; i < k; i++) {
		cin >> arr[i];
		st.update(arr[i], 1);
	}
	long long ans = 0;
	for (int i = k; i <= n; i++) {
		cin >> arr[i];
		st.update(arr[i], 1);
		ans += st.query((k + 1) / 2);
		st.update(arr[i - k + 1], -1);
	}
	cout << ans << '\n';
	return 0;
}