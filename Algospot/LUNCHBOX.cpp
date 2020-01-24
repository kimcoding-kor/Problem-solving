#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct p {
	int time, eat;
}p;

bool cmp(p t, p u) {
	return t.eat > u.eat;
}

typedef vector <p> vp;

int main() {
	int test; scanf("%d", &test); while (test--) {
		int n; scanf("%d", &n);
		vp v(n + 1);
		for (int i = 1; i <= n; i++) scanf("%d", &v[i].time);
		for (int i = 1; i <= n; i++) scanf("%d", &v[i].eat);
		sort(v.begin() + 1, v.end(), cmp);
		int sum = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			sum += v[i].time;
			ans = max(ans, sum + v[i].eat);
		}
		printf("%d\n", ans);
	}
	return 0;
}