#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define vi vector <int>
#define vvi vector <vi>
#define pii pair<int,int>
#define ll long long
#define fs first
#define sd second
#define eb emplace_back
using namespace std;
 
int main() {
	FIO;
	int t; cin >> t; while (t--) {
		ll n, g, b; cin >> n >> g >> b;
		ll ans = 0;
		ll mid = (n + 1) / 2;
		ans += ((mid - 1) / g) * b + mid;
		if (ans < n) ans = n;
		cout << ans << '\n';
	}
	return 0;
}