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
using namespace std;

int main() {
	FIO;
	int n; cin >> n;
	vi v(n);
	FOR(i, 0, n - 1) cin >> v[i];
	FOR(i, 0, n - 1) {
		int x; cin >> x;
		v[i] -= x;
	}
	sort(all(v));
	ll ans = 0;
	FOR(i, 0, n - 1) {
		int idx = upper_bound(all(v), -v[i]) - v.begin();
		ans += n - idx;
		if (v[i] > 0) ans--;
	}
	cout << ans / 2 << '\n';
	return 0;
}