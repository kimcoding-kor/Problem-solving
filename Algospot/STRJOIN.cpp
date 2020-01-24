#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main() {
	int test; scanf("%d", &test); while (test--) {
		priority_queue <int, vector<int>, greater <int>> pq;
		int n; scanf("%d", &n);
		for (int i = 1, x; i <= n; i++) {
			scanf("%d", &x);
			pq.push(x);
		}
		int ans = 0;
		while (pq.size() > 1) {
			int a = pq.top(); pq.pop();
			int b = pq.top(); pq.pop();
			ans += (a + b);
			pq.push(a + b);
		}
	    printf("%d\n", ans);
		pq.pop();
	}
	return 0;
}