#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

struct p {
	int x, y;
	p operator- (const p& a) {
		return p{ x - a.x, y - a.y };
	}
};

int main() {
	FIO;
	p a, b, c;
	auto ccw = [&](p a, p b) {
		return a.x * b.y - a.y * b.x;
	};
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	int x = ccw(b - a, c - a);
	cout << (x ? abs(x) / x : x) << '\n';
	return 0;
}