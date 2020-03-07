#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define vi vector <int>
#define vvi vector <vi>
#define pii pair<int,int>
using namespace std;
 
int main() {
	FIO;
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		int sum = 0, ans = 0, cnt = 0;
		FOR(i, 1, n) {
			int x; cin >> x;
			if (!x) ans++, x = 1;
			if (x == -1) cnt++;
			sum += x;
		}
		if (!sum) {
			if (cnt == n) ans += 2;
			else ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}