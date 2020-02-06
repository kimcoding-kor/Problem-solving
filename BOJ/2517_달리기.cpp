#include <bits/stdc++.h>
using namespace std;

struct p {
	int idx, val;
	bool operator<(const p& t) const {
		return val < t.val;
	}
};

struct ST {
	int* tree, leaf;
	ST(int n) {
		leaf = (1 << (int)ceil(log2(n)));
		tree = new int[leaf * 2]();
	}
	void update(int idx, int val) {
		idx += leaf;
		tree[idx] = val;
		while (idx >>= 1) tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	}
	int query(int l, int r) {
		int ret = 0;
		l += leaf, r += leaf;
		for (; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) ret += tree[l++];
			if (!(r & 1)) ret += tree[r--];
		}
		if (l == r) ret += tree[l];
		return ret;
	}
	~ST() {
		delete[] tree;
	}
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	ST st(n);
	p* arr = new p[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].val;
		arr[i].idx = i;
	}
	sort(arr, arr + n);
	int* ans = new int[n];
	for (int i = 0; i < n; i++) {
		int now = arr[i].idx;
		ans[now] = now + 1 - st.query(0, now);
		st.update(now, 1);
	}
	for (int i = 0; i < n; i++) cout << ans[i] << '\n';
	return 0;
}