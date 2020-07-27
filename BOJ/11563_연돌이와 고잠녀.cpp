#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

struct Dot {
	double x, y;

	Dot operator - (const Dot& a) {
		return Dot{ x - a.x , y - a.y };
	}

	double dist(Dot dt) {
		return sqrt((x - dt.x) * (x - dt.x) + (y - dt.y) * (y - dt.y));
	}

	double inner(Dot v) {
		return x * v.x + y * v.y;
	}

	double cross(Dot v) {
		return x * v.y - y * v.x;
	}
};

struct Line {
	Dot a, b;

	double perpendicular(Dot dt) {
		double x = (b - a).inner(dt - a);
		double y = (a - b).inner(dt - b);
		if (x * y < 0) return 1e9;

		double area = abs((b - a).cross(dt - a));
		return area / a.dist(b);
	}

	double dist(Line ln) {
		double ret = 1e9;
		Dot c = ln.a, d = ln.b;
		ret = min({ ret, a.dist(c), a.dist(d) });
		ret = min({ ret, b.dist(c), b.dist(d) });

		ret = min(ret, perpendicular(c));
		ret = min(ret, perpendicular(d));
		ret = min(ret, ln.perpendicular(a));
		ret = min(ret, ln.perpendicular(b));
		return ret;
	}
};

int main() {
	FIO;
	int n, m;
	cin >> n >> m;

	Line yo[2005], ko[2005];
	
	FOR(i, 1, n + m) {
		double a, b, c, d;
		cin >> a >> b >> c >> d;
		if(i <= n)
			yo[i] = Line{ Dot{ a, b }, Dot{ c, d } };
		else
			ko[i - n] = Line{ Dot{ a, b }, Dot{ c, d } };
	}

	double ans = 1e9;
	FOR(i, 1, n) FOR(j, 1, m)
		ans = min(ans, yo[i].dist(ko[j]));

	cout << fixed;
	cout.precision(7);
	cout << ans << '\n';
	return 0;
}