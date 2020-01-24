#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, arr[1005], ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		arr[i] -= x;
	}
	while (1) {
		bool flag = true;
		for (int i = 1, j; i <= n; i++) {
			if (arr[i] != 0) {
				flag = false;
				int temp = arr[i];
				for (j = i + 1; j <= n; j++) {
					if ((arr[j] <= 0 && arr[i] > 0) || (arr[j] >= 0 && arr[i] < 0)) break;
					temp = arr[i] < 0 ? max(arr[i], arr[j]) : min(arr[i], arr[j]);
				}
				for (int k = i; k < j; k++) arr[k] -= temp;
				ans += abs(temp);
				i = j - 1;
			}
		}
		if (flag) break;
	}
	printf("%d\n", ans);
	return 0;
}