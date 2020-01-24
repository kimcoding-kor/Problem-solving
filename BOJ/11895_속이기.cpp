#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, sum = 0, chk = 0, Min = 1e9;
	cin >> n;
	for (int i = 1,x; i <= n; i++) {
		cin >> x;
		sum += x;
		chk ^= x;
		Min = min(Min, x);
	}
	cout << (chk ? 0 : sum - Min) << '\n';
	return 0;
}