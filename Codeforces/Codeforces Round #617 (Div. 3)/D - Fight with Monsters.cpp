#include <cstdio>
#include <iostream>
#include <string>
#include <map>
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
 
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	vi v(n);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		x %= (a + b);
		if (!x) x = (a + b);
		if (x > a) v[i] = ((x - a) - 1) / a + 1;
	}
	sort(all(v));
	int ans = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
		if (sum > k) break;
		ans++;
	}
	cout << ans << '\n';
	return 0;
}