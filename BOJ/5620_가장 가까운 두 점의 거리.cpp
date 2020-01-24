#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define x first
#define y second
#define all(x) (x).begin() + 1, (x).end()

typedef pair <int, int> pii;
typedef vector <pii> vpi;
typedef map <pii, int> mpi;
typedef mpi::iterator mit;

int n;
vpi v;
mpi m;

int dist(pii a, pii b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
	scanf("%d", &n);
	v = vpi(n + 1);
	for (int i = 1, a, b; i <= n; i++)
		scanf("%d %d", &v[i].x, &v[i].y);
	sort(all(v));
	int L = 1, R = 2;
	int ans = dist(v[L], v[R]);
	m[{v[L].y, v[L].x}] = m[{v[R].y, v[R].x}] = 1;
	for (R = 3; R <= n; R++) {
		while (L < R) {
			if (ans > (v[R].x - v[L].x) * (v[R].x - v[L].x)) break;
			m.erase(m.find({ v[L].y,v[L].x }));
			L++;
		}
		int len = (int)sqrt(ans);
		mit low = m.lower_bound({ v[R].y - len, -10005 });
		mit high = m.upper_bound({ v[R].y + len, 10005 });
		for (; low != high; low++)
			ans = min(ans, dist(v[R], { low->first.second,low->first.first }));
		m[{v[R].y, v[R].x}] = 1;
	}
	printf("%d\n", ans);
	return 0;
}