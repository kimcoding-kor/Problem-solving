#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
#define all(x) (x).begin(), (x).end()
#define vi vector <int>
#define vvi vector <vi>
#define ll long long
#define vll vector <ll>
#define pii pair<int,int>
using namespace std;
 
int main() {
	FIO;
	int t; cin >> t; while (t--) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		int ans;
		ans = max({ a * y, b * x, (a - 1 - x) * b, (b - 1 - y) * a });
		cout << ans << '\n';
	}
	return 0;
}