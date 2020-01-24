#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int main() {
	int test; scanf("%d", &test); while (test--) {
		priority_queue <int, vector <int>, greater <int>> rus, kor;
		int n; scanf("%d", &n);
		for (int i = 1, x; i <= n; i++) {
			scanf("%d", &x);
			rus.push(x);
		}
		for (int i = 1, x; i <= n; i++) {
			scanf("%d", &x);
			kor.push(x);
		}
		int ans = 0;
		while (!kor.empty()) {
			int nr = rus.top(); rus.pop();
			while (!kor.empty() && nr > kor.top())
				kor.pop();
			if (kor.empty()) break;
			kor.pop(); ans++;
		}
		printf("%d\n", ans);
		while (!kor.empty()) kor.pop();
		while (!rus.empty()) rus.pop();
	}
	return 0;
}