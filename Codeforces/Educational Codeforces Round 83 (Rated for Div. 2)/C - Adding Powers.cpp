#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
#define all(x) (x).begin(), (x).end()
#define vi vector <int>
#define vvi vector <vi>
#define ll long long
#define vll vector <ll>
#define vvl vector <vll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ep emplace
#define fs first
#define sd second
using namespace std;

int main() {
	FIO;
	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k;
		vll a(1,1);
		ll x = 1;
		FOR(i, 1, 1000) {
			x *= k;
			if (x > 1e16) break;
			a.eb(x);
		}
		vector <bool> chk(a.size());
		int flag = 1;
		FOR(i, 1, n) {
			cin >> x;
			RFOR(j, a.size() - 1, 0) {
				if (x >= a[j]) {
					x -= a[j];
					if (chk[j]) {
						flag = 0;
						break;
					}
					chk[j] = 1;
				}
			}
			if (x) flag = 0;
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}