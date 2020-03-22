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
#define mod 998244353
#define EPS 1e-9
using namespace std;

int main() {
	FIO;
	int n, k; cin >> n >> k;
	vector <pii> v(n);
	FOR(i, 0, n - 1) cin >> v[i].fs, v[i].sd = i;
	sort(all(v));
	ll ans = 0;
	vector <bool> chk(n);
	FOR(i, 1, k) {
		ans += v[n - i].fs;
		chk[v[n - i].sd] = 1;
	}
	ll ans2 = 1;
	int pre = -1;
	RFOR(i, n - 1, 0) {
		if (chk[i]) {
			if (pre == -1) {
				pre = i;
				continue;
			}
			ans2 *= (pre - i);
			ans2 %= mod;
			pre = i;
		}
	}
	cout << ans << ' ' << ans2 << '\n';
	return 0;
}
