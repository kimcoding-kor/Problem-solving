#include <cstdio>
#include <vector>
using namespace std;
typedef vector <int> vi;

int main() {
	int test; scanf("%d", &test);
	while (test--) {
		int n, k; scanf("%d %d", &n, &k);
		vi v(n);
		int idx = 0;
		for (int i = 0; i < n - 2; i++) {
			v[idx%n] = 1;
			for (int j = 1; j <= k;)
				if (!v[(++idx) %n ]) j++;
		}
		for (int i = 0; i < n; i++)
			if (!v[i]) printf("%d ", i + 1);
		printf("\n");

	}
	return 0;
}