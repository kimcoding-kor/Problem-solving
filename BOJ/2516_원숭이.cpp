#include <cstdio>
#include <vector>
#include <bitset>
using namespace std;

vector <vector <int>> v;
bitset <100005> bit;

int main() {
	bit.set();
	int n; scanf("%d", &n);
	v.resize(n + 1);
	for (int i = 1,x; i <= n; i++) {
		scanf("%d", &x);
		for (int j = 1, y; j <= x; j++) {
			scanf("%d", &y);
			v[i].push_back(y);
		}
	}
	int b_size = n, flag = 1;
	for (;flag;) {
		flag = 0;
		for (int i = 1; i <= n; i++) {
			int cnt = 0;
			for (auto j : v[i])
				if (bit.test(j) == bit.test(i)) cnt++;
			if (cnt > 1) {
				if (bit.test(i)) bit.set(i, 0), b_size--;
				else bit.set(i, 1), b_size++;
				flag++;
			}
		}
	}
	printf("%d ", b_size);
	for (int i = 1; i <= 2 * n; i++) {
		if (i <= n && bit.test(i)) printf("%d ", i);
		if (i == n) printf("\n%d ", n - b_size);
		if (i > n && !bit.test(i-n)) printf("%d ", i - n);
	}
	return 0;
}