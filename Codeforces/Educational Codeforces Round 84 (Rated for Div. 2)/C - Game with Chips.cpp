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
	int n, m, k; cin >> n >> m >> k;
	int a, b;
	FOR(i, 1, k * 2) cin >> a >> b;
	cout << n + m - 3 + n * m << '\n';
	FOR(i, 1, n - 1) cout << 'U';
	FOR(i, 1, m - 1) cout << 'L';
	FOR(i, 1, n) {
		if (i & 1) FOR(j, 1, m - 1) cout << 'R';
		else FOR(j, 1, m - 1) cout << 'L';
		if(i < n) cout << 'D';
	}
	return 0;
}