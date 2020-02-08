#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
using namespace std;

struct LST {
	int* tree, * lazy;
	int size;
	LST(int n) {
		size = (1 << (int)(ceil(log2(n)) + 1));
		tree = new int[size]();
		lazy = new int[size]();
	}
	void propagate(int now, int start, int end) {
		if (!lazy[now]) return;
		tree[now] = (end - start + 1) - tree[now];
		if (start < end) {
			lazy[now * 2] ^= lazy[now];
			lazy[now * 2 + 1] ^= lazy[now];
		}
		lazy[now] = 0;
	}
	void update(int now, int start, int end, int left, int right) {
		propagate(now, start, end);
		if (right < start || end < left) return;
		if (left <= start && end <= right) {
			lazy[now] ^= 1;
			propagate(now, start, end);
			return;
		}
		int mid = (start + end) / 2;
		update(now * 2, start, mid, left, right);
		update(now * 2 + 1, mid + 1, end, left, right);
		tree[now] = tree[now * 2] + tree[now * 2 + 1];
	}
	int query(int now, int start, int end, int left, int right) {
		propagate(now, start, end);
		if (right < start || end < left) return 0;
		if (left <= start && end <= right) return tree[now];
		int mid = (start + end) / 2;
		return query(now * 2, start, mid, left, right) + query(now * 2 + 1, mid + 1, end, left, right);
	}
	~LST() {
		delete[] tree;
		delete[] lazy;
	}
};

int main() {
	FIO;
	int n, m; cin >> n >> m;
	LST lst(n);
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (!a) lst.update(1, 1, n, b, c);
		else cout << lst.query(1, 1, n, b, c) << '\n';
	}
	return 0;
}