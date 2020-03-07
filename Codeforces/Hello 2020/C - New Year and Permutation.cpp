#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
 
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define all(x) (x).begin(), (x).end()
 
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef long long ll;
 
void factorial(vi& f, int n, int m) {
	f[0] = 1;
	for (int i = 1; i <= n; i++)
		f[i] = (1LL * f[i - 1] * i) % m;
}
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m; cin >> n >> m;
	vi f(n + 1);
	factorial(f, n, m);
	int ans = f[n];
	for (int i = 1; i < n; i++) {
		ans = (1LL * ans + (((1LL * (i + 1) * (i + 1) % m) * f[i]) % m * f[n - i] % m)) % m;
	}
	cout << ans << '\n';
	return 0;
}