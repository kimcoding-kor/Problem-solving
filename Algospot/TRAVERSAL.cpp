#include <cstdio>

int pre[105], in[105];

int f(int left, int right, int idx) {
	for (int i = left; i <= right; i++) {
		if (pre[idx] != in[i]) continue;
		idx = f(left, i - 1, idx + 1);
		idx = f(i + 1, right, idx + 1);
		printf("%d ", in[i]);
		return idx;
	}
	return idx - 1;
}

int main() {
	int test; scanf("%d", &test); while (test--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &pre[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &in[i]);
		f(1, n, 1);
		printf("\n");
	}
	return 0;
}