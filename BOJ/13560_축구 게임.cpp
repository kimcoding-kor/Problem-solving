#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i, a, b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
	FIO;
	int n, sum = 0;
	int v[10005];
	cin >> n;
	FOR(i, 1, n) cin >> v[i];
	sort(v + 1, v + n + 1);
	FOR(i, 1, n) {
		sum += v[i];
		if (sum < i * (i - 1) / 2)
			return cout << -1 << '\n', 0;
	}
	cout << (sum == n * (n - 1) / 2 ? 1 : -1) << '\n';
	return 0;
}