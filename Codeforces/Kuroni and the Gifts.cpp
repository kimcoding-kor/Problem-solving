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
		int n; cin >> n;
		int a[105], b[105];
		FOR(i, 0, n - 1) cin >> a[i];
		FOR(i, 0, n - 1) cin >> b[i];
		sort(a, a + n);
		sort(b, b + n);
		FOR(i, 0, n - 1) cout << a[i] << ' '; cout << '\n';
		FOR(i, 0, n - 1) cout << b[i] << ' '; cout << '\n';
	}
	return 0;
}