#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

struct p { int s, e; };

int main() {
	FIO;
	int n; cin >> n;
	p* arr = new p[n];
	priority_queue <int> pq;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		arr[i] = p{ min(a,b),max(a,b) };
	}
	int d; cin >> d;
	sort(arr, arr + n, [](p a, p b) {
		if (a.e == b.e) return a.s < b.s;
		return a.e < b.e;
		});
	int ans = 0;
	for (int i = 0; i < n; i++) {
		pq.emplace(-arr[i].s);
		while (pq.size() && -pq.top() + d < arr[i].e) pq.pop();
		ans = max(ans, (int)pq.size());
	}
	cout << ans << '\n';
	return 0;
}