#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct ST {
	vector <int> tree;
	ST(int n) {
		int tree_size = 1 << ((int)ceil(log2(n)) + 1);
		tree.resize(tree_size, 1e9);
	}
	void update(int now, int start, int end, int idx, int val) {
		if (idx < start || end < idx) return;
		if (start == end) tree[now] = val;
		else {
			int mid = (start + end) / 2;
			update(now * 2, start, mid, idx, val);
			update(now * 2 + 1, mid + 1, end, idx, val);
			tree[now] = min(tree[now * 2], tree[now * 2 + 1]);
		}
	}
	int query(int now, int start, int end, int left, int right) {
		if (end < left || right < start) return 1e9;
		if (left <= start && end <= right) return tree[now];
		int mid = (start + end) / 2;
		return min(query(now * 2, start, mid, left, right), query(now * 2 + 1, mid + 1, end, left, right));
	}
	~ST() {
		tree.clear();
	}
}ST;

typedef struct p {
	int a, b, c;
}p;

int main() {
	int n; scanf("%d", &n);
	vector <p> v(n + 1);
	for (int i = 1,x; i <= n * 3; i++) {
		scanf("%d", &x);
		if (i <= n) v[x].a = i;
		else if (i <= 2 * n) v[x].b = i - n;
		else v[x].c = i - 2 * n;
	}
	sort(v.begin() + 1, v.end(), [&](p t, p u) {
		return t.a < u.a;
		});
	ST st(n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (st.query(1, 1, n, 1, v[i].b) > v[i].c) ans++;
		st.update(1, 1, n, v[i].b, v[i].c);
	}
	printf("%d\n", ans);
	return 0;
}