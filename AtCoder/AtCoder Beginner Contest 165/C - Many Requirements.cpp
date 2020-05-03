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
#define tc int t; cin >> t; while(t--)
using namespace std;


int main() {
	FIO;
	int n, m, q; cin >> n >> m >> q;
	vi a, b, c, d;
	a = b = c = d = vi(55);
	vi arr(55);
	int ans = 0;
	FOR(i, 1, q)
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	function <void(int,int)> go = [&](int here, int lv) {
		if (lv == n + 1) {
			int sum = 0;
			FOR(i, 1, q) {
				if (arr[b[i]] - arr[a[i]] != c[i]) continue;
				sum += d[i];
			}
			ans = max(ans, sum);
			return;
		}
		FOR(i, here, m) {
			arr[lv] = i;
			go(i, lv + 1);
		}
	};

	go(1, 1);
	cout << ans << '\n';
	return 0;
}
