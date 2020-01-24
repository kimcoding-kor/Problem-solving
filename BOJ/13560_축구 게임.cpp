#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector <int> v(n + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	int sum = 0, flag = 1;
	for (int i = 1; i <= n; i++) {
		sum += v[i];
		if (sum < (i * (i - 1)) / 2) flag = 0;
	}
	printf("%d\n", flag && sum == (n*(n - 1)) / 2 ? 1 : -1);
	return 0;
}