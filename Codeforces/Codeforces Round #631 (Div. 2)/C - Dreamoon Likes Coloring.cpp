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
	int n, m; cin >> n >> m;
	vi v(n + 1), p(n + 2);
	FOR(i, 1, m) cin >> v[i], p[i] = i;
	p[m + 1] = n + 1;
	FOR(i, 1, m) {
		if (i + v[i] - 1 > n)
			return cout << -1 << '\n', 0;
	}
	RFOR(i, m, 1) {
		int x = p[i + 1];
		if (p[i] + v[i] >= x) {
			FOR(i, 1, m) cout << p[i] << ' ';
			return 0;
		}
		p[i] = p[i + 1] - v[i];
	}
	cout << -1 << '\n';
	return 0;
}