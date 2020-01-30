#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int test; cin >> test; while (test--) {
		int n, arr[1000005]; cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];
		sort(arr, arr + n);
		int m; cin >> m;
		while (m--) {
			int x; cin >> x;
			int idx = lower_bound(arr, arr + n, x) - arr;
			if (idx == n) cout << "0\n";
			else cout << (x == arr[idx]) << '\n';
		}
	}
	return 0;
}