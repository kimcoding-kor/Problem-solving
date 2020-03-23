#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
using namespace std;

int main() {
	FIO;
	int t; cin >> t; while (t--) {
		ll n; cin >> n;
		cout << (n * ((int)1e9 - 1)) << '\n';
	}
 	return 0;
}