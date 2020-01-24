#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct p {
	int m1, m2;
}p;
typedef vector <p> vp;

typedef struct ST {
	vp tree;
	ST(int n) {
		int tree_size = 1 << ((int)ceil(log2(n)) + 1);
		tree.resize(tree_size);
	}
	void update(int now, int start, int end, int idx, int val) {
		if (idx < start || end < idx) return;
		if (start == end) {
			tree[now] = p{ val, -1 };
			return;
		}
		int mid = (start + end) / 2;
		update(now * 2, start, mid, idx, val);
		update(now * 2 + 1, mid + 1, end, idx, val);
		p a = tree[now * 2], b = tree[now * 2 + 1];
		tree[now] = p{ max(a.m1,b.m1),max(min(a.m1,b.m1),max(a.m2,b.m2)) };
	}
	p query(int now, int start, int end, int left, int right) {
		if (end < left || right < start) return p{ -1, -1 };
		if (left <= start && end <= right) return tree[now];
		int mid = (start + end) / 2;
		p a = query(now * 2, start, mid, left, right), b = query(now * 2 + 1, mid + 1, end, left, right);
		return p{ max(a.m1,b.m1),max(min(a.m1,b.m1),max(a.m2,b.m2)) };
	}
	~ST() {
		tree.clear();
	}
}ST;

int main() {
	int n, m;
	scanf("%d", &n);
	ST st(n);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		st.update(1, 1, n, i, x);
	}
	scanf("%d", &m);
	for (int i = 1, x, a, b; i <= m; i++) {
		scanf("%d %d %d", &x, &a, &b);
		if (x == 1) st.update(1, 1, n, a, b);
		else {
			p ans = st.query(1, 1, n, a, b);
			printf("%d\n", ans.m1 + ans.m2);
		}
	}
	return 0;
}