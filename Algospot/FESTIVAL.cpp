#include <cstdio>
#define min(a,b) (a < b ? a : b)
int arr[1005];
int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		int N, L;
		scanf("%d %d", &N, &L);
		for (int i = 1; i <= N; i++)
			scanf("%d", &arr[i]);
		double ans = 1e9;
		for (int i = 1; i <= N - L + 1; i++) {
			int sum = 0;
			for (int j = i; j <= N; j++) {
				sum += arr[j];
				if (j - i + 1 >= L) 
					ans = min(ans, (double)sum / (double)(j - i + 1));
			}
		}
		printf("%.8f\n", ans);
	}
	return 0;
}