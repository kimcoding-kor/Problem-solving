#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> pii;

#define x first
#define y second

int ccw(pii a, pii b, pii c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int intersect(pii a, pii b, pii c, pii d) {
	int abc = ccw(a, b, c), abd = ccw(a, b, d);
	int cda = ccw(c, d, a), cdb = ccw(c, d, b);
	if (abc == 0 && abd == 0 && cda == 0 && cdb == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		if (c == b || a == d) return 1;
		return (c < b && a < d) * 10;
	}
	return 1LL * abc * abd <= 0 && 1LL * cda * cdb <= 0;
}

int main() {
	int test; scanf("%d", &test); while (test--) {
		int a, b, c, d, sx, sy, ex, ey;
		scanf("%d %d %d %d %d %d %d %d", &a, &b, &c, &d, &sx, &sy, &ex, &ey);
		pii dot[] = { {a,b},{c,b},{c,d},{a,d} };
		int ans = 0;
		for (int i = 0; i < 4; i++) {
			ans += intersect(dot[i], dot[(i + 1) % 4], { sx,sy }, { ex,ey });
			if (intersect(dot[i], dot[i], { sx,sy }, { ex,ey })) ans--;
		}
		printf("%d\n", ans >= 4 ? 4 : ans);
	}
	return 0;
}