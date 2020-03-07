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
	int n, m, k; cin >> n >> m >> k;
	ll a[40005] = {}, b[40005] = {};
	ll cnt = 0;
	FOR(i, 1, n) {
		int x; cin >> x;
		if (x) a[++cnt]++;
		else cnt = 0;
	}
	cnt = 0;
	RFOR(i, n, 1) {
		if (a[i] > 0) {
			a[i] += a[i + 1];
		}
	}
	cnt = 0;
	FOR(i, 1, m) {
		int x; cin >> x;
		if (x) b[++cnt]++;
		else cnt = 0;
	}
	cnt = 0;
	RFOR(i, m, 1) {
		if (b[i] > 0) {
			b[i] += b[i + 1];
		}
	}
	ll ans = 0;
	FOR(i, 1, n) {
		if (k % i) continue;
		if (k / i > m) continue;
		ans += (a[i] * b[k / i]);
	}
	cout << ans << '\n';
	return 0;
}