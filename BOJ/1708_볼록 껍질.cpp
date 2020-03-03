#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ep emplace
#define ll long long
using namespace std;

struct p {
	int x, y, a, b;
	p(int xx = 0, int yy = 0) : x(xx), y(yy), a(1), b(0) {}
	ll ccw(p t, p u) {
		return 1ll * (t.x - x) * (u.y - y) - 1ll * (u.x - x) * (t.y - y);
	}
	bool operator< (const p& t) const {
		ll c = p(0, 0).ccw(p(a, b), p(t.a, t.b));
		if (c) return c > 0;
		if (x == t.x) return y < t.y;
		return x < t.x;
	}
};

int main() {
	FIO;
	int n; cin >> n;
	p d[100005];
	FOR(i, 0, n - 1) cin >> d[i].x >> d[i].y;
	sort(d, d + n);
	FOR(i, 1, n - 1) {
		d[i].a = d[i].x - d[0].x;
		d[i].b = d[i].y - d[0].y;
	}
	sort(d + 1, d + n);
	stack <p> s;
	s.ep(d[0]); s.ep(d[1]);
	FOR(i, 2, n - 1) {
		while ((int)s.size() > 1) {
			p b = s.top(); s.pop();
			p a = s.top(); s.pop();
			ll c = a.ccw(b, d[i]);
			s.ep(a);
			if (c > 0) {
				s.ep(b);
				break;
			}
		}
		s.ep(d[i]);
	}
	cout << (int)s.size() << '\n';
	return 0;
}