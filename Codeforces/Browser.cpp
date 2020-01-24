#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
 
int main() {
	int n, pos, l, r, ans = 0;
	scanf("%d %d %d %d", &n, &pos, &l, &r);
	if (abs(pos - l) < abs(pos - r)) {
		if (l != 1) {
			ans += (abs(pos - l) + 1);
			pos = l;
		}
		if (r != n)
			ans += (abs(pos - r) + 1);
	}
	else{
		if (r != n) {
			ans += (abs(pos - r) + 1);
			pos = r;
		}
		if (l != 1)
			ans += (abs(pos - l) + 1);
	}
	printf("%d\n", ans);
	return 0;
}