#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector <int> vi;

vi seg, lazy;
int n, m, h = 1;

void propagate(int left, int right, int idx) {
	if (!lazy[idx]) return;
	seg[idx] = (right - left + 1) - seg[idx];
	if (left != right) {
		lazy[idx * 2] ^= 1;
		lazy[idx * 2 + 1] ^= 1;
	}
	lazy[idx] = 0;
}

void update(int nl, int nr, int idx, int left, int right) {
	propagate(nl, nr, idx);
	if (nl > right || nr < left) return;
	if (nl >= left && nr <= right) {
		lazy[idx] ^= 1;
		propagate(nl, nr, idx);
		return;
	}
	int mid = (nl + nr) >> 1;
	update(nl, mid, idx * 2, left, right);
	update(mid + 1, nr, idx * 2 + 1, left, right);
	seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
}

int sum(int nl, int nr, int idx, int left, int right) {
	propagate(nl, nr, idx);
	if (nl > right || nr < left) return 0;
	if (nl >= left && nr <= right) return seg[idx];
	int mid = (nl + nr) >> 1;
	return sum(nl, mid, idx * 2, left, right) + sum(mid + 1, nr, idx * 2 + 1, left, right);
}

int main() {
	scanf("%d %d", &n, &m);
	while (h < n) h <<= 1;
	seg.resize(2 * h + 1);
	lazy.resize(2 * h + 1);
	for (int i = 1, a, b, c; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a) printf("%d\n", sum(1, h, 1, b, c));
		else update(1, h, 1, b, c);
	}
	return 0;
}