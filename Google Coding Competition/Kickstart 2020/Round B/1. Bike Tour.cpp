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
	int test; cin >> test;
	FOR(t, 1, test) {
		int ans = 0;
		int n; cin >> n;
		vi v(n + 1);
		FOR(i, 1, n) cin >> v[i];
		FOR(i, 2, n - 1) {
			if (v[i - 1] < v[i] && v[i] > v[i + 1]) ans++;
		}
		cout << "Case #" << t << ": " << ans << '\n';
	}
	return 0;
}