#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
 
bool f(int n, vi v) {
	for (int i = 0; i < (n - 1) / 2; i++)
		if (v[i] < i) return 0;
	for (int i = n - 1; i >= n / 2 + 1; i--)
		if (v[i] < (n - 1 - i)) return 0;
	if ((n % 2) && v[n / 2] < n / 2) return 0;
	else if (n % 2) return 1;
	int idx = (n - 1) / 2;
	if (v[idx] >= idx && v[idx + 1] >= idx + 1) return 1;
	if (v[idx] >= idx + 1 && v[idx + 1] >= idx) return 1;
	return 0;
}
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int test; cin >> test; while (test--) {
		int n; cin >> n;
		vi v(n + 1);
		for (int i = 0; i < n; i++) cin >> v[i];
		cout << (f(n, v) ? "Yes\n" : "No\n");
	}
	return 0;
}