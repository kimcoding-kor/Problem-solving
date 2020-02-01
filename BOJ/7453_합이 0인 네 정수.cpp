#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[4][4000], v[16000000];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++)
			cin >> arr[j][i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			v[i * n + j] = arr[0][i] + arr[1][j];
	sort(v, v + n * n);
	long long ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			auto it = equal_range(v, v + n * n, -arr[2][i] - arr[3][j]);
			ans += (it.second - it.first);
		}
	cout << ans << '\n';
	return 0;
}