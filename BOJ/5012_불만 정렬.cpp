#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef struct ST {
	vector <int> tree;
	ST(int n) {
		int tree_size = 1 << ((int)ceil(log2(n)) + 1);
		tree.resize(tree_size);
	}
	void update(int now, int start, int end, int idx, int val) {
		if (start > idx || idx > end) return;
		if (start == end) tree[now] += val;
		else {
			int mid = (start + end) / 2;
			update(now * 2, start, mid, idx, val);
			update(now * 2 + 1, mid + 1, end, idx, val);
			tree[now] = tree[now * 2] + tree[now * 2 + 1];
		}
	}
	int query(int now, int start, int end, int left, int right) {
		if (end < left || right < start) return 0;
		if (left <= start && end <= right) return tree[now];
		int mid = (start + end) / 2;
		return query(now * 2, start, mid, left, right) + query(now * 2 + 1, mid + 1, end, left, right);
	}
	~ST() {
		tree.clear();
	}
}ST;

int main() {
	int n; scanf("%d", &n);
	vector <int> v(n + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
	ST L(n), R(n);
	for (int i = 1; i <= n; i++)
		R.update(1, 1, n, v[i], 1);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		R.update(1, 1, n, v[i], -1);
		ans += 1LL * L.query(1, 1, n, v[i] + 1, n) * R.query(1, 1, n, 1, v[i] - 1);
		L.update(1, 1, n, v[i], 1);
	}
	printf("%lld\n", ans);
	return 0;
}